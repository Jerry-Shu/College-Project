#include "../std_lib_facilities.h"
#include "M01.h"
using namespace std;


int main()
{
    double operands1;
    double operands2;
    string operation;
    double result;
    cin >> operation;
    cin >> operands1 >> operands2;
    if(operation == "+")
    {

       result = addition(operands1,operands2);
        

    }
    else if(operation == "-")
    {
        
        result = subtraction (operands1, operands2);
        
    }
    else if(operation == "*")
    {
        
        result = multiplication (operands1, operands2);
        
    }
    else if(operation == "/" && operands2 != 0)
    {

        result = division (operands1, operands2);
        
    }
    else
    {

        return 0;
    
    }
    
    cout << "= " << result;
    cout << endl;






    return 0;
}
