#ifndef BLOCO_H
#define BLOCO_H

#include "Processo.h"

class Bloco {
	public:
		bool alocado;
		Processo proc;
		int size;
		int espacoOcupado;
		Bloco(Processo _proc, int _size);
		Bloco(int _size);
		Bloco();
		Bloco(Processo _proc);
};

#endif

