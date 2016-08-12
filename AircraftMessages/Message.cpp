/**************
Author: Mark Singleton
Date: 12/12/2015
Class: COP 2224C Professor Reed
***************/

#include "Message.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

Message::Message()
{
    lineDelim = "\"";
    tokenDelim = " ";
    next = 0;
    last = 0;
    msgNum = 0;
}

Message::~Message()
{
    //dtor
}

void Message::ParseFiles(string messageFile)
{
// Read file
    inputMsg.open(messageFile.c_str());
    if(!inputMsg.is_open())
    {
        cout << "Could not open file!" << endl;
    }
    while(!inputMsg.eof() )
    {
// gets each line of file
        getline(inputMsg, singleLine);
        msgNum++;

// Parse each line and put it in a token
        next = 0;
        last = 0;
        field = 0;

        while ((next = singleLine.find(lineDelim, last)) != string::npos)
        {
            temp = singleLine.substr(last, next-last);
            if(field == 3)
            {
                messageLines.push_back(temp);
            }
            last = next + 1;
            field++;
        }

    }

    inputMsg.close();

}

vector<string> Message::GetMessageLines()
{
    return messageLines;
}

