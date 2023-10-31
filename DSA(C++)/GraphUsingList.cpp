#include<iostream>
using namespace std;

struct node
{
    int item;
    int vertex;
    node *next;
};

class AdjList
{
    private:
        node *start;
    public:
        AdjList() : start(NULL) { }
        node* getStart();
        int AddNode(int,int);
        int RemoveFirstNode();
        void printList();
        ~AdjList();
};

node* AdjList::getStart()
{
    return start;
}

int AdjList::AddNode(int v,int data)
{
    node* n=new node;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start=n;
    return 1;
}

int AdjList::RemoveFirstNode()
{
    node* t=start;
    if(start)
    {
      start=start->next;
      delete t;
    }
    return 1;
}

void AdjList::printList()
{
    node* t=start; static int i=0;
    cout<<endl;
    while(t)
    {
        if(t==start)
        {
            cout<<"Node[V-"<<i<<"] = "<<"| V"<<t->vertex<<" | "<<t->item<<" |--->";
        }
        else if(t->next==NULL)
        {
            cout<<" | V"<<t->vertex<<" | "<<t->item<<" |--->NULL";
        }
        else
        {
            cout<<" | V"<<t->vertex<<" | "<<t->item<<" |--->";
        }
        t=t->next;
    }
    cout<<endl;
    i++;
}

AdjList::~AdjList()
{
   while(start)
   RemoveFirstNode();
   start=NULL;
}


class Graph
{
    private:
         int v_count;
         AdjList *ptr;
    public:
        Graph() :v_count(0),ptr(NULL) { }
        Graph(int);
        int CreateGraph(int);
        void PrintGraph();
        int getV_Count();
        ~Graph();      
};

Graph::Graph(int v)
{
    v_count=v;
    ptr=NULL;
}

int Graph::getV_Count()
{
    return v_count;
}

int Graph::CreateGraph(int v)
{
    v_count=v;
    int data,e,a;
    ptr=new AdjList[v];
    for(int i=0; i<v_count; i++)
    {
        cout<<endl<<"Enter Number Of Adjacent Nodes Of v["<<i<<"] :- "; cin>>e;
        for(int j=0; j<e; j++)
        {
            cout<<endl<<"Enter Vertex No : "; cin>>v;
            cout<<endl<<"Enter The Item : ";  cin>>data;
            ptr[i].AddNode(v,data);
        }
    }
    return 1;
}

void Graph::PrintGraph()
{
    cout<<endl<<"The Current Graph List Is Looks Like :- "<<endl;
    for(int i=0; i<v_count; i++)
    {
        cout<<endl;
        ptr[i].printList();
    }
}

Graph::~Graph()
{
    delete []ptr;
}


int main()
{
    system("cls");
    Graph g1;
    g1.CreateGraph(4);
    g1.PrintGraph();
    cout<<endl;
    return 0;
}