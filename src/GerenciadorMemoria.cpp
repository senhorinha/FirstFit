#include "include/GerenciadorMemoria.h"
#include <sstream>
#include "include/Logger.h"

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
		stringstream descricao;
		descricao << "nome do processo: " << copy.top().nome;
		Logger::Instance()->escrever(descricao.str());
		copy.pop();
	}
}
void GerenciadorMemoria::executarProcessos(){
	Processo aux;
	bool modificada;
	// a cada ciclo verificar o tempo de cada processo executando na memoria
	while(!(queue.empty() && espera.empty() && m.empty())) {
		modificada = false;
		stringstream aux1;
		aux1 << "Iteração " << instante << ":";
		Logger::Instance()->escrever(aux1.str());
		//verificar se algum processo precisa ser retirado
		if(verificarSaida()) {
			while(!espera.empty()) {
				if(m.insertProcesso(espera.front()) == SEM_ESPACO) {
					break;
				}
				stringstream aux2;
				aux2 << "    " << espera.front().nome << " alocado";
				Logger::Instance()->escrever(aux2.str());
				espera.pop();
			}
			modificada = true;
		}
		
		// inicio de um ciclo, irá executar apenas no seu instante
		while(!queue.empty()) {
			aux = queue.top();
			if(aux.tChegada == instante) {
				stringstream aux3;
				aux3 << "  >> iniciando " << aux.nome;
				Logger::Instance()->escrever(aux3.str());
				stringstream aux4;
				if(inserirProcesso(aux) == SEM_ESPACO) {
					aux4 << "    sem espaço, colocar " << aux.nome << " em espera";
					espera.push(aux);
				} else {
					aux4 << "    " << aux.nome << " alocado";
				}
				Logger::Instance()->escrever(aux4.str());
				queue.pop();
				modificada = true;
				continue;
			}
			break;
		}
		
		instante++;
			
		decrementarExecucao();
		stringstream aux5;
		if(modificada) {
			aux5 << "  estrutura da memória:";
			m.exibir();
		} else {
			aux5 << "  Nada aconteceu desde o último relatório";
		}
		Logger::Instance()->escrever(aux5.str());
	}
	stringstream aux6;
	aux6 << "Finalizada a execução de todos os processos.";
	Logger::Instance()->escrever(aux6.str());
}
bool GerenciadorMemoria::verificarSaida(){
	return m.desalocarExpirados();
}
void GerenciadorMemoria::exibirFilaEspera(){
	std::queue<Processo> copy(espera);
	while(!(copy.empty())){
		stringstream aux;
		aux << "nome do processo: " << copy.front().nome;
		Logger::Instance()->escrever(aux.str());
		copy.pop();
	}
}
void GerenciadorMemoria::decrementarExecucao(){
	m.decrementarProc();
}
int GerenciadorMemoria::inserirProcesso(Processo p){
	return m.insertProcesso(p);
}

