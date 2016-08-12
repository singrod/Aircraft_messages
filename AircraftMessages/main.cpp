/**************
Author:
Mark Singleton
Date: 12/12/2015
Class:
COP 2224C Professor Reed
***************/

#include <iostream>
#include "Dictionary.h"
#include "Message.h"

using namespace std;

int main()
{
    Dictionary* myObject = new Dictionary();
    myObject->CreateNounSet("noun.txt");
    myObject->CreateVerbSet("verb.txt");

    Message* myMessage = new Message();
    myMessage->ParseFiles("acars_msgs1.txt");

    myObject->WordCount(myMessage->GetMessageLines());

    return 0;

}
