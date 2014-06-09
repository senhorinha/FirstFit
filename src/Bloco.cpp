#include "include/Bloco.h"

Bloco::Bloco(int _size) {
	alocado = false;
	size = _size;
	tamanhoRestante = _size;
}
Bloco::Bloco(Processo _proc){
	proc = _proc;
	size = _proc.size;
	tamanhoRestante = size;

}

