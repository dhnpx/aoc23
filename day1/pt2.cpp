#include <limits.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file;
    file.open("input.txt");
    string word;
    int sum = 0;
    string target[20] = {
	    "0",
	    "1",
	    "2",
	    "3",
	    "4",
	    "5",
	    "6",
	    "7",
	    "8",
	    "9",
	    "zero",
	    "one",
	    "two",
	    "three",
	    "four",
	    "five",
	    "six",
	    "seven",
	    "eight",
	    "nine",
    };

    while (getline (file, word)) {
	int f = 0;
	int l = 0;
	int fpos = INT_MAX;
	int lpos = INT_MIN;
	int pos;
	for (int i = 0; i < 20; i++) {
		pos = word.find(target[i]);
		if (pos != string::npos && pos < fpos) {
			f = i % 10;
			fpos = pos;
		}	
	}	
	for (int i = 0; i < 20; i++) {
		pos = word.rfind(target[i]);
		if (pos != string::npos && pos > lpos) {
			l = i % 10;
			lpos = pos;
		}
	}
	sum += f * 10 + l;
    }
    cout << sum << endl;
}
