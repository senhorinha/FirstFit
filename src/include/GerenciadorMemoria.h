/*
 * GerenciadorMemoria.h
 *
 *  Created on: 08/06/2014
 *      Author: rodrigomello
 */

#ifndef GERENCIADORMEMORIA_H_
#define GERENCIADORMEMORIA_H_
#include <list>
#include <iostream>
#include <stdio.h>
#include "Processo.h"
#include "Memoria.h"
#include "TempoChegada.h"
#include <iostream>
#include <unistd.h>
#include <queue>
#include <vector>

#define SEM_ESPACO -3
using std::priority_queue;
using std::vector;
using std::cout;
using std::endl;

class GerenciadorMemoria {
	priority_queue<Processo,vector<Processo>,TempoChegada> queue;
	int instante;
	std::queue<Processo> espera;
	Memoria m;
public:
	GerenciadorMemoria();
	virtual ~GerenciadorMemoria();
	//vai colocar na fila em relacao ao seu tempo de chegada;
	void escalonarProcesso(Processo p);
	void exibirFila();
	void exibirFilaEspera();
	void executarProcessos();
	void decrementarExecucao();
	bool verificarSaida();
	int inserirProcesso(Processo p);



};

#endif /* GERENCIADORMEMORIA_H_ */
