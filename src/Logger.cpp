#include <stddef.h>
#include "include/Logger.h"

Logger* Logger::instance = NULL;

Logger* Logger::Instance() {
	if (!instance) {
		instance = new Logger;
	}
	return instance;
}


bool Logger::abrirArquivoDeLog(string arquivoDeLog) {
	arquivo.open(arquivoDeLog.c_str());
	if (arquivo.is_open()) {
		return true;
	} else {
		return false;
	}
}

bool Logger::escrever(std::string string) {
	if (arquivo.is_open()) {
		arquivo << string << endl;
		return true;
	} else {
		return false;
	}
}

bool Logger::fecharArquivoDeLog() {
	arquivo.close();
	if (arquivo.is_open()) {
		return false;
	} else {
		return true;
	}
}
