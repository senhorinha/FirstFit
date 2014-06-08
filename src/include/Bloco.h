#ifndef BLOCO_H
#define BLOCO_H

#include "Processo.h"

class Bloco {   
	public:
		Processo proc;
		int size;
		int tamanhoRestante;
		Bloco(Processo _proc, int _size);
		Bloco(int _size);
		Bloco();
};

#endif

