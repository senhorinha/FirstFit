#include "Evento.h"
#include "ControleProcesso.h"
#include <iostream>

#ifndef ENTRADA_H_
#define ENTRADA_H_

class Entrada : public Evento {

public:
	Entrada(ControleProcesso *p, long tempo);
	virtual void executar();
	virtual void atualizarEstatisticas();
};

#endif /* ENTRADA_H_ */
