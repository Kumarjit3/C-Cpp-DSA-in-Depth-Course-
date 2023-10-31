#include<iostream>
#include<conio.h>
using namespace std;
int menu();

class Graph
{
     private:
        int v_count;
        int e_count;
        int** ptr;
     protected:
        void setEdge();
     public:
        Graph() : v_count(0),e_count(0),ptr(NULL) { }   
        bool isEmpty();
        int createGraph(int,int);
        void showGraph();
        void showTotalNumbersOfNodes();
        void showTotalNumberOfEdges();
        void removeEdge(int);
        void Adjacent_nodes_of_a_given_node(int);
        void node_isolated_or_not(int);
        ~Graph();
};


Graph::~Graph()
{
    if(ptr!=NULL)
    {
        for(int i=0; i<v_count; i++)
        {
            delete []ptr[i];
        }
        delete []ptr;
    }
    else
    delete []ptr;
}

int Graph::createGraph(int v,int e)
{
    v_count=v;
    e_count=e;
    ptr=new int*[v]; 
    for(int i=0; i<v_count; i++)
    {
        ptr[i]=new int[v];
    }
    for(int p=0; p<v; p++)
    {
    for(int j=0; j<v; j++)
    {
        ptr[p][j]=0;
        ptr[j][p]=0;
    }
   }
   setEdge();
   return 1;
}

bool Graph::isEmpty()
{
    if(ptr==NULL)
    return true;
    else
    return false;
}

void Graph::showGraph()
{
    cout<<endl;
    for(int i=0; i<v_count; i++)
    {
        if(i==0)
        cout<<"    "<<"V"<<i<<" ";
        else
        cout<<"V"<<i<<" ";
    }
    cout<<endl;
    for(int i=0; i<(v_count); i++)
    {
        cout<<"V"<<i<<""<<" ";
        for(int j=0; j<(v_count); j++)
        {
            cout<<" "<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::setEdge()
{
    int m,p;
    cout<<endl;
    for(int i=0; i<e_count; i++)
    {
       cout<<endl<<"Enter node numbers connecting edge [vi<---->vj] : "; cin>>m>>p;
       ptr[m][p]=1;
       ptr[p][m]=1;
    }
}

void Graph::removeEdge(int n)
{
    int m,p;
    cout<<endl;
    for(int i=0; i<n; i++)
    {
       cout<<endl<<"Enter node numbers connecting edge [vi<---->vj] : "; cin>>m>>p;
       ptr[m][p]=0;
       ptr[p][m]=0;
       e_count--;
    }
}

void Graph::Adjacent_nodes_of_a_given_node(int v)
{
    if(v>=0&&v<v_count)
    {
        for(int i=0; i<v_count; i++)
        {
            if(ptr[v][i]==1&&ptr[i][v]==1)
            {
                cout<<endl<<v<<" <-------------> "<<i<<endl;
            }
        }
    }
    else
    {
        cout<<endl<<"Invalid Node"<<endl;
    }
}

void Graph::node_isolated_or_not(int v)
{
    int c=0;
    if(v>=0&&v<v_count)
    {
        for(int i=0; i<v_count; i++)
        {
            if(ptr[v][i]==1&&ptr[i][v])
            c++;
            else
            c;
        }
    }
    if(c==0)
    cout<<endl<<"Yes This Node Is Isolated"<<endl;
    else
    cout<<endl<<"No! This Node Is Not Isolated"<<endl; 
}

void Graph::showTotalNumberOfEdges()
{
    cout<<endl<<"Total Number Of Edges Are :"<<e_count<<endl;
}

void Graph::showTotalNumbersOfNodes()
{
    cout<<endl<<"Total Number Of Nodes Are :"<<v_count<<endl; 
}

int menu()
{
    int n;
    cout<<endl<<"\t\t--------------------------------------";
    cout<<endl<<"\t\t  GRAPH DATA STRUCTURE USING MATRIX";
    cout<<endl<<"\t\t--------------------------------------\n"<<endl;
    cout<<endl<<"1.CREATE GRAPH________________________";
    cout<<endl<<"2.SHOW GRAPH__________________________";
    cout<<endl<<"3.NODE ISOLATED OR NOT________________";
    cout<<endl<<"4.ADJACENT NODES OF A GIVEN NODE______";
    cout<<endl<<"5.TOTAL NUMBER OF NODES_______________";
    cout<<endl<<"6.TOTAL NUMBER OF EDGES_______________";
    cout<<endl<<"7.REMOVE EDGES________________________";
    cout<<endl<<"8.GRAPH IS EMPTY OR NOT_______________";
    cout<<endl<<"9.EXIT________________________________";
    cout<<endl<<"\nEnter Your Choice In Between[1/2/3/4/5/6/7/8] :- ";
    cin>>n; return n;
}

int main()
{
    system("cls");
    Graph g1;
    while(1)
    {
        switch(menu())
        {
          case 1:
          {
                int p,q;
                  cout<<endl<<"Enter Total Numbers Of Nodes : "; cin>>p;
                  cout<<endl<<"Enter Total Numbers Of Edges : "; cin>>q;
                  int k=g1.createGraph(p,q);  
                if(k==1)
                  cout<<endl<<"Graph Create Sucessfully"<<endl;
                else
                  cout<<endl<<"Graph Is Not Created"<<endl;
                 break;
          }
          case 2:
          {
                if(g1.isEmpty())
                {
                  cout<<endl<<"Graph Is Note Craeted! Create Graph First"<<endl;
                }
                else
                {
                  cout<<endl<<"Current Graph Matrix Is Looks Like : "<<endl;
                  g1.showGraph();
                }
                 break;
          }
          case 3:
          {
                if(g1.isEmpty())
                {
                  cout<<endl<<"Graph Is Note Craeted! Create Graph First"<<endl;
                }
                else
                {
                  int v;
                  cout<<endl<<"Enter Node No:- "; cin>>v;
                  g1.node_isolated_or_not(v);
                }      
                 break;
          }
          case 4:
          {
                if(g1.isEmpty())
                {
                  cout<<endl<<"Graph Is Note Craeted! Create Graph First"<<endl;
                }
                else
                {
                  int v;
                  cout<<endl<<"Enter Node No:- "; cin>>v;
                  g1.Adjacent_nodes_of_a_given_node(v);
                }
                 break;
          }
          case 5:
          {
                if(g1.isEmpty())
                {
                  cout<<endl<<"Graph Is Note Craeted! Create Graph First"<<endl;
                } 
                else
                {
                  g1.showTotalNumbersOfNodes();
                }
                 break;
          }
          case 6:
          {
                if(g1.isEmpty())
                {
                  cout<<endl<<"Graph Is Note Craeted! Create Graph First"<<endl;
                }
                else
                {
                 g1.showTotalNumberOfEdges();
                }
                 break;
          }
          case 7:
          {
                if(g1.isEmpty())
                {
                  cout<<endl<<"Graph Is Note Craeted! Create Graph First"<<endl;
                }
                else
                {
                    int n;
                    cout<<endl<<"Enter The Total Number Of Edges You Want To Remove : ";
                    cin>>n;
                    g1.removeEdge(n);
                    cout<<endl<<"Edges Remove Successful"<<endl;
                }
                 break;
          }
          case 8:
          {
                if(g1.isEmpty())
                {
                    cout<<endl<<"Yes The Graph Is Empty"<<endl;
                }
                else
                {
                    cout<<endl<<"No The Graph Is Not Empty"<<endl;
                }
                break;
          }
          case 9:
          {
                cout<<endl<<"\n\nExit_____________________________________________\n"<<endl;
                exit(0);
                break;
          }
          default:
          {
            cout<<endl<<"Wrong Choice! Choose Again"<<endl;
            break;
          }
        }
        cout<<endl<<"Enter Any Key To Continue : ";
        getch();
        system("cls");
    }
    cout<<endl;
    return 0;  
}