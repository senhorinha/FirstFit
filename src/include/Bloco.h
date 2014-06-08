#ifndef BLOCO_H
#define BLOCO_H
#include "ControleProcesso.h"


class Bloco
{   
public:
   ControleProcesso proc;
   int size;
   int tamanhoRestante;
   Bloco(ControleProcesso _proc, int _size);
   Bloco(int _size);
   Bloco();

};

#endif

