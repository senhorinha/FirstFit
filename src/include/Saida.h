#ifndef SAIDA_H_
#define SAIDA_H_

#include "Evento.h"
#include "ControleProcesso.h"
#include <iostream>

class Saida : public Evento {

public:
	Saida(ControleProcesso *p, long tempo);
	virtual void executar();
	virtual void atualizarEstatisticas();
};
#endif /* SAIDA_H_ */
