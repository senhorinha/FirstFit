#include "include/GerenciadorMemoria.h"

GerenciadorMemoria::GerenciadorMemoria() {
	instante = 0;
	//configurar a memoria como eu quiser, OU NÃO!
}

GerenciadorMemoria::~GerenciadorMemoria() {
	// TODO Auto-generated destructor stub
}
void GerenciadorMemoria::escalonarProcesso(Processo p){
	queue.push(p);
}
void GerenciadorMemoria::exibirFila(){
	priority_queue<Processo,vector<Processo>,TempoChegada> copy(queue);
	while(!(copy.empty())){
		std::cout << "nome do processo: " << copy.top().nome << std::endl;
		copy.pop();
	}
}
void GerenciadorMemoria::executarProcessos(){
	Processo aux;
	/*a cada ciclo verificar o tempo de cada processo executando na memoria*/
	while(!(queue.empty() && espera.empty())){
		//inicio de um ciclo, irá executar apenas no seu instante
		cout << "inserindo processo " << queue.top().nome << " no instante "<< instante<<endl;
		aux = queue.top();
		if(aux.tChegada == instante){
			if(inserirProcesso(queue.top())==SEM_ESPACO && !(queue.empty())){
				cout << " colocar na fila de espera " << queue.top().nome <<endl;
				espera.push(queue.top());
				queue.pop();
			}else{
				if(!(queue.empty())){
					queue.pop();
				}
			}

		}
		sleep(1);
		if(queue.top().tChegada != instante){
			instante++;
		}
		cout << "dormindo por 1 seg" << endl;
		//decrementa todos os processos da memoria
		decrementarExecucao();
		//fim de um ciclo
		//verificar se algum processo precisa ser retirado
		if(verificarSaida()){
			if(!(espera.empty())){
				if(m.insertProcesso(espera.front()) != -3){
					espera.pop();
					//decrementarExecucao();
				}
			}

		}
		cout << "exib memoria" << endl;
		m.exibir();


	}
}
bool GerenciadorMemoria::verificarSaida(){
	return m.verificarDesalocamento();
}
void GerenciadorMemoria::exibirFilaEspera(){
	std::queue<Processo> copy(espera);
	while(!(copy.empty())){
		std::cout << "nome do processo: " << copy.front().nome << std::endl;
		copy.pop();
	}
}
void GerenciadorMemoria::decrementarExecucao(){
	m.decrementarProc();
}
int GerenciadorMemoria::inserirProcesso(Processo p){
	return m.insertProcesso(p);
}

