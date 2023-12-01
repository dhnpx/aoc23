#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    file.open("input.txt");
    string word;
    int sum = 0;

    while (getline (file, word)) {
        int f = -1;
        int l = -1;
        for (char c : word) {
            if (isdigit(c)) {
                if ( f == -1) {
                    f = c - '0';
                    l = c - '0';
                } else {
                    l = c - '0';
                }
            }
        }
        sum += (10 * f) + l;
    }
    cout << sum << endl;
}
