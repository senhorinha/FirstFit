#include "include/Bloco.h"

Bloco::Bloco(ControleProcesso _proc, int _size)
{
	proc = _proc;
	size = _size;
	tamanhoRestante = size;
}
Bloco::Bloco(int _size)
{
	size = _size;
	proc.nome = "free";
	proc.size = _size;
	tamanhoRestante = size;
}
