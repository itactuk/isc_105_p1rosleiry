//
// Created by Ivan Tactuk on 10/13/2019.
//

#include <minunit.h>

#include "punto1Lib.h"

#define MINUNIT_EPSILON 1E-12

MU_TEST(test_CadenaLLenaPar) {
    char micadena[] = {'a', 'b', 'c', '\0'};
    invierte(micadena);
    mu_assert_int_eq('c', micadena[0]);
    mu_assert_int_eq('b', micadena[1]);
    mu_assert_int_eq('a', micadena[2]);
    mu_assert_int_eq('\0', micadena[3]);
}

MU_TEST(test_CadenaLLenaImpar) {
    char micadena[] = {'a', 'b', 'c', 'd', '\0'};
    invierte(micadena);
    mu_assert_int_eq('d', micadena[0]);
    mu_assert_int_eq('c', micadena[1]);
    mu_assert_int_eq('b', micadena[2]);
    mu_assert_int_eq('a', micadena[3]);
    mu_assert_int_eq('\0', micadena[4]);
}

MU_TEST(test_CadenaVacia) {
    char micadena[] = {'\0'};
    invierte(micadena);
    mu_assert_int_eq('\0', micadena[0]);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_CadenaLLenaPar);
    MU_RUN_TEST(test_CadenaLLenaImpar);
    MU_RUN_TEST(test_CadenaVacia);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}