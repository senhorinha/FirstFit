#ifndef EVENTO_H_
#define EVENTO_H_

#include "ControleProcesso.h"

class Evento {

protected:
	ControleProcesso *processo;
	long tempo;
public:
	virtual void executar() = 0;
	virtual void atualizarEstatisticas() = 0;

	ControleProcesso * getProcesso() {
		return processo;
	}

	long getTempo() {
		return tempo;
	}

	int compareTo(Evento *evento) {
		long outroTempo = evento->getTempo();
		if (tempo < outroTempo) {
			return -1;
		} else if (tempo > outroTempo) {
			return 1;
		} else {
			return 0;
		}
	}
};
#endif /* EVENTO_H_ */
