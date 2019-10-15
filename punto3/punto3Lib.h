//
// Created by Ivan's PC on 10/13/2019.
//

#ifndef EX1ISC105SEPT2019_PUNTO3LIB_H
#define EX1ISC105SEPT2019_PUNTO3LIB_H

#define CANTIDAD_MAXIMA_RESULTADOS 100

typedef struct indices{
    int x;
    int y;
} INDICES;

typedef struct resultados{
    INDICES indices[CANTIDAD_MAXIMA_RESULTADOS];
    int cantidad_resultados_indices;
} RESULTADOS;

RESULTADOS puntos_de_silla(int m, int n, float matriz[m][n]);

#endif //EX1ISC105SEPT2019_PUNTO3LIB_H
