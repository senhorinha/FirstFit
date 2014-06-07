#include <iostream>
#include <stdio.h>

#include "controleProcesso.h"
#include "controleProcesso.cpp"
#include "bloco.h"
#include "bloco.cpp"
#include "memoria.h"
#include "memoria.cpp"

#define TAM_MEMORIA 100

using namespace std;

/*
int main()
{
    ControleProcesso proc(1728,0,5,21.5);
    printf("Proc size: %f\n",proc.size);
    Bloco bl(proc,proc.size);
    printf("bloc size: %f | bloc.pid: %d\n",bl.size,bl.proc.pid);

    Memoria mem;
    printf("Memoria size: %f\n",mem.memoria[0].size);

    ControleProcesso proc1(1,0,5,21.5);
    ControleProcesso empty;
    Bloco bloco1(proc1,proc1.size);
    Bloco bloco2(empty,TAM_MEMORIA - proc1.size);
    mem.removeBloco(0);
    mem.insertBloco(bloco1);
    mem.insertBloco(bloco2);

    printf("Memoria size: %f\n",mem.memoria[0].size+mem.memoria[1].size);
    printf("Bloco 1 size: %f | pid = %d\n",mem.memoria[0].size, mem.memoria[0].proc.pid);
    printf("Bloco 2 size: %f | pid = %d\n",mem.memoria[1].size, mem.memoria[1].proc.pid);

    ControleProcesso proc2(2,0,2,35);
    Bloco bloco3(proc2,proc2.size);
    mem.splitBloco(1,bloco3);
    printf("splitBloco(1,bloco3-tam35)\n");
    printf("Bloco 1 size: %f | pid = %d\n",mem.memoria[0].size, mem.memoria[0].proc.pid);
    printf("Bloco 2 size: %f | pid = %d\n",mem.memoria[1].size, mem.memoria[1].proc.pid);
    printf("Bloco 3 size: %f | pid = %d\n",mem.memoria[2].size, mem.memoria[2].proc.pid);

    mem.mergeBloco(0,2);
    printf("mergeBloco(0,2)\n");
    printf("Bloco 1 size: %f | pid = %d\n",mem.memoria[0].size, mem.memoria[0].proc.pid);
    printf("Bloco 2 size: %f | pid = %d\n",mem.memoria[1].size, mem.memoria[1].proc.pid);
    



    return 0;
}
*/
