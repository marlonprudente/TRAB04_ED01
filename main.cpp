#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main(int argc, char * argv[])
{
    Arvore arvore;
    int op,n;

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
            cout << endl << "Digite o Valor: ";
            cin >> n;
            arvore.insert_node(n);
            cout << endl;
            break;

        case 2:
            cout << endl << "Digite o Valor a ser Removido: ";
            cin >> n;
            arvore.remove_node(n);
            cout << endl;
            break;

        case 3:
            arvore.print_tree();
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

    return 0;
}
