#ifndef TERMINALINCOLOR_H_
#define TERMINALINCOLOR_H_

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/utsname.h>

using namespace std;

class Terminal {

	string loginComNomeDaMaquina;

public:
	Terminal();
	void parteInicialDoTerminal();
	void imprimir(string msg);
	void imprimirHelp(string comando, string descricao, string comoUtilizar,
			string parametros, string exemploDeUso);
};

#endif /* TERMINALINCOLOR_H_ */
