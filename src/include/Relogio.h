/*
 * Relogio.h
 *
 *  Created on: 08/06/2014
 *      Author: rodrigomello
 */

#ifndef RELOGIO_H_
#define RELOGIO_H_

class Relogio {
public:
	int instante;
	Relogio();
	virtual ~Relogio();
	void ciclo();
};

#endif /* RELOGIO_H_ */
