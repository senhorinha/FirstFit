#ifndef MEMORIA_H
#define MEMORIA_H
#include <vector>
#include <stdio.h>
#include <iostream>
#include <list>
#include "Bloco.h"
#include <string.h>
#include "Processo.h"

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
   int insertProcesso(Processo _processo);
   int removeBloco(Bloco _bloco);
   int removerProcesso(Processo _processo);
   void removeBloco(int index);
   void exibir();
   int rendimento();
   int quantidadeVazia();
   void decrementarProc();
   /*responde se algum processo foi retirado da memoria*/
   bool verificarDesalocamento();

};

#endif
