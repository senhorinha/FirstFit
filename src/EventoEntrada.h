#ifndef __EVENTO_ENTRADA_H__
#define __EVENTO_ENTRADA_H__

#include "Evento.h"
#include  "Processo.h"

class EventoEntrada : public Evento {
	public:
		EventoEntrada(Processo *p, long tempo);
		
		/**
		 * Executa o evento de entrada no modo de execução de um programa
		 */
		virtual void executar();
};

#endif

