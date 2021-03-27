#include <iostream>
#include "Node.h"

Node::Node()
{
    this->H = 0;
    this->Parent = NULL;
}

Node::Node(Node* Parent, float H)
{
    this->Parent = Parent;
    this->H = H;
}

void Node::Print() 
{
    std::cout << "Its working !!!";   // For Debug
}

