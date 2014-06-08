#ifndef NODO_H_
#define NODO_H_

#include "Evento.h"

class Nodo {

private:
	Evento *evento;
	Nodo *proximoNodo;
public:
	Nodo(Evento *evento, Nodo *proximoNodo) {
		this->evento = evento;
		this->proximoNodo = proximoNodo;
	}
	Nodo(Evento *evento) {
		this->evento = evento;
	}
	Evento * getEvento();
	void setEvento(Evento * evento);
	Nodo * getProximoNodo();
	void setProximoEvento(Nodo * proximoNodo);
};

#endif /* NODO_H_ */
