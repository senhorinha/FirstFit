#ifndef __EVENTO_SAIDA_H__
#define __EVENTO_SAIDA_H__

#include "Evento.h"
#include "Processo.h"

class EventoSaida : public Evento {
	public:
		EventoSaida(Processo *p, long tempo);
		
		/**
		 * Executa o evento de saída no modo de execução de um programa
		 */
		virtual void executar();
};

#endif

