#ifndef _TESTE_H_
#define _TESTE_H_

class Teste{
      private:
              int atributo;
      public:
              Teste(){atributo=0;}
              ~Teste(){}
              void set_atributo(int a)
              {
                  atributo=a;
              }
              int get_atributo()
              {
                  return atributo;
              }
};

#endif
