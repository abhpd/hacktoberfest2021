#include<iostream>
using namespace std;

struct matrix {
    int row;
    int col;
    int** data;
};
 
matrix create(int r, int c)
{
    //matrix m=(matrix*)malloc(sizeof(matrix));
    matrix m;
    m.row = r;
    m.col = c;
    m.data = (int**)calloc(r,sizeof(int));
    for(int i=0;i<r;i++)
    {
        m.data[i] = (int*)calloc(c,sizeof(int));
    }

    return m;
}
matrix operator+(matrix x, matrix y)
{ 
    matrix c = create(x.row,x.col);
    for(int i=0;i<x.row;i++)
    {
        for(int j=0;j<y.row;j++)
        {
            c.data[i][j] = x.data[i][j] + y.data[i][j];
        }
    }
    return c;    
}
matrix operator+=(matrix &x, matrix y)
{ 
    //matrix c = create(3,3);
    for(int i=0;i<x.row;i++)
    {
        for(int j=0;j<x.col;j++)
        {
            x.data[i][j] = x.data[i][j] + y.data[i][j];
        }
    }
    return x;    
}
matrix transpose(matrix m)
{
    matrix z = create(m.row,m.col);
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            z.data[j][i] = m.data[i][j];
        }
    }
    return z;

}
matrix operator*(matrix x, matrix y)
{ 
    matrix c = create(x.row,x.col);
    for (int i = 0; i < x.row; i++) {
        for (int j = 0; j < y.col; j++) {
 
            for (int k = 0; k < y.row; k++) {
                c.data[i][j] += x.data[i][k] * y.data[k][j];
            }
 
        }
 
    }
    return c;    
}
matrix operator*=(matrix &x, matrix y)
{ 

    matrix c = create(x.row,x.col);
    for (int i = 0; i < x.row; i++) {
        for (int j = 0; j < y.col; j++) {
 
            for (int k = 0; k < y.row; k++) {
                c.data[i][j] += x.data[i][k] * y.data[k][j];
            }
 
        }
 
    }
    for(int i=0;i<x.row;i++)
    {
        for(int j=0;j<x.col;j++)
        {
            x.data[i][j] = c.data[i][j];
        }
    }
    return x;    
}
bool operator==(matrix x, matrix y)
{ 
    //matrix c = create(3,3);
    for(int i=0;i<x.row;i++)
    {
        for(int j=0;j<x.col;j++)
        {
            if(x.data[i][j] != y.data[i][j]) return false;
        }
    }
    return true;    
}
void print(matrix m,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<m.data[i][j]<<" "; 
        }
        printf("\n");
    }
}
int main()
{
    matrix a = create(3,3);
    matrix b = create(3,3);
    cout<<"please insert the first matrix"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a.data[i][j]; 
        }
    }
    cout<<"please insert the second  matrix"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>b.data[i][j]; 
        }
    }

    matrix c = a+b;
    cout<<"Addition"<<endl; 
    print(c,3,3);
    cout<<endl;

    matrix d = a*b;
    cout<<"Multiplication"<<endl; 
    print(d,3,3);
    cout<<endl;

    if(a==b) cout<<"equal"<<endl;
    else cout<<"unequal"<<endl;

    a*= b;
    cout<<"Assignment operator *="<<endl; 
    print(a,3,3);
    cout<<endl;

    c+= d;
    cout<<"Assignment operator +="<<endl; 
    print(c,3,3);
    cout<<endl;
     
    matrix t = transpose(b);
    cout<<"Transpose of the matrix"<<endl; 
    print(t,3,3);
    cout<<endl; 
    
    return 0;

}
 
