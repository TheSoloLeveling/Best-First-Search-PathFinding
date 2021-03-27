#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "Node.h"


using namespace std;

struct BST
{
    BST* LeftChild;
    Node* Data;
    BST* RightChild;
};

struct BST* Insert(struct BST* Bst, Node* n)

{
    if (Bst == NULL) 
    {
        struct BST* temp = (struct BST*)malloc(sizeof(struct BST));
        temp->Data = new Node(NULL, n->GetH());
        temp->LeftChild = temp->RightChild = NULL;
        return temp;
    }
    if (n->GetH() < Bst->Data->GetH())
        Bst->LeftChild = Insert(Bst->LeftChild, n);
    else
        Bst->RightChild = Insert(Bst->RightChild, n);
    return Bst;    
}

struct BST* Search(struct BST* Bst, Node* n)
{
    if(Bst == NULL || Bst->Data->GetH() == n->GetH())
        return Bst;

    if(Bst->Data->GetH() < n->GetH())
        return Search(Bst->RightChild, n);

    return Search(Bst->LeftChild, n);
}

void Inorder(struct BST* p)
{
    if(p)
    {
        Inorder(p->LeftChild);
        std::cout << p->Data->GetH() << " ";
        Inorder(p->RightChild);
    }
}

int Rand(int a, int b)
{
    int nRand = a + (int) ((float) rand() * (b-a+1) / (RAND_MAX-1));
    return nRand;
}

vector<vector<Node*> > ConstructIntGrid()
{
    vector<vector<Node*> > grid;

    int size;

    cout << "Enter size : ";
    cin >> size;
  

    for(int i = 0; i < size; i++)
    {
        vector<Node*> v;
        for(int j = 0; j < size; j++)
        {
            Node* data = new Node(NULL, Rand(1, 10));
            v.push_back(data);
        }
        grid.push_back(v);
    }
    
    return grid;
}

void ShowGrid(vector<vector<Node*> > g)
{
    int Size = g.size();
    
    for(int i = 0; i < Size; i++)
    {
        for(int j = 0; j < Size; j++)
        {
            cout << g[i][j]->GetH() << " ";
        }
        cout << "\n";
    }
}

vector<Node*> SearchAdjacentNodes(vector<vector<Node*> > g, Node* n)
{
    int Size = g.size();
    int In,Jn;

    for(int i = 0; i < Size; i++)
    {
        for(int j = 0; j < Size; j++)
        {
            if(g[i][j] == n)
            {
                In = i;
                Jn = j;
                continue;
            }           
        }
    }

    vector<Node*> v;

    try
    {
        g.at(In+1).at(Jn);
        v.push_back(g[In+1][Jn]);
    }
    catch(const std::exception& e) {}

    try
    {
        g.at(In-1).at(Jn);
        v.push_back(g[In-1][Jn]);
    }
    catch(const std::exception& e) {}

    try
    {
        g.at(In).at(Jn+1);
        v.push_back(g[In][Jn+1]);
    }
    catch(const std::exception& e) {}

    try
    {
        g.at(In).at(Jn-1);
        v.push_back(g[In][Jn-1]);
    }
    catch(const std::exception& e) {}
    
    return v;
}

void BestFirstSearch(vector<vector<Node*> > g, Node* StartNode, Node* EndNode)
{
    Node* CurrentNode = StartNode;

    vector<Node*> v = SearchAdjacentNodes(g, CurrentNode);

    /*std::cout << "Adjacent Nodes to the Current Node " << CurrentNode->GetH() << " are : ";   //For Debug
    for(int j = 0; j < v.size(); j++) std::cout << v[j]->GetH() << " ";  */ 

    struct BST* ClosedSet = Insert(ClosedSet, CurrentNode);

    vector<Node*> neighbors = SearchAdjacentNodes(g, CurrentNode);

    for(int i = 0; i < neighbors.size(); i++)
    {
        if(Search(ClosedSet, neighbors[i]))
            continue;
        else
        {
            
        }
    }
}


int main(int argc, char *argv[]) {

    vector<vector<Node*> > MainGrid = ConstructIntGrid();
    
    ShowGrid(MainGrid);
    std::cout << endl;

    int Size = MainGrid.size();
    
    
    //BestFirstSearch(MainGrid, MainGrid[1][1], MainGrid[Size-1][Size-1]);

    
    

    return 0;
    
}