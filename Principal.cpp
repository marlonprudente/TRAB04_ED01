#include "Principal.h"
#include "Teste.h"
#include <iostream>
using namespace std;

Principal::Principal(){
    executar();
}

void Principal::executar(){
	int op;

		cout << endl;
		cout << "1 - Inserir elemento na arvore" << endl;
		cout << "2 - Remoção de objeto da arvore" << endl;
		cout << "3 - Mostrar a arvore" << endl;
		cout << "0 - SAIR" << endl;
		cin >> op;


		while(op!=0)
		{
            switch(op)
		{
            case 1:
			inclusao();
			break;

            case 2:
			remocao();
			break;

            case 3:
			mostrar();
			break;

			default:
			    cout << "Opção Inválida.\n";
                break;
		}
        cout << endl;
		cout << "1 - Inserir elemento na árvore" << endl;
		cout << "2 - Remoção de objeto da árvore" << endl;
		cout << "3 - Mostrar a árvore" << endl;
		cout << "0 - SAIR" << endl;
		cin >> op;
		}
}
void Principal::inclusao()
{
	int n;
	cout << endl << "Digite o Valor: ";
	cin >> n;
	arvore.insert_node(n);
	cout << endl;
}
void Principal::remocao()
{
    int n;
    cout << endl << "Digite o Valor a ser Removido: ";
	cin >> n;
	arvore.remove_node(n);
	cout << endl;

}
void Principal::mostrar()
{
    arvore.print_tree();
}
