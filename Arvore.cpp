#include "Arvore.h"
#include <queue>
void Arvore::print_tree()
{
    queue<Node*> lista;
    if(raiz!=NULL)
    {
         lista.push(raiz);
         cout << "Raiz: " << raiz->get_dados();
         if(raiz->get_pmenor()!=NULL)
         {
             cout << " FE: " << raiz->get_pmenor()->get_dados();
         }
         else
         {
             cout << " FE: -1";
         }

         if(raiz->get_pmaior()!=NULL)
         {
            cout << " FD: " << raiz->get_pmaior()->get_dados() << "\n";
         }
         else
         {
             cout << " FD: -1\n";
         }
         Node *temp = new Node();
         temp = raiz;
         while(!lista.empty())
         {
             if(temp->get_pmenor()!=NULL)
             {
                 lista.push(temp->get_pmenor());
                 cout << "No: " << temp->get_pmenor()->get_dados();
                 if(temp->get_pmenor()->get_pmenor()!=NULL)
                 {
                     cout << " FE: " << raiz->get_pmenor()->get_pmenor()->get_dados();
                 }
                 else
                 {
                     cout << " FE: -1";
                 }
                 if(temp->get_pmenor()->get_pmaior()!=NULL)
                 {
                     cout << " FD: " << raiz->get_pmenor()->get_pmaior()->get_dados() << "\n";
                 }
                 else
                 {
                    cout << " FD: -1 \n";
                 }

             }
             if(temp->get_pmaior()!=NULL)
             {
                lista.push(temp->get_pmaior());
                cout << "No: " << temp->get_pmaior()->get_dados();
                if(temp->get_pmaior()->get_pmenor()!=NULL)
                {
                     cout << " FE: " << raiz->get_pmaior()->get_pmenor()->get_dados();
                 }
                 else
                 {
                     cout << " FE: -1";
                 }
                if(temp->get_pmaior()->get_pmaior()!=NULL)
                 {
                     cout << " FD: " << raiz->get_pmaior()->get_pmaior()->get_dados() << "\n";
                 }
                 else
                 {
                    cout << " FD: -1 \n";
                 }
             }
        lista.pop();
        temp = lista.front();
         }

    }
    else
    {
        cout << endl << "Arvore Vazia." << endl;
    }
}

void Arvore::remove_node(int in)
{
    if(raiz==NULL)
    {
        cout << "Arvore vazia" << endl;
    }
    else
    {
        Node* aux=raiz;
        Node* antecessor=raiz;
        while(aux!=NULL)
        {
            if(in>aux->get_dados())
            {
                antecessor=aux;
                aux=aux->get_pmaior();
            }
            else if(in<aux->get_dados())
            {
                antecessor=aux;
                aux=aux->get_pmenor();
            }
            else if(in==aux->get_dados())
                break;
        }
        if(aux==raiz)
        {
            if(aux->get_pmaior()==NULL && aux->get_pmenor()==NULL) //SE E UMA FOLHA
            {
                delete aux;
                raiz=NULL;
            }
            else if(aux->get_pmaior()==NULL) // SE SO TEM FOLHAS A ESQUERDA
            {
                raiz=aux->get_pmenor();
                delete aux;
            }
            else if(aux->get_pmenor()==NULL) // SE SO TEM FOLHAS A DIREITA
            {
                raiz=aux->get_pmaior();
                delete aux;
            }
            else //FOLHAS DOS DOIS LADOS - EXCLUSAO POR COPIA
            {
                Node* aux2=aux->get_pmenor();
                antecessor=aux;
                while(aux2->get_pmaior()!=NULL)
                {
                    antecessor=aux2;
                    aux2=aux2->get_pmaior();
                }
                if(antecessor->get_pmaior()==aux2)
                    antecessor->set_pmaior(aux2->get_pmenor());
                if(antecessor->get_pmenor()==aux2)
                    antecessor->set_pmenor(aux2->get_pmenor());
                aux->set_dados(aux2->get_dados());

                delete aux2;
            }
        }
        else if(aux!=NULL)
        {
            if(aux->get_pmaior()==NULL && aux->get_pmenor()==NULL) //SE E UMA FOLHA
            {
                if(antecessor->get_pmaior()==aux)
                    antecessor->set_pmaior(NULL);
                else if(antecessor->get_pmenor()==aux)
                    antecessor->set_pmenor(NULL);
                delete aux;
            }
            else if(aux->get_pmaior()==NULL) // SE SO TEM FOLHAS A ESQUERDA
            {
                if(antecessor->get_pmaior()==aux)
                    antecessor->set_pmaior(aux->get_pmenor());
                else if(antecessor->get_pmenor()==aux)
                    antecessor->set_pmenor(aux->get_pmenor());
                delete aux;
            }
            else if(aux->get_pmenor()==NULL) // SE SO TEM FOLHAS A DIREITA
            {
                if(antecessor->get_pmaior()==aux)
                    antecessor->set_pmaior(aux->get_pmaior());
                else if(antecessor->get_pmenor()==aux)
                    antecessor->set_pmenor(aux->get_pmaior());
                delete aux;
            }
            else //FOLHAS DOS DOIS LADOS - EXCLUSAO POR COPIA
            {
                Node* aux2=aux->get_pmenor();
                antecessor=aux;
                while(aux2->get_pmaior()!=NULL)
                {
                    antecessor=aux2;
                    aux2=aux2->get_pmaior();
                }
                if(antecessor->get_pmaior()==aux2)
                    antecessor->set_pmaior(aux2->get_pmenor());
                if(antecessor->get_pmenor()==aux2)
                    antecessor->set_pmenor(aux2->get_pmenor());
                aux->set_dados(aux2->get_dados());
                delete aux2;
            }
        }
    }
}


void Arvore::insert_node(int in)
{
    Node* nodein;
    nodein = new Node();
    nodein->set_dados(in);
    Node* aux = raiz;
    bool SUCESSO=false;

    if(raiz==NULL)
    {
        raiz=nodein;
    }
    else
    {
      do
      {
        if(nodein->get_dados()>aux->get_dados())
        {
            if(aux->get_pmaior()==NULL)
            {
                SUCESSO=true;
                aux->set_pmaior(nodein);
            }
            else{
                aux=aux->get_pmaior();
                }
        }

        else if(nodein->get_dados()<aux->get_dados())
            {
            if(aux->get_pmenor()==NULL)
                {
                SUCESSO=true;
                aux->set_pmenor(nodein);
                }

            else{
                aux=aux->get_pmenor();
                }
            }

        else
        {
        SUCESSO=true;
        }

      }while(SUCESSO==false);
    }
}

