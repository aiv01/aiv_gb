#include <aiv_unit_test.h>
#include <aiv_gb.h>

int tests_succeded = 0;
int tests_failed = 0;
int tests_executed = 0;

void aiv_gb_tests_run_opcodes_00();
void aiv_gb_tests_run_opcodes_10();
void aiv_gb_tests_run_opcodes_20();
void aiv_gb_tests_run_opcodes_30();

void aiv_gb_tests_run_opcodes_40();
void aiv_gb_tests_run_opcodes_50();
void aiv_gb_tests_run_opcodes_60();
void aiv_gb_tests_run_opcodes_70();

void aiv_gb_tests_run_opcodes_80();
void aiv_gb_tests_run_opcodes_90();
void aiv_gb_tests_run_opcodes_a0();
void aiv_gb_tests_run_opcodes_b0();

void aiv_gb_tests_run_opcodes_c0();
void aiv_gb_tests_run_opcodes_d0();
void aiv_gb_tests_run_opcodes_e0();
void aiv_gb_tests_run_opcodes_f0();

void aiv_gb_tests_run_prefix_00();
void aiv_gb_tests_run_prefix_10();
void aiv_gb_tests_run_prefix_20();
void aiv_gb_tests_run_prefix_30();



int main(int argc, char **argv)
{
    //aiv_gb_tests_run_opcodes_00();
    //aiv_gb_tests_run_opcodes_b0();
    //aiv_gb_tests_run_opcodes_60();
    //aiv_gb_tests_run_opcodes_20();
    //aiv_gb_tests_run_opcodes_90();
    //aiv_gb_tests_run_opcodes_70();
    //aiv_gb_tests_run_opcodes_d0();
    //aiv_gb_tests_run_prefix_00();
    //aiv_gb_tests_run_prefix_10();
    //aiv_gb_tests_run_prefix_20();
    aiv_gb_tests_run_prefix_30();

    PRINT_TEST_RESULTS();
    return 0;
}