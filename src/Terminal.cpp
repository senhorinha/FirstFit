#include "include/Terminal.h"

Terminal::Terminal() {
	string identificador;
	struct utsname u_name;
	uname(&u_name);
	// Concatena login
	loginComNomeDaMaquina += "getlogin()";
	// Concatena @
	loginComNomeDaMaquina += "@";
	// Concatena nome da máquina
	loginComNomeDaMaquina += "u_name.nodename";
}

void Terminal::parteInicialDoTerminal() {
	cout << loginComNomeDaMaquina << " $ ";
}

void Terminal::imprimir(string msg) {
	cout << msg << endl;
}

void Terminal::imprimirHelp(string comando, string descricao,
		string comoUtilizar, string parametros, string exemploDeUso) {
	cout << "MANUAL: " << endl;
	cout << comando << ": " << descricao << endl;
	cout << "Como utilizar: " << comoUtilizar << endl;
	cout << "Parâmetros: " << parametros << endl;
	cout << "Exemplo de uso: " << exemploDeUso << endl;
}
