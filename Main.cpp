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

void SearchAdjacentNodes(vector<vector<Node*> > g, Node* n)
{
    int Size = g.size();
    Node* data;

    for(int i = 0; i < Size; i++)
    {
        for(int j = 0; j < Size; j++)
        {
            if (g[i][j] == n)
            {
                data = n;
                continue;
            }           
        }
    }

    

}

void BestFirstSearch(vector<vector<Node*> > g, Node* StartNode, Node* EndNode)
{
    Node* CurrentNode = StartNode;

    int Size = g.size();
    int In, Jn;

    for(int i = 0; i < Size; i++)
    {
        for(int j = 0; j < Size; j++)
        {
            if (g[i][j] == CurrentNode)
            {
                In = i;
                Jn = j;
                continue;
            }           
        }
    }

    g[In+1][Jn]->SetParent(CurrentNode);
    g[In-1][Jn]->SetParent(CurrentNode);
    g[In][Jn+1]->SetParent(CurrentNode);
    g[In][Jn-1]->SetParent(CurrentNode);

}


int main(int argc, char *argv[]) {

    vector<vector<Node*> > MainGrid = ConstructIntGrid();
    
    ShowGrid(MainGrid);

    int Size = MainGrid.size();
    
    
    BestFirstSearch(MainGrid, MainGrid[0][0], MainGrid[Size-1][Size-1]);

    
    for(int i = 0; i < Size; i++)
    {
        for(int j = 0; j < Size; j++)
        {
            cout <<  MainGrid[i][j]->GetParent();        
        }
        cout << "\n";
    }

    
    
}