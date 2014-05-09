#include "include/Analisador.h"

Analisador::Analisador() {

}

vector<string> Analisador::separarParametros(string comando) {
	vector<string> tokens;
	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;
	while ((pos = comando.find(delimiter)) != std::string::npos) {
		token = comando.substr(0, pos);
		tokens.push_back(token);
		comando.erase(0, pos + delimiter.length());
	}
	tokens.push_back(comando);
	return tokens;
}

bool Analisador::validarComando(string comando) {
	vector<string> partesDoComando = separarParametros(comando);
	int numeroDeParametros = partesDoComando.size() - 1;

	for (string & c : getComandosDisponiveis()) {
		if (c == partesDoComando[0]) {
			// Analisa se alloc tem 2 parametros e verifica se o ultimo parametro é um numero
			if (c == "alloc" && numeroDeParametros == 2) {
				if (isNumero(partesDoComando[2])) {
					return true;
				}
				// Analisa se free possui apenas um parâmetro
			} else if (c == "free" && numeroDeParametros == 1) {
				return true;
				// Analisa help, se número de parâmetros for 1 então esse deve ser um comando disponivel.
			} else if (c == "help") {
				if (numeroDeParametros == 1) {
					for (string & c : getComandosDisponiveis()) {
						if (c == partesDoComando[1]) {
							return true;
						}
					}
				} else if (numeroDeParametros == 0) {
					return true;
				}
			}
			return true;
		}
	}
	return false;
}

vector<string> Analisador::getComandosDisponiveis() {
	return comandosDisponiveis;
}

bool Analisador::isNumero(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}
