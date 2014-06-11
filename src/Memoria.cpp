#include <sstream>
#include "include/Logger.h"
#include "include/Memoria.h"

Memoria::Memoria() {
	//memória iniciada com tamanho total
	tamanhoAtual = TAM_MEMORIA;
	Bloco bl(20);
	Bloco bl1(5);
	Bloco bl2(15);
	Bloco bl3(20);
	Bloco bl4(10);
	Bloco bl5(15);
	Bloco bl6(5);
	Bloco bl7(10);

	//inicio a memoria com várias divisões do tamanho da memoria.
	mem.push_back(bl);
	mem.push_back(bl1);
	mem.push_back(bl2);
	/*mem.push_back(bl3);
	 mem.push_back(bl4);
	 mem.push_back(bl5);
	 mem.push_back(bl6);
	 mem.push_back(bl7);*/

}
//Insere um novo processo na 'memoria'
int Memoria::insertProcesso(Processo _processo) {
	int posicaoAlocado = 0;
	//alocar um processo caso possua tamanho suficiente e não tiver alocado por outro processo;
	for (list<Bloco>::iterator it = mem.begin(); it != mem.end();
			++it, posicaoAlocado++) {
		if (!(it->alocado)) {
			if (it->size >= _processo.size) {
				//espaço suficiente, então alocar
				it->espacoOcupado = _processo.size;
				it->proc = _processo;
				tamanhoAtual -= _processo.size;
				it->alocado = true;
				return posicaoAlocado;
			}
		}

	}
	//se um erro de alocação ocorrer, colocar o processo numa fila.
	return ERROALOC;
}
void Memoria::exibir() {
	for (list<Bloco>::iterator it = mem.begin(); it != mem.end(); ++it) {
		stringstream descricao;
		if (it->espacoOcupado == 0) {
			descricao << "      bloco ( tamanho: " << it->size << "\tvazio )";
		} else {
			descricao << "      bloco ( tamanho: " << it->size << "\tocupado: "
					<< it->espacoOcupado << "\tprocesso: " << it->proc.nome
					<< " )";
		}
		Logger::Instance()->escrever(descricao.str());
	}
}
int Memoria::removeBloco(Bloco _bloco) {
	//procurar um bloco alocado por seu PID;
	int pos = 0;
	for (list<Bloco>::iterator it = mem.begin(); it != mem.end(); ++it) {
		if (it->proc.nome.compare(_bloco.proc.nome)) {
			it->proc.nome = "free";
			it->espacoOcupado = 0;
			return pos;
		}
		pos++;
	}
	throw ERROPOS;
}
int Memoria::removerProcesso(Processo _processo) {
	//procurar um bloco alocado por seu PID;
	int pos = 0;
	for (list<Bloco>::iterator it = mem.begin(); it != mem.end(); ++it) {
		if (it->alocado) {
			if (it->proc.nome.compare(_processo.nome) == 0) {
				it->proc.nome = "free";
				it->espacoOcupado = 0;
				it->alocado = false;
				return pos;
			}
		}
		pos++;
	}
	throw ERROPOS;

}
int Memoria::rendimento() {
	return 100 - quantidadeVazia();
}
int Memoria::quantidadeVazia() {
	int valorNaoUsado = 0;
	for (list<Bloco>::iterator it = mem.begin(); it != mem.end(); ++it) {
		valorNaoUsado += it->size - it->espacoOcupado;
	}
	return valorNaoUsado;
}
void Memoria::decrementarProc() {
	for (list<Bloco>::iterator it = mem.begin(); it != mem.end(); ++it) {
		it->proc.tExec--;
	}
}
bool Memoria::desalocarExpirados() {
	bool r = false;
	for (list<Bloco>::iterator it = mem.begin(); it != mem.end(); ++it) {
		stringstream descricao;
		if (it->proc.size != 0 && it->proc.tExec == 0) {
			descricao << "  << removendo " << it->proc.nome;
			removerProcesso(it->proc);
			r = true;
		}
		Logger::Instance()->escrever(descricao.str());
	}
	return r;
}
bool Memoria::empty() {
	for (list<Bloco>::iterator it = mem.begin(); it != mem.end(); ++it) {
		if (it->espacoOcupado != 0) {
			return false;
		}
	}
	return true;
}
