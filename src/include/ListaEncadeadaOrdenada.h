#ifndef LISTAENCADEADAORDENADA_H_
#define LISTAENCADEADAORDENADA_H_

#include "Nodo.h"

class ListaEncadeadaOrdenada {

private:
	Nodo *inicial;

public:
	ListaEncadeadaOrdenada() {
	}
	ListaEncadeadaOrdenada(Nodo * inicial) {
		this->inicial = inicial;
	}
	Evento * pop();
	Evento * getByIndice(int indice);
	bool adicionar(Evento * evento);
};

#endif /* LISTAENCADEADAORDENADA_H_ */
