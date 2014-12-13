#ifndef _NODE_H_
#define _NODE_H_
#include "Teste.h"
#include <stdlib.h>

class Node{
        private:
                Teste* patual;
                Node* pmenor;
                Node* pmaior;
        public:
                Node(){patual=NULL;pmenor=NULL;pmaior=NULL;}
                ~Node(){patual=NULL;pmenor=NULL;pmaior=NULL;}
                void set_patual(Teste* in);
                Teste* get_patual();

                void set_pmenor(Node* in);
                Node* get_pmenor();

                void set_pmaior(Node* in);
                Node* get_pmaior();
};

#endif
