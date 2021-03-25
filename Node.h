
class Node
{
    private:
        float H;
        Node* Parent;

    public:
        Node();
        Node(Node* Parent, float H);
        void Print();

        float GetH() {return this->H;}
        Node* GetParent() {return this->Parent;}

        void SetParent(Node* Parent) {this->Parent = Parent;}

};