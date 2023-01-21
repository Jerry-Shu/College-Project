#include "Matrices.h"

namespace Matrices
{

Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;

    a.resize(_rows, vector<double>(_cols,0));
    /*
    for(int i = 0; i < _rows; i++)
    {
        a.at(i).resize(_cols, 0);
    }
    */

}



///Add each corresponding element.
///usage:  c = a + b;
Matrix operator+(const Matrix& a, const Matrix& b)
{
    if(a.getRows() != b.getRows() || a.getCols() != b.getCols())   error("Doesn't match");
    Matrix c(a.getRows(),b.getCols());
    for(int i = 0; i < a.getRows(); i++)
    {
        for(int j = 0; j < b.getCols(); j++)
        {
            c(i,j) = a(i,j) + b(i,j);

        }
    }
    return c;
}

///Matrix multiply.  See description.
///usage:  c = a * b;
Matrix operator*(const Matrix& a, const Matrix& b)
{
    if(b.getRows() != a.getCols()) error("rows!=clos");
    double sum = 0;
    Matrix c(a.getRows(), b.getCols());

    for(int k = 0; k < b.getCols(); k++)
    {
        for(int i = 0; i < a.getRows(); i++)
        {
            for(int j = 0; j < a.getCols(); j++)
            {

                //cout << "sum +=" << "a(" << i << "," << j << ") " <<a(i,j)  << " + " << "b(" << j << "," << k <<")" <<b(j,k) << "= " << a(i,j) * b(j,k) << endl;
                sum += a(i,j) * b(j,k);

            }
            //cout << "sum final = " << sum << endl;
            //cout << "c(" << i << "," << k << ") = " << sum << endl;
           c(i,k) = sum;
           sum = 0;
        }
    }

    return c;

}

///Matrix comparison.  See description.
///usage:  a == b
bool operator==(const Matrix& a, const Matrix& b)
{
    if(a.getRows() != b.getRows() || a.getCols() != b.getCols())  return false;

    for(int i = 0; i < a.getRows(); i++)
    {
        for(int j = 0; j < b.getCols(); j++)
        {
            if( fabs(a(i,j) - b(i,j)) > 0.001)
            {
                return false;
            }

        }
    }
    return true;

}

///Matrix comparison.  See description.
///usage:  a != b
bool operator!=(const Matrix& a, const Matrix& b)
{
    return(!(a == b));
}

///Output matrix.
///Separate columns by ' ' and rows by '\n'
ostream& operator<<(ostream& os, const Matrix& a)
{

    for(int i = 0; i < a.getRows(); i++)
    {

        for(int j = 0; j < a.getCols(); j++)
        {

            os << setw(10) << a(i,j);

        }
        os << endl;

    }

    return os;

}








































}
