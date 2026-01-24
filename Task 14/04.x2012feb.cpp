#include <iostream>
#include <array>
using namespace std;

const int MAXPAL = 50;

struct TWord {
    string word = "";
    int distance = 0;
    int lastPos = -1;
};

typedef array<TWord, MAXPAL> TVec;

struct TOpenArr {
    int size = 0;
    TVec words;
};

int main () {
    void add(TOpenArr &a, string word, int counter);

    int counter = 0;
    TOpenArr res;

    string input;
    cout << "Start introducing words (write \"end\" to end): ";
    while((cin >> input) and (input != "end")) {
        add(res, input, counter);
        counter++;
    }

    for(int i = 0; i < res.size; i++) {
        TWord e = res.words[i];
        if(e.distance > 0) cout << e.word << ": " << e.distance << endl;
    }
    return 0;

}

void add(TOpenArr &a, string word, int counter) {
    int wordVecPos(TOpenArr a, string word);
    /**
     * 2 cases: Either it is already registered or it is not
     * If it is registered, we redefine the distance if and only if the distance is greater. Update last pos
     * If it is not registered, we actualize last pos and word
     */
    int vecpos = wordVecPos(a, word);
    if(vecpos == -1) { // It is not registered
        a.words[a.size].word = word;
        a.words[a.size].lastPos = counter;
        a.size++;
    } else {
        if(a.words[vecpos].distance < (counter - a.words[vecpos].lastPos)) {
            a.words[vecpos].distance = (counter - a.words[vecpos].lastPos);
        }
        a.words[vecpos].lastPos = counter;
    }
}

int wordVecPos(TOpenArr a, string word) {
    /**
     * Returns the position of a word in the open array
     * If no word is found inside the open array, returns -1
     */
    int i = 0;
    while((i < (a.size - 1)) and (a.words[i].word != word)) i++;
    return((a.words[i].word != word)?-1:i);
}