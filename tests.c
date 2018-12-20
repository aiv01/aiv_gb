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

//void aiv_gb_tests_run_prefix_cb_00();
//void aiv_gb_tests_run_prefix_cb_10();
//void aiv_gb_tests_run_prefix_cb_20();
//void aiv_gb_tests_run_prefix_cb_30();

void aiv_gb_tests_run_prefix_cb_40();
void aiv_gb_tests_run_prefix_cb_50();
void aiv_gb_tests_run_prefix_cb_60();
void aiv_gb_tests_run_prefix_cb_70();

void aiv_gb_tests_func_roberto();
void aiv_gb_tests_func_virginia();

void aiv_gb_tests_func_massimo();
void aiv_gb_tests_run_func_alessio();
void aiv_gb_tests_func_pierettini();

int main(int argc, char **argv)
{

    aiv_gb_tests_run_opcodes_00();
    aiv_gb_tests_run_opcodes_10();
    aiv_gb_tests_run_opcodes_20();
    aiv_gb_tests_run_opcodes_30();
    aiv_gb_tests_run_opcodes_40();
    aiv_gb_tests_run_opcodes_50();
    aiv_gb_tests_run_opcodes_60();
    aiv_gb_tests_run_opcodes_70();
    aiv_gb_tests_run_opcodes_80();
    aiv_gb_tests_run_opcodes_90();
    aiv_gb_tests_run_opcodes_a0();
    aiv_gb_tests_run_opcodes_b0();
    aiv_gb_tests_run_opcodes_c0();
    aiv_gb_tests_run_opcodes_d0();
    aiv_gb_tests_run_opcodes_e0();
    aiv_gb_tests_run_opcodes_f0();
    //aiv_gb_tests_run_prefix_cb_00();
    //aiv_gb_tests_run_prefix_cb_10();
    //aiv_gb_tests_run_prefix_cb_20();
    //aiv_gb_tests_run_prefix_cb_30();
    aiv_gb_tests_run_prefix_cb_40();
    aiv_gb_tests_run_prefix_cb_50();
    aiv_gb_tests_run_prefix_cb_60();
    aiv_gb_tests_run_prefix_cb_70();


    aiv_gb_tests_func_roberto();
    aiv_gb_tests_func_roberto();   
    aiv_gb_tests_func_massimo();    
    aiv_gb_tests_run_func_alessio();


    PRINT_TEST_RESULTS();
    return 0;
}
