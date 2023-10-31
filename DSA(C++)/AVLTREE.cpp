#include<iostream>
using namespace std;

int max(int a,int b)
{
    return (a>b)?a:b;
}

struct node
{
    node* left;
    node* right;
    int item;
    int height;
};

class AVL
{
    private:
        node* root;
    protected:
        void insert(node*,int); 
        void Deletee(node*,node*,int); 
        void setHeight(node*);
        void updateHeight(node*);  
    public:
        AVL();
        int Insert(int);
        int Delete(int);
        int GetHeight(node*);
        int GetBalanceFactor(node*);
        void RR_Rotaion(node*);
        void LL_Rotation(node*);   
};

AVL::AVL()
{
    root=NULL;
}