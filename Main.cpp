#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "Node.h"


using namespace std;

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

void BestFirstSearch(Node* StartNode, Node* EndNode)
{
    Node* CurrentNode = StartNode;

}


int main(int argc, char *argv[]) {

    vector<vector<Node*> > MainGrid = ConstructIntGrid();
    
    ShowGrid(MainGrid);

    Node* node = new Node(NULL, Rand(0, 10));

    node->Print();

    
}