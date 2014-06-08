#ifndef CONTROLEPROCESSO_H
#define CONTROLEPROCESSO_H

#include <iostream>

using namespace std;

class ControleProcesso {

public:
	string nome;
	int tChegada;
	int tExec;
	int size;

	ControleProcesso(string nome, int _tChegada, int _tExec, double _size);
	ControleProcesso(string nome, int _tChegada, int _tExec, int _size);
	ControleProcesso();
};

#endif

