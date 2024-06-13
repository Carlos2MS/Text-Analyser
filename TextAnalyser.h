#ifndef A05_TEXTANALYSER_H
#define A05_TEXTANALYSER_H
#include "UnsortedWordList.h"
#include <string>
using namespace std;

class TextAnalyser {
private:
    bool readIntoA = true; // determines whether ReadFile() stores the input into listA or listB
// is flipped during each ReadFile(), so ReadFile() operations alternate between A and B.
public:
    UnsortedWordList listA; // stores words read in each odd attempt (1st, 3rd, 5th, ...)
    UnsortedWordList listB; // stores words read in each even attempt (2nd, 4th, 6th, ...)
    UnsortedWordList listC; // stores result of Intersection() and Union()
    void ReadFile(string filename);
    void Intersection();
    void Union();
};

#endif //A05_TEXTANALYSER_H