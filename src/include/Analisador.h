#ifndef ANALISADOR_H_
#define ANALISADOR_H_

#include <iostream>
#include <vector>
using namespace std;

class Analisador {

private:
	vector<string> comandosDisponiveis = { "help", "exit" , "alloc", "free", "meminfo"};
public:
	Analisador();
	bool validarComando(string comando);
	vector<string> getComandosDisponiveis();
	vector<string> separarParametros(string);
	bool isNumero(const std::string& s);
};


#endif /* ANALISADOR_H_ */
