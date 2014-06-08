#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/Analisador.h"
#include "include/Terminal.h"
#include "include/Evento.h"
#include "include/Entrada.h"
#include "include/Saida.h"
#include "include/ControleProcesso.h"

using namespace std;

Analisador *analisador = new Analisador();
Terminal *terminal = new Terminal();
ListaEncadeadaOrdenada *listaDeEventos = new ListaEncadeadaOrdenada();

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

	cout << "Código em: https://github.com/thisenrose/FirstFit.git" << endl;
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
		if (comando == "open") {
			descricao = "Abrir o arquivo de entrada";
			comoUtilizar = "open p1";
			parametros = "p1 -> localização do arquivo";
			exemploDeUso = "open arquivo_de_entrada";
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

void lerArquivoDeEntrada(string localDoArquivo) {
	string linha;
	ifstream arquivo(localDoArquivo);
	if (arquivo.is_open()) {
		while (getline(arquivo, linha)) {
			if (!linha.empty()) {
				if (linha.substr(0, 2) != "//") {
					//TODO: Colocar processo na lista
					vector<string> partesDoProceso =
							analisador->separarParametros(linha);
					string nome = partesDoProceso[0];
					int tamanho = atoi(partesDoProceso[1].c_str());
					int tempoDeExecucao = atoi(partesDoProceso[2].c_str());
					int tempoDeChegada = atoi(partesDoProceso[3].c_str());
					ControleProcesso * processo = new ControleProcesso(nome,
							tempoDeChegada, tempoDeExecucao, tamanho);
					Evento * evento = new Entrada(processo, processo->tChegada);
					listaDeEventos->adicionar(evento);
				}
			}
		}
		arquivo.close();
	}
}

// Verifica qual comando foi digitado e inicia operação
void executar(vector<string> partesDoComando) {
	string nomeDoComando = partesDoComando[0];
	if (nomeDoComando == "help") {
		executarHelp(partesDoComando);
	} else if (nomeDoComando == "open") {
		if (analisador->validarArquivo(partesDoComando[1])) {
			lerArquivoDeEntrada(partesDoComando[1]);
		}
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
		if (analisador->validarComando(comando)) {
			executar(analisador->separarParametros(comando));
		} else {
			terminal->imprimir(
					"Erro! Comando não reconhecido. Digite help para ajuda");
		}
	}
}

