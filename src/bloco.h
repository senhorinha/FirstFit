#ifndef BLOCO_H
#define BLOCO_H
#include "controleProcesso.h"


class Bloco
{   
public:
   ControleProcesso proc;
   double size;
   Bloco(ControleProcesso _proc, double _size);
   Bloco(double _size);
   Bloco(){};
};

#endif

