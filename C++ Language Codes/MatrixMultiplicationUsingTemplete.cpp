#include<iostream>
using namespace std;

template<typename T>
class matrix
{    
     private:
        T **ptr;
        int row,column;
     public:
        matrix() : ptr(NULL),row(0),column(0) { }
        void setRowColumn(int row,int column)
        {
            this->row=row;
            this->column=column;
            ptr=new T*[row];
            for(int i=0; i<row; i++)
            {
                ptr[i]=new T[column];
            }
        }
        void setMatrix()
        {
            cout<<"Enter "<<row*column<<" Values : \n"<<endl;
            for(int i=0; i<row; i++)
            {
                for(int j=0; j<column; j++)
                {
                    cin>>ptr[i][j];
                }
            }
        }
        void showMatrix()
        {
            for(int i=0; i<row; i++)
            {
                for(int j=0; j<column; j++)
                {
                    cout<<ptr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        matrix MatMUl(matrix m1,matrix m2)
        {
            matrix m3;
            m3.setRowColumn(m1.row,m1.column);
            for(int i=0; i<m1.row; i++)
            {
                for(int j=0; j<m1.column; j++)
                {
                    m3.ptr[i][j]=0;
                    for(int k=0; k<m1.row; k++)
                    {
                        m3.ptr[i][j]+=(m1.ptr[i][k]*(m2.ptr[k][j]));
                    }
                }
            }
            return m3;
        }    
}; 


int main()
{
    system("cls");
    matrix<int> m1,m2,m3;
    m1.setRowColumn(3,3);
    m2.setRowColumn(3,3);
    m1.setMatrix();
    m2.setMatrix();
    m3=m3.MatMUl(m1,m2);
    cout<<endl<<"After Multiplication Of Int Matrix : "<<endl;
    m3.showMatrix();
    cout<<endl;
    matrix<float> m4,m5,m6;
    m4.setRowColumn(3,3);
    m5.setRowColumn(3,3);
    m4.setMatrix();
    m5.setMatrix();
    cout<<endl<<"After Multiplication Of Float Matrix : "<<endl;
    m6=m6.MatMUl(m4,m5);
    m6.showMatrix();
    return 0;
}
