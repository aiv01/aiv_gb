#include <stdio.h>
#include <stdarg.h>

static int tests_succeded = 0;
static int tests_failed = 0;
static int tests_executed = 0;

#define TEST(f)                                                                                 \
    static void test_##f(const char *, int *);                                                  \
    static void run_test_##f()                                                                  \
    {                                                                                           \
        int failed = 0;                                                                         \
        const char *current_test_name = "test_" #f "()";                                        \
        test_##f(current_test_name, &failed);                                                   \
        tests_executed++;                                                                       \
        if (!failed)                                                                            \
        {                                                                                       \
            fprintf(stdout, "[%s %s] %s:test_" #f "() PASSED\n", __DATE__, __TIME__, __FILE__); \
            tests_succeded++;                                                                   \
        }                                                                                       \
    }                                                                                           \
    static void test_##f(const char *current_test_name, int *failed)

#define ASSERT_THAT(rule)                                                                                                           \
    if (!(rule))                                                                                                                    \
    {                                                                                                                               \
        fprintf(stderr, "[%s %s] %s:%s FAILED at line %d: " #rule "\n", __DATE__, __TIME__, __FILE__, current_test_name, __LINE__); \
        *failed = -1;                                                                                                               \
        tests_failed++;                                                                                                             \
        return;                                                                                                                     \
    }

#define RUN_TEST(f)                                                                         \
    fprintf(stdout, "[%s %s] running %s:test_" #f "()...\n", __DATE__, __TIME__, __FILE__); \
    run_test_##f()

#define PRINT_TEST_RESULTS() fprintf(stdout, "***** FINISHED *****\n[%s %s] %s TESTS EXECUTED: %d\n", __DATE__, __TIME__, __FILE__, tests_executed);\
fprintf(stdout, "[%s %s] %s TESTS SUCCEDED: %d\n", __DATE__, __TIME__, __FILE__, tests_succeded);\
fprintf(stdout, "[%s %s] %s TESTS FAILED: %d\n", __DATE__, __TIME__, __FILE__, tests_failed);
