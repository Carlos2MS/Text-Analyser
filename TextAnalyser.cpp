#include "TextAnalyser.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void TextAnalyser::ReadFile(string filename) {
    cout << "TextAnalyser::ReadFile, filename='" << filename << "'." << endl;

    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "unable to open file with filename='" << filename << "'." << endl;
        return;
    }
    
    string word;
    UnsortedWordList* currentList = readIntoA ? &listA : &listB;

    while (file >> word) {
// TODO replace with code that handles each word
    currentList->CountWord(word);
    }
// TODO if necessary add code here
    readIntoA = !readIntoA;
    // at the beginning prints a diagnostic message of the form
    // TextAnalyser::ReadFile, filename='<name of the file>'
    //
    // reads in a file and puts the words in listA or listB
    //
    // alternates readIntoA between true and false to control which list is used
}

void TextAnalyser::Intersection(){
    listC.DeleteAll();
    Node* currentA = listA.Front();

    while (currentA != nullptr) {
        if (listB.Contains(currentA->word)) {
            int countA = currentA->count;
            int countB = (listB.FindWord(currentA->word))->count;

            int minCount;
            if (countA < countB) {
                minCount = countA;
            }
            else {
                minCount = countB;
            }

            for (int i = 0; i < minCount; i++) {
                listC.CountWord(currentA->word);
            }
        }
        currentA = currentA->next;
    }
    // determines intersection of A and B, i.e.
    // it puts all words that appear in listA *and* listB in listC
    // for each word it takes the minimum of word counts in A and B for C
}

void TextAnalyser::Union(){
    listC.DeleteAll();
    Node* currentA = listA.Front();
    Node* currentB = listB.Front();

    while (currentA != nullptr) {
        int countA = currentA->count;
        for (int i = 0; i < countA; i++) {
            listC.CountWord(currentA->word);
        }
        currentA = currentA->next;
    }

    while (currentB != nullptr) {
        int countB = currentB->count;
        for (int i = 0; i < countB; i++) {
            listC.CountWord(currentB->word);
        }
        currentB = currentB->next;
    }
    // determines union of A and B, i.e.
    // it puts all words that appear in listA *or* listB in listC
    // for each word it takes the sum of word counts in A and B (not the maximum!) for C
    // i.e., it has the same result as reading both files that were source for A and B    
}
    