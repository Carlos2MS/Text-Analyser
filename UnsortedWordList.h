#ifndef A05_UNSORTEDWORDLIST_H
#define A05_UNSORTEDWORDLIST_H
#include "Node.h"

class UnsortedWordList {
public:
    UnsortedWordList();
    ~UnsortedWordList();
    bool IsEmpty() const;
    int Length() const; 
    Node *Front() const; 
    Node *Back() const; 
    bool Contains(string word); 
    Node * FindWord(string word);
    string MaxWord() const;
    int MaxCount() const;
    void Print() const;
    void CountWord(string word);
    void InsertFirst(string word);
    void DeleteAll();
    void DeleteWord(string word);
protected:
    int length; // number of nodes in the list
    Node *first; // pointer to first node in the list
    Node *last; // pointer to last node in the list
// if there is only one Node in the list --> first and last point to the same Node
// if the list is empty --> first and last are set to nullptr
};

#endif //A05_UNSORTEDWORDLIST_H