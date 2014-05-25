#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/Analisador.h"
#include "include/Terminal.h"

using namespace std;

Analisador *analisador = new Analisador();
Terminal *terminal = new Terminal();

void imprimirComandosDisponiveis() {
	vector<string> comandosDisponiveis = analisador->getComandosDisponiveis();
	cout << "Comandos disponíveis: [";
	for (int i = 0; i < comandosDisponiveis.size(); i++) {
		auto& c = comandosDisponiveis[i];
		if (i == comandosDisponiveis.size() - 1) {
			cout << c << "]" << endl;
		} else {
			cout << c << ", ";
		}
	}
}

void imprimirMensagemDeBoasVindas() {

	// http://patorjk.com/software/taag/#p=display&f=Standard&t=FirstFit
	cout << "  _____ _          _   _____ _ _      " << endl;
	cout << " |  ___(_)_ __ ___| |_|  ___(_) |_    " << endl;
	cout << " | |_  | | '__/ __| __| |_  | | __|   " << endl;
	cout << " |  _| | | |  \\__ \\ |_|  _| | | |_    " << endl;
	cout << " |_|   |_|_|  |___/\\__|_|   |_|\\__|   " << endl;
	cout << "                                      " << endl;

	cout << "Código em: https://github.com/thisenrose/BuddySystem" << endl;
	imprimirComandosDisponiveis();
	cout << "Sintaxe: <help> ou <help> + <comando> ou <comando> + <parametros>"
			<< endl;
	cout << endl;
}

// Imprime as mensagens de ajuda para cada comando
bool executarHelp(vector<string> partesDoComando) {
	int numeroDeParametros = partesDoComando.size() - 1;
	if (numeroDeParametros == 0) {
		imprimirComandosDisponiveis();
		cout
				<< "Sintaxe: <help> ou <help> + <comando> ou <comando> + <parametros>"
				<< endl;
		return true;
	} else {
		string comando = partesDoComando[1];
		string descricao;
		string comoUtilizar;
		string parametros;
		string exemploDeUso;
		if (analisador->validarComando(comando)) {
			if (comando == "alloc") {
				descricao = "Aloca memória para um programa";
				comoUtilizar = "alloc p1 p2";
				parametros = "p1 -> nome do programa\np2->espaco em kb";
				exemploDeUso = "alloc google-chrome 512";
			} else if (comando == "free") {
				descricao = "Libera a memória ocupada por um programa";
				comoUtilizar = "free p1";
				parametros = "p1 -> nome do programa";
				exemploDeUso = "free google-chrome";
			} else if (comando == "meminfo") {
				descricao = "Imprime dados da memória como espaço livre, programas na memória etc.";
				comoUtilizar = "meminfo";
				parametros = "Nenhum";
				exemploDeUso = "meminfo";
			} else if (comando == "exit") {
				descricao = "Finaliza a execução.";
				comoUtilizar = "exit";
				parametros = "Nenhum";
				exemploDeUso = "exit";
			}
			terminal->imprimirHelp(comando, descricao, comoUtilizar, parametros,
					exemploDeUso);
			return true;
		}
		return false;
	}
}

// Verifica qual comando foi digitado e inicia operação
void executar(vector<string> partesDoComando) {
	string nomeDoComando = partesDoComando[0];
	if (nomeDoComando == "help") {
		executarHelp (partesDoComando);
	} else if (nomeDoComando == "alloc") {
		//TODO: Alocar memómria
	} else if (nomeDoComando == "free") {
		//TODO: Liberar memória
	} else if (nomeDoComando == "meminfo") {
		//TODO: Imprimir informações da memória, como, espaço livre, blocos livres etc.
	} else if (nomeDoComando == "exit") {
		exit(1);
	}
}

int main() {
	imprimirMensagemDeBoasVindas();
	while (true) {
		char aux[256];
		terminal->parteInicialDoTerminal();
		std::cin.getline(aux, 256);
		string comando = aux;
		vector<string> partesDoComando = analisador->separarParametros(comando);
		if (analisador->validarComando(partesDoComando[0])) {
			executar(partesDoComando);
		} else {
			terminal->imprimir(
					"Erro! Comando não reconhecido. Digite help para ajuda");
		}
	}
}

