/**************
Author: Mark Singleton
Date: 12/12/2015
Class: COP 2224C Professor Reed
***************/
#include "Dictionary.h"
#include <iostream>
#include "Message.h"
#include <sstream>
#include <vector>
#include <set>
#include <ctype.h>
#include <algorithm>

using namespace std;

Dictionary::Dictionary()
{
    tokenDelim = " ";
}

Dictionary::~Dictionary()
{
    //dtor
}

// Re-order copy of map to descending order

template <typename T1, typename T2>
struct less_second
{
    typedef pair<T1, T2> type;
    bool operator() (type const& a, type const& b)
    {
        return a.second > b.second;
    }

};

void Dictionary::CreateNounSet(string words)
{

//Read file
    inFSNoun.open(words.c_str());

    if(!inFSNoun.is_open())
    {
        cout << "Could not open file!" << endl;
    }

    char place[60];
    while(!inFSNoun.eof() )
    {

// gets each line of file and insert into set
        getline(inFSNoun, nounFileLines);

        for(unsigned int i = 0; i < nounFileLines.size() ; i++)
        {

// Transform lines to uppercase
            place[i] = toupper(nounFileLines[i]);
            nounFileLines[i] = place[i];

        }

// Build set
        nouns.insert(nounFileLines);

    }

    inFSNoun.close();

}

void Dictionary::CreateVerbSet(string words)
{

// Read file
    inFSVerb.open(words.c_str());

    if(!inFSVerb.is_open())
    {
        cout << "Could not open file!" << endl;
    }

    char place2[60];
    while(!inFSVerb.eof() )
    {

// gets each line of file and insert into set
        getline(inFSVerb, verbFileLines);

        for(unsigned int i = 0; i < verbFileLines.size() ; i++)
        {

// Transform lines to uppercase
            place2[i] = toupper(verbFileLines[i]);
            verbFileLines[i] = place2[i];

        }

// Build set
        verbs.insert(verbFileLines);

    }

    inFSVerb.close();

}

void Dictionary::WordCount(std::vector<std::string> message)
{
    wordsCounted = 0;

//Checking line by line in message vector
    for(unsigned int i = 0; i < message.size(); i++)
    {
        next = 0;
        last = 0;
        field = 0;
        stringItem = message.at(i);

// Parse Line into Tokens
        while (( next = stringItem.find(tokenDelim, last)) != string::npos)
        {
            temp2 = stringItem.substr(last, next-last);

// Fill tokenizer
            messageTokens.push_back(temp2);
            last = next + 1;
        }

// Compare each token to Dictionary
        for(unsigned int j = 0; j < messageTokens.size(); j++)
        {
            string token = messageTokens.at(j);
            it = nouns.find(token);

            if(it != nouns.end() && !token.empty())
            {
                wordsCounted++;

            }

            it = verbs.find(token);

            if(it != verbs.end() && !token.empty())
            {
                wordsCounted++;

            }

        }

// Build Map with message and word count
        if(wordsCounted > 0)
        {
            newTmp = stringItem;
            myMap.insert(pair<string, int>(newTmp, wordsCounted));

        }

// Reset Tokenizer and word count
        wordsCounted = 0;
        messageTokens.clear();

    }

// Reorganize map
    vector<pair<string, int> > mapCopy(myMap.begin(), myMap.end());
    sort(mapCopy.begin(), mapCopy.end(), less_second<string, int>());

// Iterator for reorganized map copy
    vector< pair<string, int> >::const_iterator itersCopy;

// Print to console the final product
    for(itersCopy = mapCopy.begin(); itersCopy != mapCopy.end(); itersCopy++)
    {

        cout << "Count: " << itersCopy->second << "  Message: " << itersCopy->first << endl;

    }

}
