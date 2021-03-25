
#include <iostream>
#include "Node.h"


Node::Node(Node* Parent, float H)
{
    this->Parent = Parent;
    this->H = H;
}

void Node::Print() 
{
    std::cout << "Its working !!!";
}
