//
// Created by Ivan's PC on 10/13/2019.
//

#ifndef EX1ISC105SEPT2019_PUNTO2LIB_H
#define EX1ISC105SEPT2019_PUNTO2LIB_H

typedef struct complejo{
    double real;
    double imaginaria;
} COMPLEJO;

COMPLEJO suma(COMPLEJO a, COMPLEJO b);
struct complejo resta(COMPLEJO a, COMPLEJO b);
COMPLEJO multiplica(struct complejo a, struct complejo b);
COMPLEJO divide(COMPLEJO a, COMPLEJO b);

#endif //EX1ISC105SEPT2019_PUNTO2LIB_H
