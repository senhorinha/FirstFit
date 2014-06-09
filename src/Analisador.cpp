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
			if (c == "open" && numeroDeParametros == 1) {
				return true;
			} else if (c == "start" && numeroDeParametros == 0) {
				return true;
			} else if (c == "exit" && numeroDeParametros == 0) {
				return true;
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
		}
	}
	return false;
}

bool Analisador::validarProcesso(string processo) {
	vector<string> partesDoProcesso = separarParametros(processo);
	int numeroDeParametros = partesDoProcesso.size();
// nome, tamanho, tempo de execucao, tempo de chegada
	if (numeroDeParametros == 4) {
		if (isNumeroValido(partesDoProcesso[1])
				&& isNumeroValido(partesDoProcesso[2])
				&& isNumeroValido(partesDoProcesso[3])) {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

bool Analisador::validarArquivo(string localDoArquivo) {
	string linha;
	int contadorDeLinha = 1;
	bool arquivoCorreto = true;
	ifstream arquivo(localDoArquivo);
	if (arquivo.is_open()) {
		while (getline(arquivo, linha)) {
			if (!linha.empty()) {
				if (linha.substr(0, 2) != "//") {
					if (!validarProcesso(linha)) {
						cout << "Erro! Linha " << contadorDeLinha
								<< " não reconhecível." << endl;
						arquivoCorreto = false;
					}
				}
			}
			contadorDeLinha++;
		}
		arquivo.close();
	} else {
		cout << "Erro! Não foi possível abrir o arquivo" << endl;
		arquivoCorreto = false;
	}
	return arquivoCorreto;
}

vector<string> Analisador::getComandosDisponiveis() {
	return comandosDisponiveis;
}

bool Analisador::isNumeroValido(string numero) {
	if (isNumero(numero) && atoi(numero.c_str()) >= 0) {
		return true;
	} else {
		return false;
	}
}

bool Analisador::isNumero(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}
