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
	for (int i = 0; i < 20; i++) {
		if(word.find(target[i]) != string::npos) {
			f = i % 10;
			break;
		}	
	}	
	for (int i = 0; i < 20; i++) {
		if (word.rfind(target[i]) != string::npos) {
			l = i % 10;
			break;
		}
	}
	cout << f << l << endl;
	sum += f * 10 + l;
    }
    //cout << sum << endl;
}
