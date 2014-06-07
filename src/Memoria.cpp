#include "Memoria.h"

Memoria::Memoria()
{
	/*memoria.clear();
	ControleProcesso pr();
	Bloco bl(100);
	memoria.push_back(bl);*/
	//ControleProcesso pr();
	//memória iniciada com tamanho total
	tamanhoAtual = TAM_MEMORIA;
	Bloco bl(20);
	Bloco bl1(5);
	Bloco bl2(15);
	Bloco bl3(8);
	Bloco bl4(10);
	mem.clear();
	//inicio a memoria com várias divisões do tamanho da memoria.
	mem.push_back(bl);
	mem.push_back(bl1);
	mem.push_back(bl2);
	mem.push_back(bl3);
	mem.push_back(bl4);

}
//Insere um novo bloco na 'memoria'
int Memoria::insertBloco(Bloco _bloco)
{
	int posicaoAlocado = 0;
	//alocar um processo caso possua tamanho suficiente e não tiver alocado por outro processo;
	for(list<Bloco>::iterator it=mem.begin();it!=mem.end();++it){
		if(it->proc.pid == FREE){
			if(it->size >= _bloco.size){
				//espaço suficiente, então alocar
				it->tamanhoRestante = it->size - _bloco.size;
				it->proc = _bloco.proc;
				tamanhoAtual -=_bloco.size;
				return posicaoAlocado;
			}
		}
		posicaoAlocado++;
	}
	//se um erro de alocação ocorrer, colocar o processo numa fila.
	throw ERROALOC;
}
void Memoria::exibir(){
	for(list<Bloco>::iterator it = mem.begin();it != mem.end();++it){
		printf("bloco PID %i | tamanho do bloco %i | espaço restante %i \n",it->proc.pid,it->size,it->tamanhoRestante);
	}
}
int Memoria::removeBloco(Bloco _bloco){
	//procurar um bloco alocado por seu PID;
	int pos = 0;
	for(list<Bloco>::iterator it = mem.begin();it !=mem.end();++it){
		if(it->proc.pid == _bloco.proc.pid){
			it->proc.pid = -1;
			it->tamanhoRestante = it->size;
			return pos;
		}
		pos++;
	}
	throw ERROPOS;
}
//Remove do vetor 'memoria' o bloco na posição 'index'
/*void Memoria::removeBloco(int index)
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

}*/

