//
// Created by Ivan Tactuk on 10/13/2019.
//

#include <minunit.h>

#include "punto2Lib.h"

#define MINUNIT_EPSILON 1E-2

COMPLEJO x = {1.10, 2.00};
COMPLEJO y = {2.00, -1.00};

MU_TEST(test_SumaComplejo) {
    COMPLEJO res = suma(x, y);
    mu_assert_int_eq(3.10, res.real);
    mu_assert_int_eq(1.00, res.imaginaria);
}

MU_TEST(test_RestaComplejo) {
    COMPLEJO res = resta(x, y);
    mu_assert_int_eq(-0.90, res.real);
    mu_assert_int_eq(3.00, res.imaginaria);
}

MU_TEST(test_MultiplicaComplejo) {
    COMPLEJO res = multiplica(x, y);
    mu_assert_int_eq(4.20, res.real);
    mu_assert_int_eq(2.90, res.imaginaria);
}

MU_TEST(test_DivideComplejo) {
    COMPLEJO res = divide(x, y);
    mu_assert_int_eq(0.04, res.real);
    mu_assert_int_eq(1.02, res.imaginaria);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_SumaComplejo);
    MU_RUN_TEST(test_RestaComplejo);
    MU_RUN_TEST(test_MultiplicaComplejo);
    MU_RUN_TEST(test_DivideComplejo);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}