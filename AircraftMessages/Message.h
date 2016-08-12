/**************
Author: Mark Singleton
Date: 12/12/2015
Class: COP 2224C Professor Reed
***************/

#ifndef MESSAGE_H
#define MESSAGE_H
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>

class Message
{
public:
    Message();
    virtual ~Message();
    void ParseFiles(std::string messageFile);
    std::vector<std::string>GetMessageLines();
private:
    int field;
    std::string temp;
    int msgNum;
    std::ifstream inputMsg;
    std::string singleLine;
    std::string lineDelim;
    std::string tokenDelim;
    size_t next;
    size_t last;
    std::vector<std::string> messageLines;
    std::vector<std::string> messageToken;
};

#endif // MESSAGE_H
