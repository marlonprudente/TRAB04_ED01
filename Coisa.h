#ifndef _COISA_H_
#define _COISA_H_

class Coisa{
      private:
              int atributo;
      public:
              Coisa(){atributo=0;}
              ~Coisa(){}
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
