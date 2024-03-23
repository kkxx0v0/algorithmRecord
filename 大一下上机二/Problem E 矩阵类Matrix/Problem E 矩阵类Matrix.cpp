#include<iostream>
#include<iomanip>
#include<string.h>
#define N 10
using namespace std;
class Matrix
{
public:
    int m, n;
    int p[N][N];
    Matrix()
    {
        m = 0;
        n = 0;
        //int** p=NULL;
        memset(p, true, sizeof(p) / sizeof(int));
    }
    Matrix(int m, int n)
    {
        this->m = m;
        this->n = n;
        memset(p, true, sizeof(p) / sizeof(int));
        /*p = new int* [m];
        for (int i = 0; i < n; i++)
        {
            p[i] = new int[n];
        }*/
    }
    friend istream& operator>>(istream&, Matrix&);
    friend ostream& operator<<(ostream&, const Matrix&);
    Matrix& operator*(Matrix& mat)
    {
        if (n != mat.m)
        {
            Matrix temp(0, 0);
            return temp;
        }
        Matrix temp(m, mat.n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < mat.n; j++)
            {
                int sum = 0;
                for (int k = 0; k < n; k++)
                {
                    sum += p[i][k] * mat.p[k][j];
                }
                temp.p[i][j] = sum;
            }
        }
        return temp;
    }
    void DiagonalOrder()
    {   
        bool b = true;
        int i=0, j=0;
        for (int k = 0; k < m + n; k++)
        {
            if (k)
            {
                cout << " ";
            }
            cout << p[i][j];
            if (i==0&&b==true)
            {
                if (k=n-1)
                {
                    i++;
                }
                else
                {
                    j++;
                }
                b = false;
            }
            else if (j==0&&b==false)
            {
                i++;
                b = true;
            }
            else if (b==true)
            {
                --i;
                j++;
                --k;
            }
            else if (b == false)
            {
                i++;
                --j;
                --k;
            }
        }
    }
    void setZeros()
    {
        bool is[N][N];
        memset(is, true, sizeof(is) / sizeof(bool));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (p[i][j]==0)
                {
                    is[i][j] = false;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!is[i][j])
                {
                    for (int a = 0; a < n; a++)
                    {
                        p[i][a] = 0;
                    }
                    for (int a = 0; a < m; a++)
                    {
                        p[a][j] = 0;
                    }
                }
            }
        }
    }
};
istream& operator>>(istream& input, Matrix& mat)
{
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            cin >> mat.p[i][j];
        }
    }
    return input;
}
ostream& operator<<(ostream& output, const Matrix& mat)
{
    if (mat.m==0&&mat.n==0)
    {
        cout << "can’t multiply!" << endl;;
        return output;
    }
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            if (j)
            {
                cout << " ";
            }
            cout << mat.p[i][j];
        }
        cout << endl;
    }
    return output;
}
int main() 
{
    int n, m;
    while (cin >> m >> n) 
    {
        Matrix mat1(m, n);
        cin >> mat1;
        int x, y;
        cin >> x >> y;
        Matrix mat2(x, y);
        cin >> mat2;
       /* Matrix res = mat1 * mat2;
        cout << res;*/
        mat1.DiagonalOrder();
        mat1.setZeros();
        cout << mat1;
    }
    return 0;
}