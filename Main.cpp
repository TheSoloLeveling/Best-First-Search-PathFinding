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

vector<vector<int> > ConstructIntGrid()
{
    vector<vector<int> > grid;

    int size;

    cout << "Enter size : ";
    cin >> size;
  

    for(int i = 0; i < size; i++)
    {
        vector<int> v;
        for(int j = 0; j < size; j++)
        {
            v.push_back(Rand(1, 10));
        }
        grid.push_back(v);
    }
    return grid;
}

void BestFirstSearch(Node* StartNode, Node* EndNode)
{
    

}

void ShowGrid(vector<vector<int> > g)
{
    int Size = g.size();
    
    for(int i = 0; i < Size; i++)
    {
        for(int j = 0; j < Size; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char *argv[]) {

    vector<vector<int> > MainGrid = ConstructIntGrid();
    
    ShowGrid(MainGrid);

    Node* node = new Node(NULL, Rand(0, 10));

    node->Print();

    
}