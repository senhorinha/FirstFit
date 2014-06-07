#include "controleProcesso.h"

//Informações do Processo 
ControleProcesso::ControleProcesso(int _pid, int _tChegada, int _tExec, double _size){
	pid = _pid;
	tChegada = _tChegada;
	tExec = _tExec;
	size = _size;	

}
//Usado para o segmento não alocado da memoria
ControleProcesso::ControleProcesso(){
	pid = -1;       
	tChegada = 0;
	tExec = 0;
	size = 0;	

}