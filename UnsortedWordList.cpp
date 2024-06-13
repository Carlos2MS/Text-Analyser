#include "UnsortedWordList.h"
#include <iostream>
using namespace std;

UnsortedWordList::UnsortedWordList(){
    length = 0;
    first =nullptr;
    last= nullptr;
    // default constructor
} 
UnsortedWordList::~UnsortedWordList(){
    DeleteAll();
    // destructor, frees memory space
} 
bool UnsortedWordList::IsEmpty() const{
    if(length == 0){
        return true;
    }
    else{
        return false;
    }
    // returns true if the list is empty, else false
}

int UnsortedWordList::Length() const{
    return length;
    // returns the number of nodes in the list
}
Node* UnsortedWordList::Front() const{
    return first;
    // returns the first node in the list
} 
Node* UnsortedWordList::Back() const{
    return last;
    // returns the last node in the list
}


bool UnsortedWordList::Contains(string word){
    Node* current = first;

    while(current != nullptr) {
        if(current->word == word){
            return true;
        } 
        current = current->next;
    }   
    return false;
    // returns true if the list contains the word <word>, else wrong
} 
Node * UnsortedWordList::FindWord(string word){
    Node* current = first;

    while(current != nullptr) {
        if(current->word == word){
            return current;
        } 
        current = current->next;
    }   
    return nullptr;
    // returns the pointer to the node with the word <word>
    // if there is no node with that word, it returns nullptr
}

string UnsortedWordList::MaxWord() const{
    int max = -999;
    string maxw;
    Node* current  = first;
    bool checker = false;

    while(current != nullptr){
        if(current->count > max){
            max = current->count;
            maxw = current->word; 
        }
        else if (current->count == max){
            checker = true;
        }

        current = current->next;
    }
    if(checker == true){
        maxw = "undefined";
    }
    return maxw;

    // if exactly one word with the highest count exists -- returns that word with the highest count
    // if multiple words exist that all have the maximum count -- returns "undefined" (without the quotes)
    // if the list is empty -- returns "undefined" (without the quotes)
}

int UnsortedWordList::MaxCount() const{
    int max = INT32_MIN;
    Node * current = first;

    while (current != nullptr){
        max = max > current->count ? max : current->count;
        current = current->next;
    }

    return max;
    // returns the highest count
} 
void UnsortedWordList::Print() const{
    cout<< "WordList("<< endl;
    cout<<"length="<< length<< endl;
    
    Node* current  = first;

    while(current != nullptr){
        cout<<"Word("<<current->word<<","<<current->count<<")"<< endl;
        current = current->next;
    }
    cout<<")"<<endl;
}
void UnsortedWordList::CountWord(string word){
    Node* current = FindWord(word);

    if (current != nullptr) {
        current->count++;
    } 
    else {
        Node* newNode = new Node(word);
        
        if (IsEmpty() == true) {
        first = newNode;
        last = newNode;
        }
        else {
        last->next = newNode;
        last = newNode;
        }

        length++;
    }

    // counts the word <word>, numReadFiles.e., searches the list to find the first node that has word <word>
    // If such a node is found -- the counter of that node incremented by 1
    // Otherwise -- adds a new node with word <word> at the end of the list
}

void UnsortedWordList::InsertFirst(string word){
    if(Contains(word) == true){
      Node* current = FindWord(word);
      current->count++;
    }
    if(Contains(word) == false){
        Node* current = new Node(word, 1);
    
        current->next = first;
        first = current;
        length++;
    }
    // If such a node is not found, creates a new node with word <word> and inserts it at the beginning of the list.
    // sets count to 1.
}

void UnsortedWordList::DeleteAll(){
    Node * current = first;
    Node* temp;
    while (current != nullptr){
        temp = current;
        delete temp;
        current = current->next;
    }

    length = 0;
    first = nullptr;
    last = nullptr;

    // deletes all nodes in the list, the UnsortedWordList object is NOT deleted/destroyed

}
void UnsortedWordList::DeleteWord(string word){
    Node * current = first;
    Node* previous = nullptr;

    while (current != nullptr){
        if(current->word == word){
            if(previous == nullptr){
                first = current->next;
            }
            else{
                previous->next = current->next;
            }
            if(current == last){
                last = previous;
            }

            delete current;
            length--;
        }

        previous = current;
        current = current->next;
    }
    // ADVANCED
    // deletes node with word <word> and updates other pointers etc
}