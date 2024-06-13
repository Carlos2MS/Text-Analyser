#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string newWord){
    word= newWord;
    count = 1;
    next = nullptr;
     // constructor with word
}
   
Node::Node(string newWord, int newCount){

    word= newWord;
    count= newCount;
    next = nullptr;
     // constructor with word and count
}
