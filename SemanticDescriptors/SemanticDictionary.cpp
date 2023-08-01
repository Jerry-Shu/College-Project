#include "SemanticDictionary.h"

vector<vector<string>> getSentenceLists(string text)
{
    vector<vector<string>> sentenceLists;
    vector<string> sentenceList;
    string word = "";

    for(size_t i = 0; i < text.size(); i++)
    {
        if(isalpha(text.at(i)))
        {
            word += tolower(text.at(i));

        }
        ///if the ith char is alphabetical, concatenate it onto word
        else
        {
        ///else
        ///  if the size of word > 0, push it back into sentenceList and make the word empty
        if(word.size() > 0)
        {
            if(!isStopWord(word)) sentenceList.push_back(word);
            word = "";
        }
        ///  if the ith char is '?', '.', or '!', AND the size of sentenceList > 0,
        ///    then push back sentenceList into sentenceLists and clear sentenceList
        if((text.at(i) == '?' || text.at(i) == '.' || text.at(i) == '!') &&  sentenceList.size() > 0)
        {
            sentenceLists.push_back(sentenceList);
            sentenceList.clear();

        }
        }
    }
    if(word.size() > 0)
    {
         if(!isStopWord(word)) sentenceList.push_back(word);
            word = "";
    }
    if(sentenceList.size() > 0)
    {
        sentenceLists.push_back(sentenceList);
    }
    ///if the size of word > 0, push it back into sentenceList
    ///if the size of sentenceList > 0, push it back into sentenceLists
    return sentenceLists;
}


ostream& operator<<(ostream& os, const vector<vector<string>>& sentenceLists)
{

    os << "Sentence Lists:" << endl;
    os << "[" << endl;
    for(size_t i = 0; i < sentenceLists.size(); i++)
    {

        os << "[";
        for(size_t j = 0; j < sentenceLists[i].size(); j++)
        {
          os << sentenceLists[i][j]  << " ";
        }
        os << "]" << endl;


    }
    os << "]" << endl;
    return os;

}
/*
int SemanticDictionary::searchTargetWord(string targetWord)
{
    for(size_t i = 0; i < semanticDescriptors.size(); i++)
    {

        if(targetWord == semanticDescriptors[i].getTargetWord())
        {
            return i;
        }
    }
    return -1;


}
*/
void SemanticDictionary::processTargetWord(string targetWord, vector<string> sentenceList)
{
    auto it = semanticDescriptors.find(targetWord);
     if(it == semanticDescriptors.end())
     {
         it = (semanticDescriptors.insert({targetWord, SemanticDescriptor {targetWord}})).first;
     }

    for(size_t i = 0; i < sentenceList.size(); i++)
    {
        if(sentenceList[i] != targetWord)
        {
           it->second.processContextWord(sentenceList[i]);
        }
    }
    /*
    int i = searchTargetWord(targetWord);
    if(i == -1)
    {
        semanticDescriptors.push_back(SemanticDescriptor(targetWord));
        i = semanticDescriptors.size() - 1;

    }

    for(size_t j = 0; j < sentenceList.size(); j++)
    {
        if(sentenceList[j] != targetWord)
        {
           semanticDescriptors[i].processContextWord(sentenceList[j]);
        }
    }
    */
}
ostream& operator<<(ostream& os, const SemanticDictionary& d)
{

    os << "Semantic Descriptors:" << endl;
    os << "{" << endl;
    /*
    for(size_t i = 0; i < d.semanticDescriptors.size(); i++)
    {

        os << d.semanticDescriptors[i] << endl;

    }
    */
   for(auto it = d.semanticDescriptors.begin(); it != d.semanticDescriptors.end(); it++)
   {
       os << it->second << endl;
   }
        os << "}" << endl;
    return os;

}

double  SemanticDictionary::getSimilarity(string targetWord1, string targetWord2)
{
    //int indices1;
   // int indices2;
    //indices1 = searchTargetWord(targetWord1);
   // indices2 = searchTargetWord(targetWord2);
  auto it1 = semanticDescriptors.find(targetWord1);
  auto it2 = semanticDescriptors.find(targetWord2);

    //if(indices1 == -1 || indices2 == -1) throw runtime_error ("Target word(s) unknown");
    if(it1 == semanticDescriptors.end() || it2 == semanticDescriptors.end()) throw runtime_error ("Target word(s) unknown");
   // SemanticDescriptor a = semanticDescriptors[indices1];
   // SemanticDescriptor b = semanticDescriptors[indices2];
    SemanticDescriptor a = it1->second;
    SemanticDescriptor b = it2->second;
    return (a * b * 1.0) / (sqrt(a*a) * sqrt(b*b));


}
string SemanticDictionary::mostSimilarWord(string word, vector<string> choices)
{
    double bestScore = getSimilarity(word, choices.at(0));
    size_t bestIndex = 0;
    for(size_t i = 0; i < choices.size(); i++)
    {
        double score = getSimilarity(word, choices.at(i));
        if(score > bestScore)
        {
            bestScore = score;
            bestIndex = i;
        }

    }

    return choices.at(bestIndex);



}



bool isStopWord(string s)
{

    auto it = stopWords.find(s); // same as set<string>::iterator it = stopWords.find(s); 
    if(it == stopWords.end()) return false;
    return true;
    /*
   for(string word : stopWordList)
   {
       if(s == word) return true;
   }
   

   return false;
   */

}

istream& operator>>(istream& is, SemanticDictionary& d)
 {
     d.semanticDescriptors.clear();
     SemanticDescriptor desc{""};

    char c;

    while(is >> c)
    {
        if(c == '{') break;
    }
    if(is.fail()) return is;
     
    while(is >> desc)
    {
        //d.semanticDescriptors.push_back(desc);
        d.semanticDescriptors.insert({desc.getTargetWord(), desc});

    }

    is.clear();
    is >> c;
    if(c != '}') 
    {
        is.clear(ios::failbit);
    }

    return is;

   
 }