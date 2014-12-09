#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_
#include "Arvore.h"

class Principal
{
private:
	void executar();
	void inclusao();
	void remocao();
	void mostrar();
	Arvore arvore;
public:
	Principal();
};

#endif
