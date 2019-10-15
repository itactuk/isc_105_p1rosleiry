//
// Created by Ivan Tactuk on 10/13/2019.
//

#include <minunit.h>

#include "punto5Lib.h"

#define MINUNIT_EPSILON 1E-1

//   f(x)       f(x)        f(x)/g(x)/h(x)
// 5 ->(1c) 13  ->(1+2.6c) 29  ->(3.6+5.8c) 61/89/63 -> (125/185/127)(181/269/183)(129/191/131)
//   f(x)       g(x)        f(x)/g(x)/h(x)
// 5 ->(1c) 13  ->(1+2.6c) 41  ->(3.6+8.2c) 85/125/87
//   f(x)       h(x)        f(x)/g(x)/h(x)
// 5 ->(1c) 13  ->(1+2.6c) 31  ->(3.6+6.2c) 65/95/67
//   g(x)       f(x)        f(x)/g(x)/h(x)
// 5 ->(1c) 17  ->(1+3.4c) 37 -> (4.4+7.4c) 77/113/79
//   g(x)       g(x)        f(x)/g(x)/h(x)
// 5 ->(1c) 17  ->(1+3.4c) 53 -> (4.4+10.6c) 109/161/111
//   g(x)       h(x)        f(x)/g(x)/h(x)
// 5 ->(1c) 17  ->(1+3.4c) 39 -> (4.4+7.8c)  81/119/83
//   h(x)       f(x)        f(x)/g(x)/h(x)
// 5 ->(1c) 15  ->(1+3c) 33 -> (4+6.6c)     69/101/71
//   h(x)       g(x)        f(x)/g(x)/h(x)
// 5 ->(1c) 15  ->(1+3c) 47 -> (4+9.4c)      97/143/99
//   h(x)       h(x)        f(x)/g(x)/h(x)
// 5 ->(1c) 15  ->(1+3c) 35 -> (4+7c)       73/107/75

MU_TEST(test_q_mayor_que_p) {
    RESPUESTA res = pasos(5,2, 100.0);
    mu_assert_int_eq(-1, res.pasos);
    mu_assert_int_eq(-1, res.comida_restante);
}

MU_TEST(test_p_igual_q) {
    RESPUESTA res = pasos(5,5, 0.0);
    mu_assert_int_eq(0, res.pasos);
    mu_assert_int_eq(0, res.comida_restante);
}

MU_TEST(test_se_acaba_comida) {
    RESPUESTA res = pasos(5, 61, 4.0);
    mu_assert_int_eq(-1, res.pasos);
    mu_assert_int_eq(-1, res.comida_restante);
}

MU_TEST(test_apunto_de_acabarse_comida) {
    RESPUESTA res = pasos(5, 61, 9.4);
    mu_assert_int_eq(3, res.pasos);
    mu_assert_int_eq(0.0, res.comida_restante);
}

MU_TEST(test_dos_posible_soluciones) {
    RESPUESTA res = pasos(5, 125, 4000.0);
    mu_assert_int_eq(3, res.pasos);
    mu_assert_int_eq(4000.0-11.8, res.comida_restante);
}

MU_TEST(test_hx) {
    //   h(x)       h(x)        f(x)/g(x)/h(x)
    // 5 ->(1c) 15  ->(1+3c) 35 -> (4+7c)       73/107/75
    RESPUESTA res = pasos(5, 35, 4000.0);
    mu_assert_int_eq(2, res.pasos);
    mu_assert_int_eq(4000.0-4.0, res.comida_restante);
}

MU_TEST(test_fx) {
    //   f(x)       f(x)        f(x)/g(x)/h(x)
    // 5 ->(1c) 13  ->(1+2.6c) 29  ->(3.6+5.8c) 61/89/63 -> (125/185/127)(181/269/183)(129/191/131)
    RESPUESTA res = pasos(5, 29, 4000.0);
    mu_assert_int_eq(2, res.pasos);
    mu_assert_int_eq(4000.0-3.6, res.comida_restante);
}

MU_TEST(test_gx) {
    //   g(x)       g(x)        f(x)/g(x)/h(x)
    // 5 ->(1c) 17  ->(1+3.4c) 53 -> (4.4+10.6c) 109/161/111
    RESPUESTA res = pasos(5, 53, 4000.0);
    mu_assert_int_eq(2, res.pasos);
    mu_assert_int_eq(4000.0-4.4, res.comida_restante);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_q_mayor_que_p);
    MU_RUN_TEST(test_p_igual_q);
    MU_RUN_TEST(test_se_acaba_comida);
    MU_RUN_TEST(test_apunto_de_acabarse_comida);
    MU_RUN_TEST(test_dos_posible_soluciones);
    MU_RUN_TEST(test_hx);
    MU_RUN_TEST(test_fx);
    MU_RUN_TEST(test_gx);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}