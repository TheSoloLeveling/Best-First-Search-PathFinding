
class Node
{
    private:
        int H;
        Node* Parent;

    public:
        Node();
        Node(Node* Parent, float H);
        void Print();

        int GetH() {return this->H;}
        Node* GetParent() {return this->Parent;}

        void SetParent(Node* Parent) {this->Parent = Parent;}
        void SetH(int H) {this->H = H;}

};