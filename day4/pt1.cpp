#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    fstream file;
    file.open("input.txt");
    string line;
    vector<int> wNums;
    int sum = 0;

    while (getline(file, line)) {
        int count = 0;
        int pos = line.find(":");
        line.erase(0, pos + 2);
        pos = line.find("|");
        string nums = line.substr(0, pos - 1);
        line.erase(0, pos + 2);
        string str;
        stringstream ss(nums);
        while (getline(ss, str, ' ')) {
            if (str == "") {
                continue;
            }
            wNums.push_back(stoi(str));
        }
        stringstream ss2(line);
        while (getline(ss2, str, ' ')) {
            if (str == "") {
                continue;
            }
            if (find(wNums.begin(), wNums.end(), stoi(str)) != wNums.end()) {
                count++;
            }
        }
        if (count > 0) {
            sum += pow(2, count - 1);
        }
        wNums.clear();
    }
    cout << sum << endl;
}
