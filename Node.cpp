#include "Node.h"

void Node::set_dados(int in)
{
    dados=in;
}
int Node::get_dados()
{
    return dados;
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
