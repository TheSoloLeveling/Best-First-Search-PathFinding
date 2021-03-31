using namespace std;

class Node
{
    private:
        int H;
        int X;
        int Y;
        Node* Parent;

    public:
        Node();
        Node(int X, int Y);
        void Print();

        int GetH() {return this->H;}
        int GetX() {return this->X;}
        int GetY() {return this->Y;}
        Node* GetParent() {return this->Parent;}

        void SetParent(Node* Parent) {this->Parent = Parent;}
        void SetH(int H) {this->H = H;}

        bool operator()(Node* a,Node* b)
        {
            return a->GetH() < b->GetH();
        }

};


