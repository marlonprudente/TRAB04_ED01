#ifndef _NODE_H_
#define _NODE_H_
#include <stdlib.h>

class Node{
        private:
                int dados;
                Node* pmenor;
                Node* pmaior;
        public:
                Node(){dados=0;pmenor=NULL;pmaior=NULL;}
                ~Node(){dados=0;pmenor=NULL;pmaior=NULL;}
                void set_dados(int in);
                int get_dados();

                void set_pmenor(Node* in);
                Node* get_pmenor();

                void set_pmaior(Node* in);
                Node* get_pmaior();
};

#endif
