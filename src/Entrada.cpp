#include "include/Entrada.h"

Entrada::Entrada(ControleProcesso *processo, long tempo) {
	this->processo = processo;
	this->tempo = tempo;
}

void Entrada::executar() {
	std::cout << "Entrando" << std::endl;
}

void Entrada::atualizarEstatisticas() {

}
