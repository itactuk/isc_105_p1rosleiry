//
// Created by Ivan Tactuk on 10/13/2019.
//

#include <minunit.h>

#include "punto3Lib.h"

#define MINUNIT_EPSILON 1E-12

MU_TEST(test_Matriz1Elemento) {
    float matriz[1][1] = {
            {2}
    };
    RESULTADOS res = puntos_de_silla(1, 1, matriz);
    mu_assert_int_eq(res.cantidad_resultados_indices, 1);
    mu_assert_int_eq(0, res.indices[0].x);
    mu_assert_int_eq(0, res.indices[0].y);
}

MU_TEST(test_MatrizCuadrada1PS00) {
    float matriz[2][2] = {
            {6, 8},
            {2, 5}
    };// El 6 es unico pto de silla (mayor en columna, menor en fila)
    RESULTADOS res = puntos_de_silla(2, 2, matriz);
    mu_assert_int_eq(res.cantidad_resultados_indices, 1);
    mu_assert_int_eq(0, res.indices[0].x);
    mu_assert_int_eq(0, res.indices[0].y);
}

MU_TEST(test_MatrizCuadrada1PS10) {
    float matriz[2][2] = {
            {8, 6},
            {5, 2}
    };// El 6 es unico pto de silla (mayor en columna, menor en fila)
    RESULTADOS res = puntos_de_silla(2, 2, matriz);
    mu_assert_int_eq(res.cantidad_resultados_indices, 1);
    mu_assert_int_eq(1, res.indices[0].x);
    mu_assert_int_eq(0, res.indices[0].y);
}

MU_TEST(test_MatrizCuadrada1PS11) {
    float matriz[2][2] = {
            {5, 2},
            {8, 6}
    };// El 6 es unico pto de silla (mayor en columna, menor en fila)
    RESULTADOS res = puntos_de_silla(2, 2, matriz);
    mu_assert_int_eq(res.cantidad_resultados_indices, 1);
    mu_assert_int_eq(1, res.indices[0].x);
    mu_assert_int_eq(1, res.indices[0].y);
}

MU_TEST(test_MatrizCuadrada1PS01) {
    float matriz[2][2] = {
            {2, 5},
            {6, 8}
    };// El 6 es unico pto de silla (mayor en columna, menor en fila)
    RESULTADOS res = puntos_de_silla(2, 2, matriz);
    mu_assert_int_eq(res.cantidad_resultados_indices, 1);
    mu_assert_int_eq(0, res.indices[0].x);
    mu_assert_int_eq(1, res.indices[0].y);
}

MU_TEST(test_MatrizNoCuadrada1PS) {
    float matriz[3][2] = {
            {2, 5},
            {6, 8},
            {9, 10}
    };// El 9 es unico pto de silla (mayor en columna, menor en fila)
    RESULTADOS res = puntos_de_silla(3, 2, matriz);
    mu_assert_int_eq(res.cantidad_resultados_indices, 1);
    mu_assert_int_eq(0, res.indices[0].x);
    mu_assert_int_eq(2, res.indices[0].y);
}

MU_TEST(test_MatrizCuadrada2PS) {
    float matriz[3][3] = {
            {2, 10, 11},
            {6,  8, 12},
            {9,  5, 13}
    };// El 9 y el 10 son los ptos de silla (mayor en columna, menor en fila)
    RESULTADOS res = puntos_de_silla(3, 3, matriz);
    mu_assert_int_eq(res.cantidad_resultados_indices, 2);
    mu_assert_int_eq(1, res.indices[0].x + res.indices[1].x); // 0 + 1 (o viceversa)
    mu_assert_int_eq(2, res.indices[0].y + res.indices[1].y); // 2 + 0 (o viceversa)
}


MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_Matriz1Elemento);
    MU_RUN_TEST(test_MatrizCuadrada1PS00);
    MU_RUN_TEST(test_MatrizCuadrada1PS10);
    MU_RUN_TEST(test_MatrizCuadrada1PS11);
    MU_RUN_TEST(test_MatrizCuadrada1PS01);
    MU_RUN_TEST(test_MatrizNoCuadrada1PS);
    MU_RUN_TEST(test_MatrizCuadrada2PS);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}