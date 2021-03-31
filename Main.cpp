#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <queue>
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
        
        temp->Data = new Node(n->GetX(), n->GetY());

        temp->LeftChild = temp->RightChild = NULL;
        
        return temp;
    }
    
    
    if (n->GetH() < Bst->Data->GetH() )
        Bst->LeftChild = Insert(Bst->LeftChild, n);
    else
        Bst->RightChild = Insert(Bst->RightChild, n);
    return Bst;       
}

struct BST* BST_Search(struct BST* Bst, Node* n)
{
    if(Bst == NULL || (Bst->Data->GetX() == n->GetX() && Bst->Data->GetY() == n->GetY()))
        return Bst;

    if(Bst->Data->GetH() < n->GetH())
        return BST_Search(Bst->RightChild, n);

    return BST_Search(Bst->LeftChild, n);
}

int Vector_Search(vector<Node*> v, Node* n)
{
    for(int i = 0; i < v.size(); i++)
    {
        if (v[i]->GetX() == n->GetX() && v[i]->GetY() == n->GetY() )
            return i;
    }
    return -1;
}

Node* Vector_Min(vector<Node*> v)
{
    Node* min = v[0];
    for(int i = 0; i < v.size(); i++)
    {
        if (v[i]->GetH() < min->GetH())
            min = v[i];
    }

    return min;
}

void Inorder(struct BST* p)
{
    if(p)
    {
        Inorder(p->LeftChild);
        cout << "(" << p->Data->GetX() << "," << p->Data->GetY() << ")-->";
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
            Node* data = new Node(i, j);
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
            cout << "(" << g[i][j]->GetX() << "," << g[i][j]->GetY() << ")  ";
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

struct BST* BestFirstSearch(vector<vector<Node*> > g, Node* StartNode, Node* EndNode)
{
    
    Node* CurrentNode = StartNode;

    struct BST* ClosedSet = NULL;
    
    ClosedSet = Insert(ClosedSet, CurrentNode);
    vector<Node*> OpenSet;

    do
    {
        /*std::cout << "Adjacent Nodes to the Current Node " << CurrentNode->GetH() << " are : ";   //For Debug
        for(int j = 0; j < v.size(); j++) std::cout << v[j]->GetH() << " ";  */

        vector<Node*> neighbors = SearchAdjacentNodes(g, CurrentNode);


        for(int i = 0; i < neighbors.size(); i++)
        {
            if(BST_Search(ClosedSet, neighbors[i]) != NULL)
                continue;
            else
            {
                neighbors[i]->SetParent(CurrentNode);
                int distance = abs(neighbors[i]->GetX() - EndNode->GetX()) + abs(neighbors[i]->GetY() - EndNode->GetY());
                neighbors[i]->SetH(distance);
                if(Vector_Search(OpenSet, neighbors[i]) == -1)
                {
                    OpenSet.push_back(neighbors[i]);
                }
            }
        }

        if(OpenSet.empty())
            break;
        
        CurrentNode = Vector_Min(OpenSet);
       
        OpenSet.erase(OpenSet.begin() + Vector_Search(OpenSet, CurrentNode));
      
        ClosedSet = Insert(ClosedSet, CurrentNode);
     
        
    } while (CurrentNode != EndNode); 
    
    return ClosedSet;
}

int main(int argc, char *argv[]) {

    vector<vector<Node*> > MainGrid = ConstructIntGrid();
    ShowGrid(MainGrid);
    std::cout << endl;

    int costMin = 0;
    int i1, j1, i2, j2;
    cout  << "======================== BEST FIRST SEARCH ALGORITHM PROGRAM =========================" << endl;
    cout  << "Enter Start Node" << endl;
    cout  << "Enter X : " << endl;
    cin >> i1;
    cout  << "Enter Y : " << endl;
    cin >> j1;
    cout  << "Enter End Node" << endl;
    cout  << "Enter X : " << endl;
    cin >> i2;
    cout  << "Enter Y : " << endl;
    cin >> j2;
    
    struct BST* Result = BestFirstSearch(MainGrid, MainGrid[i1][j1], MainGrid[i2][j2]);
    
    cout << "Route : ";
    Inorder(Result);
    cout << "END";
    std::cout << endl;
    
        
   
}