#include "include/ControleProcesso.h"

//Informações do Processo 
ControleProcesso::ControleProcesso(string nome, int _tChegada, int _tExec, double _size){
	this->nome = nome;
	tChegada = _tChegada;
	tExec = _tExec;
	size = _size;	

}
//Usado para o segmento não alocado da memoria
ControleProcesso::ControleProcesso(){
	nome = "free";
	tChegada = 0;
	tExec = 0;
	size = 0;	

}
ControleProcesso::ControleProcesso(string nome, int _tChegada, int _tExec, int _size){
	this->nome = nome;
	tChegada = _tChegada;
	tExec = _tExec;
	size = _size;
}
