#include "memoria.h"
#include "bloco.h"
#include "controleProcesso.h"

Memoria::Memoria()
{
	memoria.clear();
	ControleProcesso pr();
	Bloco bl(100);
	memoria.push_back(bl);
}
//Insere um novo bloco no vetor 'memoria'
void Memoria::insertBloco(Bloco _bloco)
{
	memoria.push_back(_bloco);
}

//Remove do vetor 'memoria' o bloco na posição 'index'
void Memoria::removeBloco(int index)
{
	memoria.erase(memoria.begin()+index);
}

//Divide o um bloco ( que estava livre ) alocando um bloco 'novo' e criando um novo bloco livre do tamanho do espaço não usado pelo bloco recém alocado
void Memoria::splitBloco(int index_vitima, Bloco novo )
{
	memoria[index_vitima].size = memoria[index_vitima].size - novo.size;
    ControleProcesso empty;
	Bloco livre(empty,memoria[index_vitima].size - novo.size);
	std::vector<Bloco>::iterator it;
	it = memoria.begin()+index_vitima;
	memoria.insert(it,novo);
}

void Memoria::mergeBloco(int index_bl1, int index_bl2)
{
	ControleProcesso empty;
	Bloco livre(empty, memoria[index_bl1].size + memoria[index_bl2].size);
	removeBloco(index_bl1);
	removeBloco(index_bl2);
	std::vector<Bloco>::iterator it;
	it = memoria.begin()+index_bl1;
	memoria.insert(it,livre);

}