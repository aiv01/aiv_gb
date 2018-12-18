
#include "aiv_unit_test.h"
=======
#include <aiv_unit_test.h>
#include <aiv_gb.h>


int tests_succeded = 0;
int tests_failed = 0;
int tests_executed = 0;

void aiv_gb_tests_run_opcodes_50();

void aiv_gb_tests_func_roberto();

int main(int argc, char **argv)
{

 
    aiv_gb_tests_run_opcodes_50();

   
    aiv_gb_tests_run_opcodes_50();
  

    aiv_gb_tests_func_roberto();    


    PRINT_TEST_RESULTS();
    return 0;
}
