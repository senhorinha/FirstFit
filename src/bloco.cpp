#include "bloco.h"

Bloco::Bloco(ControleProcesso _proc, double _size)
{
	proc = _proc;
	size = _size;
}
Bloco::Bloco(double _size)
{
	size = _size;
}