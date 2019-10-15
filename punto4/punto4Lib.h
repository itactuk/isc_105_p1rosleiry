//
// Created by Ivan's PC on 10/13/2019.
//

#ifndef EX1ISC105SEPT2019_PUNTO4LIB_H
#define EX1ISC105SEPT2019_PUNTO4LIB_H

struct producto{
    int id;
    char nombre[50];
    double precio;
};

struct producto busqueda_binaria(int id, struct producto productos[], int n);

#endif //EX1ISC105SEPT2019_PUNTO4LIB_H
