#ifndef SEMANTICDESCRIPTOR_H_INCLUDED
#define SEMANTICDESCRIPTOR_H_INCLUDED
//#include <vector>
#include<map>
#include <iostream>
#include <cmath>
#include"std_lib_facilities.h"
using namespace std;

/*
struct ContextWord
{
    string word;
    int count;
};
*/

class SemanticDescriptor
{
    private:

        string targetWord;
        map<string, int> contextWords;

    public:  
        SemanticDescriptor(string _targetWord) : targetWord(_targetWord) {}
        string getTargetWord() {return targetWord;}
        void processContextWord(string s);
        int operator*(const SemanticDescriptor& desc);
        friend ostream& operator<<(ostream& os, const SemanticDescriptor& desc);
        //part 2----------------------------------------------------------------
       friend istream& operator>>(istream& is, SemanticDescriptor& desc); 
        //---------------------------------------------------------------------
};

#endif // SEMANTICDESCRIPTOR_H_INCLUDED
