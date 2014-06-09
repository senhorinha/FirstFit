#include "include/Relogio.h"

Relogio::Relogio() {
	instante = 0;

}

Relogio::~Relogio() {
	// TODO Auto-generated destructor stub
}
void Relogio::ciclo(){
	instante++;
}

