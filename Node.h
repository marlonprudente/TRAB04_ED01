#ifndef _NODE_H_
#define _NODE_H_
#include "Coisa.h"
#include <stdlib.h>

class Node{
        private:
                Coisa* patual;
                Node* pmenor;
                Node* pmaior;
        public:
                Node(){patual=NULL;pmenor=NULL;pmaior=NULL;}
                ~Node(){patual=NULL;pmenor=NULL;pmaior=NULL;}
                void set_patual(Coisa* in);
                Coisa* get_patual();

                void set_pmenor(Node* in);
                Node* get_pmenor();

                void set_pmaior(Node* in);
                Node* get_pmaior();
};

#endif
