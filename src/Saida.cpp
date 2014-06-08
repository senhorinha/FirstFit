#include "include/Saida.h"

Saida::Saida(ControleProcesso *processo, long tempo) {
	this->processo = processo;
	this->tempo = tempo;
}

void Saida::executar() {
	std::cout << "Saindo" << std::endl;
}

void Saida::atualizarEstatisticas() {

}
