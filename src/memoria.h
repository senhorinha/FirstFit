#ifndef MEMORIA_H
#define MEMORIA_H
#include <vector>
#include "bloco.h"
#include "controleProcesso.h"

using namespace std;
class Memoria
{   
	
public:
   std::vector<Bloco> memoria;
   Memoria();
   void insertBloco(Bloco _bloco);
   void removeBloco(int index);
   void splitBloco(int index_vitima, Bloco novo );
   void mergeBloco(int index_bl1, int index_bl2);
};

#endif
