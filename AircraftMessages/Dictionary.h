/**************
Author: Mark Singleton
Date: 12/12/2015
Class: COP 2224C Professor Reed
***************/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>

class Dictionary
{
public:
    Dictionary();
    virtual ~Dictionary();
    void CreateNounSet(std::string words);
    void CreateVerbSet(std::string words);
    void WordCount(std::vector<std::string> message);
private:
    std::string temp2;
    std::string newTmp;
    std::set<std::string>::iterator it;
    int wordsCounted;
    unsigned int next;
    unsigned int last;
    int field;
    std::string stringItem;
    std::string tokenDelim;
    std::ifstream inFSNoun;
    std::string nounFileLines;
    std::ifstream inFSVerb;
    std::string verbFileLines;
    std::set<std::string> nouns;
    std::set<std::string> verbs;
    std::vector<std::string> messageTokens;
    std::map<std::string, int> myMap;
    std::map<std::string, int>::const_iterator iters;

};

#endif // DICTIONARY_H
