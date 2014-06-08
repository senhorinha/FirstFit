#include "include/ListaEventos.h"

ListaEventos::ListaEventos() {
	primeiro = nullptr;
}

ListaEventos::~ListaEventos() {
}
		
Evento *ListaEventos::proximo() {
	ListaEventos::Item *rem = primeiro;
	
	if(rem == nullptr) {
		return nullptr;
	}
	
	primeiro = rem->proximo;

	Evento *ret = rem->valor;

	delete [] rem;

	return ret;
}

void ListaEventos::adicionar(Evento *e) {
	ListaEventos::Item *adic = new ListaEventos::Item(e);
	
	if(primeiro == nullptr) {
		adic->proximo = nullptr;
		primeiro = adic;
		return;
	}
	
	ListaEventos::Item *atual = primeiro;
	
	while(atual->proximo != nullptr && atual->proximo->valor->comparar(e) < 0) {
		atual = atual->proximo;
	}
	
	adic->proximo = atual->proximo;
	atual->proximo = adic;
}

ListaEventos::Item::Item(Evento *e) {
	valor = e;
}

