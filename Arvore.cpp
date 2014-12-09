#include "Arvore.h"
#include <queue>
void Arvore::print_tree()
{

    if(raiz!=NULL)
    {
        tam = 1;
        if(raiz->get_pmenor()!=NULL)
            contar_arvore(raiz->get_pmenor());

        if(raiz->get_pmaior()!=NULL)
            contar_arvore(raiz->get_pmaior());


    }
    else
    {
        cout << endl << "Arvore Vazia." << endl;
    }
    int i;
    Node vetor[tam];
    for(i=0;i<tam;i++)
    {
        vetor[i] =
    }

}
void Arvore::contar_arvore(Node* subraiz)
{
            tam++;
            if(subraiz->get_pmenor()!=NULL)
            {
            tam++;
            }
            if(subraiz->get_pmaior()!=NULL)
            {
            tam++;
            }

    //PERCORRER OS DEMAIS EM PRÉ-ORDEM
    if(subraiz->get_pmenor()!=NULL)
        contar_arvore(subraiz->get_pmenor());
    if(subraiz->get_pmaior()!=NULL)
        contar_arvore(subraiz->get_pmaior());
}

void Arvore::percorrer_preordem(Node* subraiz)
{
            //cout << "No: " << subraiz->get_patual()->get_atributo();
            if(subraiz->get_pmenor()!=NULL)
            {
            tam++;
            //cout << " FE: " << subraiz->get_pmenor()->get_patual()->get_atributo();
            }
            else
            {
            //cout << " FE: -1";
            }

            if(subraiz->get_pmaior()!=NULL)
            {
            tam++;
            //cout << "FD: " << subraiz->get_pmaior()->get_patual()->get_atributo() << endl;
            }
            else
            {
            //cout << "FD: -1" << endl;
            }



    //PERCORRER OS DEMAIS EM PRÉ-ORDEM
    if(subraiz->get_pmenor()!=NULL)
        percorrer_preordem(subraiz->get_pmenor());
    if(subraiz->get_pmaior()!=NULL)
        percorrer_preordem(subraiz->get_pmaior());
        cout << "Tam " << tam << endl;

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
            if(in>aux->get_patual()->get_atributo())
            {
                antecessor=aux;
                aux=aux->get_pmaior();
            }
            else if(in<aux->get_patual()->get_atributo())
            {
                antecessor=aux;
                aux=aux->get_pmenor();
            }
            else if(in==aux->get_patual()->get_atributo())
                break;
        }
        if(aux==raiz)
        {
            if(aux->get_pmaior()==NULL && aux->get_pmenor()==NULL) //SE EH UMA FOLHA
            {
                delete aux;
                raiz=NULL;
            }
            else if(aux->get_pmaior()==NULL) // SE SOH TEM FOLHAS A ESQUERDA
            {
                raiz=aux->get_pmenor();
                delete aux;
            }
            else if(aux->get_pmenor()==NULL) // SE SOH TEM FOLHAS A DIREITA
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
                aux->set_patual(aux2->get_patual());

                delete aux2;
            }
        }
        else if(aux!=NULL)
        {
            if(aux->get_pmaior()==NULL && aux->get_pmenor()==NULL) //SE EH UMA FOLHA
            {
                if(antecessor->get_pmaior()==aux)
                    antecessor->set_pmaior(NULL);
                else if(antecessor->get_pmenor()==aux)
                    antecessor->set_pmenor(NULL);
                delete aux;
            }
            else if(aux->get_pmaior()==NULL) // SE SOH TEM FOLHAS A ESQUERDA
            {
                if(antecessor->get_pmaior()==aux)
                    antecessor->set_pmaior(aux->get_pmenor());
                else if(antecessor->get_pmenor()==aux)
                    antecessor->set_pmenor(aux->get_pmenor());
                delete aux;
            }
            else if(aux->get_pmenor()==NULL) // SE SOH TEM FOLHAS A DIREITA
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
                aux->set_patual(aux2->get_patual());
                delete aux2;
            }
        }
    }
}


void Arvore::insert_node(int in)
{
    Teste* valor;
    valor = new Teste();
    valor->set_atributo(in);
    Node* nodein;
    nodein=new Node();
    nodein->set_patual(valor);
    Node* aux=raiz;
    bool SUCESSO=false;


    if(raiz==NULL)
    {//--If mestre
        raiz=nodein;
    }//--fim if mestre
    else
    {//-Else mestre
      do
      {
        if(in>aux->get_patual()->get_atributo())
        {//if maior
            if(aux->get_pmaior()==NULL)
            {
                SUCESSO=true;
                aux->set_pmaior(nodein);
            }
            else{
                aux=aux->get_pmaior();
                }//-fim else
        }//Fim if maior

        else if(in<aux->get_patual()->get_atributo()){//menor
            if(aux->get_pmenor()==NULL)
            {
                SUCESSO=true;
                aux->set_pmenor(nodein);
            }
            else{
                aux=aux->get_pmenor();

                }//--Fim else
        }//Fim if menor

        else{//--São iguais!
        SUCESSO=true;
        }
      }while(SUCESSO==false);
    }//--Fim do elsemestre

}

