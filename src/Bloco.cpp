#include "include/Bloco.h"

Bloco::Bloco(int _size) {
	alocado = false;
	size = _size;
	espacoOcupado = 0;
}
Bloco::Bloco(Processo _proc){
	proc = _proc;
	size = _proc.size;
	espacoOcupado = 0;

}

