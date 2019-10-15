//
// Created by Ivan Tactuk on 10/13/2019.
//

#include <minunit.h>

#include "punto4Lib.h"

#define MINUNIT_EPSILON 1E-1

struct producto prods[]={
    {2, "Agua", 12.0},
    {4, "Arroz", 15.0},
    {6, "Mangu", 10.0},
    {8, "Habichuela", 12.0},
    {9, "Vaso", 2.0},
};



MU_TEST(test_ArregloVacio) {
    struct producto res = busqueda_binaria(2, prods, 0);
    mu_assert_int_eq(-1, res.id);
}

MU_TEST(test_Arreglo1ElementoEncontrado) {
    struct producto res = busqueda_binaria(2, prods, 1);
    mu_assert_int_eq(2, res.id);
    mu_assert_double_eq(12.0, res.precio);
}

MU_TEST(test_Arreglo1ElementoNoEncontradoIzq) {
    struct producto res = busqueda_binaria(1, prods, 1);
    mu_assert_int_eq(-1, res.id);
}

MU_TEST(test_Arreglo1ElementoNoEncontradoDcha) {
    struct producto res = busqueda_binaria(3, prods, 1);
    mu_assert_int_eq(-1, res.id);
}

MU_TEST(test_Arreglo1ElementoEncontradoMedioIzqPar) {
    struct producto res = busqueda_binaria(4, prods, 4);
    mu_assert_int_eq(4, res.id);
    mu_assert_double_eq(15.0, res.precio);
}

MU_TEST(test_Arreglo1ElementoEncontradoMedioDchaPar) {
    struct producto res = busqueda_binaria(6, prods, 4);
    mu_assert_int_eq(6, res.id);
    mu_assert_double_eq(10.0, res.precio);
}

MU_TEST(test_Arreglo1ElementoNoEncontradoMedioPar) {
    struct producto res = busqueda_binaria(5, prods, 4);
    mu_assert_int_eq(-1, res.id);
}

MU_TEST(test_Arreglo1ElementoEncontradoMedioImpar) {
    struct producto res = busqueda_binaria(6, prods, 5);
    mu_assert_int_eq(6, res.id);
    mu_assert_double_eq(10.0, res.precio);
}

MU_TEST(test_Arreglo1ElementoNoEncontradoMedioIzqImpar) {
    struct producto res = busqueda_binaria(5, prods, 5);
    mu_assert_int_eq(-1, res.id);
}

MU_TEST(test_Arreglo1ElementoNoEncontradoMedioDchaImpar) {
    struct producto res = busqueda_binaria(7, prods, 5);
    mu_assert_int_eq(-1, res.id);
}


MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_ArregloVacio);
    MU_RUN_TEST(test_Arreglo1ElementoEncontrado);
    MU_RUN_TEST(test_Arreglo1ElementoNoEncontradoIzq);
    MU_RUN_TEST(test_Arreglo1ElementoNoEncontradoDcha);
    MU_RUN_TEST(test_Arreglo1ElementoEncontradoMedioIzqPar);
    MU_RUN_TEST(test_Arreglo1ElementoEncontradoMedioDchaPar);
    MU_RUN_TEST(test_Arreglo1ElementoNoEncontradoMedioPar);
    MU_RUN_TEST(test_Arreglo1ElementoEncontradoMedioImpar);
    MU_RUN_TEST(test_Arreglo1ElementoNoEncontradoMedioIzqImpar);
    MU_RUN_TEST(test_Arreglo1ElementoNoEncontradoMedioDchaImpar);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}