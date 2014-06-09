/*
 * TempoChegada.h
 *
 *  Created on: 08/06/2014
 *      Author: rodrigomello
 */

#ifndef TEMPOCHEGADA_H_
#define TEMPOCHEGADA_H_
#include "Processo.h"
class TempoChegada {
public:
	bool operator()(Processo p1, Processo p2){
		return p1.tChegada>p2.tChegada;
	}
};

#endif /* TEMPOCHEGADA_H_ */
