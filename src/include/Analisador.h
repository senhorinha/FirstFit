#ifndef ANALISADOR_H_
#define ANALISADOR_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

class Analisador {

private:
	vector<string> comandosDisponiveis = { "help", "open", "exit" };
	bool validarProcesso(string processo);
	bool isNumeroValido(string numero);
	bool isNumero(const std::string& s);
public:
	Analisador();
	bool validarComando(string comando);
	bool validarArquivo(string nomeDoArquivo);
	vector<string> getComandosDisponiveis();
	vector<string> separarParametros(string);
};

#endif /* ANALISADOR_H_ */
