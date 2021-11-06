/*
 * carrito.h
 *
 *  Created on: 21 Apr 2021
 *      Author: mentxaka
 */

#ifndef CARRITO_H_
#define CARRITO_H_
#include "producto.h"

typedef struct{
	int nProd;
	Producto producto;
}Compra;

typedef struct{
	int nComp;
	Compra* compra;
	float total;
}Carrito;

void modificarCompra(Compra *c, int cant);
void imprimirCompra(Compra c);
void crearCarrito(Carrito *c, Producto** prods, int* cants, int tamanyo);
void imprimirTicket(Carrito c);
void devolverCarrito(Carrito *c);
void modificarCarrito(Carrito *c, int ref, int cant);
void leerProductos(Producto** productos, char* fichero);

#endif /* CARRITO_H_ */
