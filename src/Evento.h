#ifndef __EVENTO_H__
#define __EVENTO_H__

#include  "Processo.h"

class Evento {
	public:
		const long tempo; // Momento em que o evento deve acontecer
		const Processo *processo; // Processo pertencente ao evento
		
		
		
		Evento(Processo *p, long tempo);
		
		/**
		 * Executa o evento
		 * Implementar o método dessa maneira faz com que as classes derivadas
		 * sejam obrigadas a implementá-lo.
		 */
		virtual void executar() = 0;
		
		/**
		 * Compara dois eventos e retorna um inteiro para indicar a relação de
		 * precedência entre eles.
		 *
		 * Valores menores que zero indicam que o evento que chamou o método
		 * precede o passado como parâmetro, valores maiores que zero indicam
		 * o contrário e zero indica que os eventos devem ocorrer ao mesmo tempo
		 * ou não importa a ordem deles;
		 */
		int comparar(Evento *e);
};

#endif
