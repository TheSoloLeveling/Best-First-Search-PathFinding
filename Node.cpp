#include <iostream>
#include "Node.h"

Node::Node()
{
    this->H = 0;
    this->Parent = NULL;
}

Node::Node(int X, int Y)
{
    this->H = 0;
    this->X = X;
    this->Y = Y;
}

void Node::Print() 
{
    std::cout << "Its working !!!";   // For Debug
}

