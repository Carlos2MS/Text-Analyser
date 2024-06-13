#include <iostream>
#include <list>
#include "UnsortedWordList.h"
#include "TextAnalyser.h"
using namespace std;

int main() {
    cout<<"Test 1:"<<endl;
    UnsortedWordList list;
    list.CountWord("Ultimate");
    list.CountWord("Question");
    list.CountWord("to");
    list.CountWord("Life");
    list.CountWord("Universe");
    list.CountWord("and");
    list.CountWord("Everything");
    list.CountWord("Question");
    list.Print();

    cout<<endl;
    cout<<"Test 2:"<<endl;
    TextAnalyser textAnalyser;
    UnsortedWordList list2;
    textAnalyser.ReadFile("hitchhiker.txt");
    list2 = textAnalyser.listA;
    list2.Print();
    cout << "Does the list contain 'the'? " <<   list2.Contains("the") << endl;
    cout << "Does the list contain 'them'? " << list2.Contains("them") << endl;

    cout<<endl;
    cout<<"Test 3: "<<endl;
    TextAnalyser textAnalyser2;
    textAnalyser2.ReadFile("hitchhiker.txt");
    textAnalyser2.ReadFile("rings.txt");
    textAnalyser2.Intersection();
    textAnalyser2.listC.Print();
    textAnalyser2.Union();
    textAnalyser2.listC.Print();

    return 0;
}