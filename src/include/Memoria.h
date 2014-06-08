#ifndef MEMORIA_H
#define MEMORIA_H
#include <vector>
#include <stdio.h>
#include <iostream>
#include <list>
#include "Bloco.h"
#include <string.h>
#include "ControleProcesso.h"

#define ERROALOC -3
#define TAM_MEMORIA 100
#define ERROPOS -2
#define FREE "free"
using namespace std;
class Memoria
{   
	
public:
   //std::vector<Bloco> memoria;
   std::list<Bloco> mem;
   int tamanhoAtual;

   Memoria();
   int insertBloco(Bloco _bloco);
   int removeBloco(Bloco _bloco);
   void removeBloco(int index);
   void splitBloco(int index_vitima, Bloco novo );
   void mergeBloco(int index_bl1, int index_bl2);
   void exibir();
};

#endif
