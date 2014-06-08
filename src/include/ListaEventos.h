#ifndef __LISTA_EVENTOS_H__
#define __LISTA_EVENTOS_H__

#include "Evento.h"

class ListaEventos {
	private:
		/**
		 * Representa um item da lista encadeada
		 */
		class Item {
			public:
				Evento *valor;
				Item *proximo;
				
				Item(Evento *e);
		};
		
		Item *primeiro;
	
	public:
		ListaEventos();
		virtual ~ListaEventos();
		
		/**
		 * Retorna o próximo evento na fila ou nullptr caso a fila esteja vazia
		 */
		Evento *proximo();
		
		/**
		 * Adiciona um evento na fila que será colocado em uma posição que
		 * mantenha a fila ordenada.
		 * 
		 * Perceba que essa fila não serve para aplicações em que itens podem
		 * ser adicinados a qualquer momento pois isso pode levar facilmente a
		 * condições de inanição (starvation)
		 */
		void adicionar(Evento *e);
};

#endif

