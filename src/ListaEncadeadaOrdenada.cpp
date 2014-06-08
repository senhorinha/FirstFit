#include "include/ListaEncadeadaOrdenada.h"

Evento * ListaEncadeadaOrdenada::pop() {
	Evento *evento;
	if (inicial != nullptr) {
		evento = inicial->getEvento();
		Nodo * aux = inicial->getProximoNodo();
		inicial = aux;
	}
	return evento;
}

Evento * ListaEncadeadaOrdenada::getByIndice(int indice) {
	int contador = 0;
	Nodo * nodo = inicial;
	Evento * evento;
	while (contador <= indice) {
		if (nodo != nullptr) {
			if (contador == indice) {
				return nodo->getEvento();
			} else {
				contador++;
				nodo = nodo->getProximoNodo();
			}
		} else {
			return nullptr;
		}
	}
	return evento;
}

bool ListaEncadeadaOrdenada::adicionar(Evento * evento) {
	Nodo * nodo = inicial;
	Nodo * nodoAnterior = inicial;
	bool adicionado = false;
	if (inicial == nullptr) {
		inicial = new Nodo(evento);
		adicionado = true;
	} else {
		Evento *aux = inicial->getEvento();
		if (aux != nullptr) {
			if (evento->compareTo(aux) == -1) {
				Nodo * novo = new Nodo(evento, inicial);
				inicial = novo;
				adicionado = true;
			}
		}
	}
	while (!adicionado) {
		if (nodo != nullptr) {
			Evento * e = nodo->getEvento();
			if (e != nullptr) {
				switch (evento->compareTo(e)) {
				case -1:
					nodoAnterior->setProximoEvento(new Nodo(evento, nodo));
					adicionado = true;
					break;
				default:
					nodoAnterior = nodo;
					nodo = nodo->getProximoNodo();
					break;
				}
			} else {
				nodo->setEvento(evento);
			}
		} else {
			nodoAnterior->setProximoEvento(new Nodo(evento));
			adicionado = true;
		}
	}
	return true;
}
