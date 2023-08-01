#include "SemanticDescriptor.h"
void SemanticDescriptor::processContextWord(string s)
{
   auto it = contextWords.find(s);
    if(it == contextWords.end())
    {

        contextWords.insert({s,1});


    }
    else
    {
        it->second++;
    }
    /*for(size_t i = 0; i < contextWords.size(); i++)
    {
        if(contextWords.at(i).word == s)
        {
            contextWords.at(i).count++;
            return;

        }
    }

     contextWords.push_back(ContextWord{s, 1});
     */

}
int SemanticDescriptor::operator*(const SemanticDescriptor& desc)
{
    int sum = 0;
    for(auto thisIter = this->contextWords.begin(); thisIter != this->contextWords.end(); thisIter++)
    {

        auto descIter = desc.contextWords.find(thisIter->first);
        if(descIter != desc.contextWords.end())
        {
            sum += (thisIter->second) * (descIter->second);
        }

    }
    
   /*
    for(size_t i = 0; i < this->contextWords.size(); i++)
    {
        for(size_t j = 0; j < desc.contextWords.size(); j++)
        {
            if(this->contextWords[i].word == desc.contextWords[j].word)
            {
                sum += this->contextWords[i].count * desc.contextWords[j].count;
            }
        }
    }
    */
    return sum;
}
ostream& operator<<(ostream& os, const SemanticDescriptor& desc)
{

    os << desc.targetWord << " {";


    for(auto it = desc.contextWords.begin(); it != desc.contextWords.end(); it++)
    {

         os<< it->first << " " << it->second << " ";


    }
    /*
    for(size_t i = 0; i < desc.contextWords.size(); i++)
    {



        os<< " " << desc.contextWords[i].word << " " << desc.contextWords[i].count;
    
    }
    */

    os << "}" << endl;

    return os;
}

//part 2-----------------------------------------------------------------

istream&operator>>(istream& is, SemanticDescriptor& desc)
{
    desc.targetWord = "";
    desc.contextWords.clear();
   
    string targetWord;
    is >> targetWord;
    desc.targetWord = targetWord;
    
    char c;
    is >> c;
    if(c != '{')
    {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }
    while(is)
    {
        is >> c;
        if(c == '}') return is ;
        
        is.unget();

        string word;
        int count;
        is >> word >> count;

        //desc.contextWords.push_back(ContextWord{word,count});
        desc.contextWords.insert({word,count});

    }

   

    return is;
}
