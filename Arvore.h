#ifndef _ARVORE_H_
#define _ARVORE_H_
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Node.h"

class Arvore{
      private:
                Node* raiz;
      public:
              Arvore(){raiz=NULL;}
              ~Arvore(){}

                void insert_node(int in);
                void remove_node(int in);
                void print_tree();
};

#endif
