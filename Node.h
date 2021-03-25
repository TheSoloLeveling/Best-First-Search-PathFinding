

class Node
{
    private:
        float H;
        Node* Parent;

    public:
        Node(Node* Parent, float H);
        void Print();
        float GetH();


};