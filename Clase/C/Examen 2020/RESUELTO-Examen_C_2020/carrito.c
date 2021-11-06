#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "carrito.h"
#include "producto.h"

void modificarCompra(Compra *c, int cant){
	c->nProd = cant;
}
void imprimirCompra(Compra c){
	printf("Producto [%i-%s-%.2f€] %i \n",c.producto.ref,c.producto.nombre,c.producto.precio,c.nProd);
}
void crearCarrito(Carrito *c, Producto** prods, int* cants, int tamanyo){
	c->nComp = tamanyo;
	c->compra = malloc(sizeof(Compra)*tamanyo);
	for(int i = 0; i<tamanyo;i++){
		Compra temp;
		temp.nProd = cants[i];
		temp.producto = *prods[i];
		c->compra[i] = temp;
		c->total += temp.nProd*temp.producto.precio;
	}
}
void imprimirTicket(Carrito c){
	for(int i = 0; i<c.nComp; i++){
		imprimirCompra(c.compra[i]);
	}
	printf("Total: %.2f€\n",c.total);
}
void devolverCarrito(Carrito *c){
	free(c->compra);
}
void modificarCarrito(Carrito *c, int ref, int cant){
	for(int i = 0; i<c->nComp;i++){
		if (c->compra[i].producto.ref == ref) c->compra[i].nProd+=cant;
	}
}
void leerProductos(Producto** productos, char* fichero){
	FILE* f = fopen(fichero, "r"); //LECTURA
	char c;
	int cont = 0;
	char ref;
	char nombre[15];
	int contN = 0;
	char cantidad[5];
	int contC = 0;
	int nProd = 0;
	while ((c = fgetc(f)) != EOF) {
		if (cont == 0) ref = c;
		if (cont>0&&cont<15){
			nombre[contN] = c;
			contN++;
			if(cont == 14) contN = 0;
		}
		if (cont>14&&cont<20){
			cantidad[contC] = c;
			contC++;
			if(cont == 19) contC = 0;
		}
		cont++;
		if (c == '\n') {
			cont = 0;
			Producto *p = malloc(sizeof(Producto));
			productos[nProd] = p;
			p->ref = ref-49;
		    for(int i = 0; i<14;i++) p->nombre[i] = nombre[i];
		    sscanf(cantidad, "%f",&p->precio);
		    nProd++;
		}
		printf("%c",c);
	}
	fclose(f);
}
