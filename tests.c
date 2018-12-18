#include "aiv_unit_test.h"

int tests_succeded = 0;
int tests_failed = 0;
int tests_executed = 0;

void aiv_gb_tests_run_opcodes_50();

int main(int argc, char **argv)
{
    aiv_gb_tests_run_opcodes_50();

    PRINT_TEST_RESULTS();
    return 0;
}
