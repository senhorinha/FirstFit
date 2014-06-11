#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Logger {

public:
	ofstream arquivo;
	static Logger* Instance();
	bool abrirArquivoDeLog(std::string arquivoDeLog);
	bool escrever(std::string string);
	bool fecharArquivoDeLog();

private:
	static Logger* instance;
	Logger() {
	}
	;
	Logger(Logger const&) {
	}
	;
	Logger& operator=(Logger const&) {
	}
	;

};
