#ifndef CONTROLEPROCESSO_H
#define CONTROLEPROCESSO_H

class ControleProcesso
{
   
public:
int pid;
   int tChegada;
   int tExec;
   double size;
   ControleProcesso(int _pid, int _tChegada, int _tExec, double _size);
   ControleProcesso();
};

#endif

