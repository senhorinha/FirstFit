#include "include/Evento.h"

Evento::Evento(Processo *p, long t) : processo(p), tempo(t) {
}

int Evento::comparar(Evento *e) {
	return this->tempo - e->tempo; // desconsiderar overflows
}

