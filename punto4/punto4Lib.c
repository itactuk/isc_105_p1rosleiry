//
// Created by Ivan's PC on 10/13/2019.
//

#include "punto4Lib.h"

struct producto _busqueda_binaria_recursiva(int id, struct producto prods[], int ii, int is);

/**
 * Si no encuentra el producto debe de retornar -1 en el id del producto
 * @param id
 * @param productos
 * @param n es la cantidad de elementos en el arreglo produtos
 * @return
 */
struct producto busqueda_binaria(int id, struct producto productos[], int n){
    return _busqueda_binaria_recursiva(id, productos, 0, n-1);
}

/**
 * Debe ser implementado con recursividad.
 * Si no encuentra el producto debe de retornar -1 en el id del producto
 * @param id
 * @param prods
 * @param ii es el indice inferior
 * @param is es el indice superior
 * @return
 */
struct producto _busqueda_binaria_recursiva(int id, struct producto prods[], int ii, int is){

}