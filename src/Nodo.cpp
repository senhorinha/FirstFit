#include "include/Nodo.h"

Evento * Nodo::getEvento() {
	return this->evento;
}

void Nodo::setEvento(Evento * evento) {
	this->evento = evento;
}

Nodo * Nodo::getProximoNodo() {
	return this->proximoNodo;
}

void Nodo::setProximoEvento(Nodo * proximoNodo) {
	this->proximoNodo = proximoNodo;
}

