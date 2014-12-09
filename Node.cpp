#include "Node.h"

void Node::set_patual(Coisa* in)
{
    patual=in;
}
Coisa* Node::get_patual()
{
    return patual;
}

void Node::set_pmenor(Node* in)
{
    pmenor=in;
}
Node* Node::get_pmenor()
{
    return pmenor;
}

void Node::set_pmaior(Node* in)
{
    pmaior=in;
}
Node* Node::get_pmaior()
{
    return pmaior;
}
