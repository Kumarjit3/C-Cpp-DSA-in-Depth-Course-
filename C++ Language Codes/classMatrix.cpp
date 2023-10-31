#include<iostream>
using namespace std;


class matrix
{    
     private:
        int **ptr;
        int row;
        int column;
     public:
        matrix() : ptr(NULL),row(0),column(0) { }
        void setRowColumn(int row,int column)
        {
            this->row=row;
            this->column=column;
            ptr=new int*[row];
            for(int i=0; i<row; i++)
            {
                ptr[i]=new int[column];
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
        matrix operator +(matrix m1)
        {
            matrix m2;
            m2.setRowColumn(m1.row,m1.column);
            for(int i=0; i<m1.row; i++)
            {
                for(int j=0; j<m1.column; j++)
                {
                   m2.ptr[i][j] = this->ptr[i][j]+m1.ptr[i][j];
                }
            }
            return m2;
        }
        matrix operator -(matrix m1)
        {
            matrix m2;
            m2.setRowColumn(m1.row,m1.column);
            for(int i=0; i<m1.row; i++)
            {
                for(int j=0; j<m1.column; j++)
                {
                   m2.ptr[i][j] = this->ptr[i][j]-m1.ptr[i][j];
                }
            }
            return m2;
        }
        matrix operator *(matrix m1)
        {
            matrix m2;
            m2.setRowColumn(m1.row,m1.column);
            for(int i=0; i<m1.row; i++)
            {
                for(int j=0; j<m1.column; j++)
                {
                    m2.ptr[i][j]=0;
                    for(int k=0; k<m1.row; k++)
                    {
                        m2.ptr[i][j]+=(this->ptr[i][k]*(m1.ptr[k][j]));
                    }
                }
            }
            return m2;
        }    
}; 


int main()
{
    system("cls");
    matrix m1,m2,m3;
    m1.setRowColumn(3,3);
    m2.setRowColumn(3,3);
    m1.setMatrix();
    cout<<endl<<"Matrix M1 Looks Like : "<<endl;
    m1.showMatrix();
    m2.setMatrix();
    cout<<endl<<"Matrix M2 Looks Like : "<<endl;
    m2.showMatrix();
    m3=m1+m2;
    cout<<endl<<"The Addition Of M1 And M2 Is : "<<endl;
    m3.showMatrix();
    m3=m1-m2;
    cout<<endl<<"The Subtraction Of M1 And M2 Is : "<<endl;
    m3.showMatrix();
    m3=m1*m2;
    cout<<endl<<"The Multiplication Of M1 And M2 Is : "<<endl;
    m3.showMatrix();
    cout<<endl;
    return 0;
}