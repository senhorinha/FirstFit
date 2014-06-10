#include "include/GerenciadorMemoria.h"

GerenciadorMemoria::GerenciadorMemoria() {
	instante = 0;
	//configurar a memoria como eu quiser, OU NÃO!
}

GerenciadorMemoria::~GerenciadorMemoria() {
	
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
	bool modificada;
	// a cada ciclo verificar o tempo de cada processo executando na memoria
	while(!(queue.empty() && espera.empty() && m.empty())) {
		modificada = false;
		
		cout << "Iteração " << instante << ":" << endl;
		
		//verificar se algum processo precisa ser retirado
		if(verificarSaida()) {
			while(!espera.empty()) {
				if(m.insertProcesso(espera.front()) == SEM_ESPACO) {
					break;
				}
				cout << "    " << espera.front().nome << " alocado" << endl;
				espera.pop();
			}
			modificada = true;
		}
		
		// inicio de um ciclo, irá executar apenas no seu instante
		while(!queue.empty()) {
			aux = queue.top();
			if(aux.tChegada == instante) {
				cout << "  >> iniciando " << aux.nome << endl;
				if(inserirProcesso(aux) == SEM_ESPACO) {
					cout << "    sem espaço, colocar " << aux.nome << " em espera" << endl;
					espera.push(aux);
				} else {
					cout << "    " << aux.nome << " alocado" << endl;
				}
				queue.pop();
				modificada = true;
				continue;
			}
			break;
		}
		
		instante++;
			
		// decrementa o tempo restante de todos os processos da memoria
		decrementarExecucao();
		
		//cout << "dormindo por 1 seg" << endl;
		//sleep(1);
		
		//fim de um ciclo
		if(modificada) {
			cout << "  estrutura da memória:" << endl;
			m.exibir();
		} else {
			cout << "  Nada aconteceu desde o último relatório" << endl;
		}
	}
	cout << "Finalizada a execução de todos os processos." << endl;
}
bool GerenciadorMemoria::verificarSaida(){
	return m.desalocarExpirados();
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

