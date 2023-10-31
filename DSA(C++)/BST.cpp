#include<iostream>
#include<conio.h>
using namespace std;
int menu();

struct node
{
    node* left;
    node* right;
    int item;
};

class BST
{
    private:
        node *root;
    protected:
       void firstInsert(int); 
       void leftInsert(int);
       void rightinsert(int); 
       void print(node*,string,bool);
       int DeleteNodeWithZeroChild(node*); 
       int DeleteNodeWithOneChild(node*);
       int DeleteNodeWithTwoChild(node*);
       void in(node*);
       void pre(node*);
       void post(node*); 
       void count(node*,int&);
    public:
       BST(): root(NULL) { }
       bool isEmpty(); 
       int insert(int);
       void printTree();
       node* searchItem(int);
       int Delete(int);
       void inOrderTraversal();
       void preOrderTraversal();
       void postOrderTraversal();
       int countTotalNode();
};


bool BST::isEmpty()
{
    if(root==NULL)
    return true;
    else
    return false;
}

int BST::insert(int data)
{
    node*k=searchItem(data);
    if(k==NULL)
    {
    if(isEmpty())
    {
      firstInsert(data);
      return 1;
    }
    else if(root->item<data)
    {
      rightinsert(data);
      return 1;
    }
    else if(root->item>data)
    {
      leftInsert(data);
      return 1;
    }
    }
    else
    {
        cout<<endl<<"\nSorry! Duplicate Insert Not Possible"<<endl;
        return 0;
    }
    return 0;
}


void BST::firstInsert(int data)  //Root is Empty Condition
{
   node* n=new node;
   n->left=NULL;
   n->right=NULL;
   n->item=data;
   root=n;
}

void BST::leftInsert(int data)
{
    node* c=root;
    while(c)
    {
        if(c->left==NULL&&c->item>data)
        {
            node* n=new node;
            n->item=data;
            n->left=NULL; 
            n->right=NULL;   
            c->left=n;
            break;         
        }
        else if(c->right==NULL&&c->item<data)   
        {
            node* n=new node;
            n->item=data;
            n->left=NULL;
            n->right=NULL;
            c->right=n;
            break;
        }
        else if(c->left!=NULL&&c->item>data)
        {
            c=c->left;
        }
        else if(c->right!=NULL&&c->item<data)
        {
            c=c->right;
        } 
    }
}

void BST::rightinsert(int data)
{
    node* c=root;
    while(c)
    {
        if(c->right==NULL&&c->item<data)
        {
            node* n=new node;
            n->item=data;
            n->left=NULL; 
            n->right=NULL;   
            c->right=n;
            break;         
        }
        else if(c->left==NULL&&c->item>data)   
        {
            node* n=new node;
            n->item=data;
            n->left=NULL;
            n->right=NULL;
            c->left=n;
            break;
        }
        else if(c->right!=NULL&&c->item<data)
        {
            c=c->right;
        }
        else if(c->left!=NULL&&c->item>data)
        {
            c=c->left;
        }
    }
}

void BST::printTree()
{
    print(root, " ",true);
}

void BST::print(node* root,string indent,bool last)
{
    if(root!=NULL)
    {
        cout<< indent;
        if(last)
        {
            cout<< "R----";
            indent += "  ";
        }
        else
        {
            cout<< "L----";
            indent += "|  ";
        }
        cout<< root->item<<endl;
        print(root->left,indent,false);
        print(root->right,indent,true);
    }
}


node* BST::searchItem(int data)
{
    node*r=root;
    while(r)
    {
        if(r->item==data)
        return r;
        else if(data<r->item)
        r=r->left;
        else
        r=r->right;
    }
    return NULL;
}

int BST::Delete(int data)
{
    if(searchItem(data)==NULL)
    cout<<endl<<"Sorry Item is not there"<<endl;
    else
    {
        node* k=searchItem(data);
        if(k->left!=NULL&&k->right!=NULL)
        return DeleteNodeWithTwoChild(k);
        else if(k->left==NULL&&k->right!=NULL)
        return DeleteNodeWithOneChild(k);
        else if(k->left!=NULL&&k->right==NULL)
        return DeleteNodeWithOneChild(k);
        else
        return DeleteNodeWithZeroChild(k);
    }
    return 0;
}

int BST::DeleteNodeWithTwoChild(node* k)
{
    node* p=root;
    while(p)
    {
        if(p->item==k->item) //Delete root node with two child
        {
            node*v=p->right;
            if(v->left==NULL)
            {
                root->item=p->item;
                node*c=p->right;
                delete p;
                root->right=c;
                return 1;
                break;
            }
            else
            {
               if(v->left->left==NULL)
               {
                 root->item=v->left->item;
                 node*c=v->left->right;
                 delete v->left;
                 v->left=c;
                 return 1;
                 break;
               }
               else
               {
                 while(v->left->left!=NULL)
                 v=v->left;
                 root->item=v->left->item;
                 node*c=v->left->right;
                 delete v->left;
                 v->left=c;
               }    
            }    
        }
        else if(p->left->item==k->item) //Delete left subtree with two child
        {
             node*v=p->left;
             p=p->left;
            if(v->left==NULL)
            {
                node*c=p->right;
                delete p;
                root->left=c;
                return 1;
                break;
            }
            else
            {
               if(v->left->left==NULL)
               {
                 p->item=v->left->item;
                 node*c=p->left->right;
                 delete p->left;
                 v->left=c;
                 return 1;
                 break;
               } 
               else
               {
                 while(v->left->left!=NULL)
                 v=v->left;
                 p->item=v->left->item;
                 node*c=v->left->right;
                 delete v->left;
                 v->left=c;
                 return 1;
                 break;
               }   
            }
        }
        else if(p->right->item==k->item) //Delete right subtree with two child
        {
             node*v=p->right;
             p=p->right;
            if(v->left==NULL)
            {
                node*c=v->right;
                delete v;
                root->right=c;
                return 1;
                break;
            }
            else
            {
               if(v->left->left==NULL)
               {
                 p->item=v->left->item;
                 node*c=v->left->right;
                 delete v->left;
                 v->left=c;
                 return 1;
                 break;
               } 
               else
               {
                 while(v->left->left!=NULL)
                 v=v->left;
                 p->item=v->left->item;
                 node*c=v->left->right;
                 delete v->left;
                 v->left=c;
                 return 1;
                 break;
               }   
            }
        }
        else if(k->item>p->item)
        p=p->right;
        else if(k->item<p->item)
        p=p->left;
    }
    return 0;
}

int BST::DeleteNodeWithOneChild(node* k)
{
    cout<<endl<<"YES"<<endl;
    node* p=root;
    while(p)
    {
        if(p->item==k->item) //Delete root node with one child
        {
            if(p->right==NULL)
            {
                node*v=p->left;
                if(v->right!=NULL)
                {
                   while(v->right->right!=NULL)
                   v=v->right;
                   root->item=v->right->item;
                   v->right=v->right->left;
                   delete v->right;
                   return 1;
                   break;
                }
                else
                {
                  root->item=v->item;
                  root->left=v->left;
                  delete v;
                  return 1;
                  break;
                }

            }
            else if(p->left==NULL)
            {
                node* v=p->right;
                if(v->right==NULL&&v->left==NULL)
                {
                  p->item=v->item;
                  delete v;
                  p->right=NULL;
                  return 1;
                  break;
                }
                else if(v->right==NULL&&v->left!=NULL)
                {
                    while(v->left->left!=NULL)
                    v=v->left;
                    root->item=v->left->item;
                    node*c=v->left->right;
                    delete v->left;
                    v->left=c;
                    return 1;
                    break;
                }
                else if(v->right!=NULL&&v->left==NULL)
                {
                    node* n=v->right;
                    root->item=v->item;
                    delete v;
                    root->right=n;
                    return 1;
                    break;
                }
                else
                {
                   while(v->left->left!=NULL)
                     v=v->right;
                     root->item=v->left->item;
                     v->left=v->left->right;
                     delete v->left;
                     return 1;
                     break;
                }
            }
        }
        else if(p->left->item==k->item) //Delete left subtree with one child
        {
            node* v=p->left;
            if(v->right==NULL)
            {
               node* m=p->left;
               delete m;
               p->left=v->left;
               return 1;
               break;
            }
            else
            {
               node* m=p->left;
               delete m;
               p->left=v->right;
               return 1;
               break;
            }
        }
        else if(p->right->item==k->item)  //Delete right subtree with one child
        {
            node* v=p->right;
            if(v->left==NULL)
            {
               node* m=p->right;
               delete m;
               p->right=v->right;
               return 1;
               break;
            }
            else
            {
               node* m=p->right;
               delete m;
               p->right=v->left;
               return 1;
               break;
            }
        }
        else if(k->item>p->item)
        p=p->right;
        else if(k->item<p->item)
        p=p->left;
    }
    return 0;
}

int BST::DeleteNodeWithZeroChild(node* k)
{
    node* p=root;
    while(p)
    {
        if(p->item==k->item) //Delete root node with zero child
        {
            delete p;
            root=NULL;
            return 1;
            break;
        }
        else if(p->right->item==k->item) //Delete right subtree with zero child
        {
            delete p->right;
            p->right=NULL;
            return 1;
            break;
        }
        else if(p->left->item==k->item) //Delete left subtree with zero child
        {
            delete p->left;
            p->left=NULL;
            return 1;
            break;
        }
        else if(k->item>p->item)
        p=p->right;
        else
        p=p->left;
    }
    return 0;
}

void BST::inOrderTraversal()
{
    cout<<endl;
    in(root);
    cout<<endl; 
}

void BST::preOrderTraversal()
{
    cout<<endl;
    pre(root);
    cout<<endl;
}

void BST::postOrderTraversal()
{
    cout<<endl;
    post(root);
    cout<<endl; 
}

void BST::in(node* n)
{
    if(n)
    {
        in(n->left);
        cout<<n->item<<" ";
        in(n->right);
    }
}

void BST::pre(node* n)
{
    if(n)
    {
        cout<<n->item<<" ";
        pre(n->left);
        pre(n->right);
    }
}

void BST::post(node* n)
{
    if(n)
    {
        pre(n->left);
        pre(n->right);
        cout<<n->item<<" ";
    }
}

int BST::countTotalNode()
{
    int c=0;
    count(root,c);
    return c;
}

void BST::count(node* n,int &c)
{
    if(n==NULL)
    return;
       c++;
       count(n->left,c);
       count(n->right,c);
}


int menu()
{
    int k;
    cout<<endl<<"\n\t\tBINARY SEARCH TREE DATA STRUCTURE\n"<<endl;
    cout<<endl<<"1.FOR INSERTION__________";
    cout<<endl<<"2.FOR DISPLAY____________";
    cout<<endl<<"3.FOR DELETION___________";
    cout<<endl<<"4.FOR SEARCHING__________";
    cout<<endl<<"5.FOR INORDER DISPLAY____";
    cout<<endl<<"6.FOR PREORDER DISPLAY___";
    cout<<endl<<"7.FOR POSTORDER DISPLAY__";
    cout<<endl<<"8.FOR COUNT TOTAL NODE___";
    cout<<endl<<"9.FOR TREE EMPTY CHECK___";
    cout<<endl<<"10.FOR EXIT______________";
    cout<<endl<<"\nENTER YOUR CHOICE IN BETWEEN [1/2/3/4/5/6/7/8/9/10] :- "; cin>>k;
    return k;
}

int main()
{
    system("cls");
    BST b1;
    while(1)
    {
        switch(menu())
        {
            case 1:
            {
                int data,k;
                cout<<endl<<"Enter The Data : "; cin>>data;
                k=b1.insert(data);
                if(k==1)
                cout<<endl<<"Insert Successfull"<<endl;
                else
                cout<<endl<<"Insert Not Successfull"<<endl;
                break;
            }
            case 2:
            {
                if(b1.isEmpty())
                cout<<endl<<"Tree Is Empty"<<endl;
                else
                cout<<endl<<"The Current BST Is__________\n"<<endl;
                b1.printTree();
                break;
            }
            case 3:
            {
               if(b1.isEmpty())
               {
                 cout<<endl<<"Tree Is Empty"<<endl;
                 break;
               }
               else
               {
               int data,k;
               cout<<endl<<"Enter The Data : "; cin>>data; 
               node*n=b1.searchItem(data);
               if(n!=NULL)
               k=b1.Delete(data);
               else
               cout<<endl<<"Item Not Found"<<endl;
               if(k==1)
                cout<<endl<<"Delete Successfull"<<endl;
               else
                cout<<endl<<"Delete Not Successfull"<<endl;
                break;
               }
            }
            case 4:
            {
               if(b1.isEmpty())
               {
                 cout<<endl<<"Tree Is Empty"<<endl;
                 break;
               } 
               else
               {
               int data,k;
               cout<<endl<<"Enter The Data : "; cin>>data; 
               node*n=b1.searchItem(data);
               if(n!=NULL)
                cout<<endl<<"Item Found Search Successfull"<<endl;
               else
                cout<<endl<<"Item Not Found Search Unsuccessfull"<<endl;
                break;
               }
            }
            case 5:
            {
                if(b1.isEmpty())
                cout<<endl<<"Tree Is Empty"<<endl;
                else   
                cout<<endl<<"After Inorder Traversal The BST Looks Like__________"<<endl;
                b1.inOrderTraversal();
                break;
            }
            case 6:
            {
                if(b1.isEmpty())
                cout<<endl<<"Tree Is Empty"<<endl;
                else   
                cout<<endl<<"After Preorder Traversal The BST Looks Like__________"<<endl;
                b1.preOrderTraversal();
                break;
            }
            case 7:
            {
                if(b1.isEmpty())
                cout<<endl<<"Tree Is Empty"<<endl;
                else   
                cout<<endl<<"After Postorder Traversal The BST Looks Like__________"<<endl;
                b1.postOrderTraversal();
                break;
            }
            case 8:
            {
                int k;
                if(b1.isEmpty())
                {
                cout<<endl<<"Tree Is Empty"<<endl;
                break;
                }
                else
                k=b1.countTotalNode();
                cout<<endl<<"Total Number's Of Nodes Of The Tree Is : "<<k<<endl;
                break;
            }
            case 9:
            {
                if(b1.isEmpty())
                cout<<endl<<"Tree Is Empty"<<endl;
                else
                cout<<endl<<"Tree Is Not Empty"<<endl;
                break;
            }
            case 10:
            {
                cout<<endl<<"\nExit___________________________________\n\n"<<endl;
                exit(0);
                break;
            }
            default:
            {
                cout<<endl<<"Wrong Choice! Choose Correctly"<<endl;
                break;
            }
        }
        cout<<endl<<"Enter Any Key For Continue__________";
        getch();
        system("cls");
    }
    return 0;
}