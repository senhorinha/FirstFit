#include "include/Processo.h"

//Informações do Processo
Processo::Processo(string nome, int _tChegada, int _tExec, double _size){
	this->nome = nome;
	tChegada = _tChegada;
	tExec = _tExec;
	size = _size;

}
//Usado para o segmento não alocado da memoria
Processo::Processo(){
	nome = "free";
	tChegada = 0;
	tExec = 0;
	size = 0;

}
Processo::Processo(string nome, int _tChegada, int _tExec, int _size){
	this->nome = nome;
	tChegada = _tChegada;
	tExec = _tExec;
	size = _size;
}
