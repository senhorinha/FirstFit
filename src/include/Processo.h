#ifndef PROCESSO_H
#define PROCESSO_H

#include <iostream>

using namespace std;

class Processo {
	public:
		string nome;
		int tChegada;
		int tExec;
		int size;

		Processo(string nome, int _tChegada, int _tExec, double _size);
		Processo(string nome, int _tChegada, int _tExec, int _size);
		Processo();

};

#endif

