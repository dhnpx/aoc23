#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    fstream file;
    file.open("input.txt");
    int r = 12;
    int g = 13;
    int b = 14;
    string line;
    int sum = 0;

    while (getline(file, line)) {
        bool skip = false;
        string delimeter = ":";
        string game = line.substr(0, line.find(delimeter));
        line.erase(0, line.find(delimeter) + delimeter.length() + 1);
        game.erase(0, 5);

        vector<string> sets;
        stringstream ss(line);
        string str;
        while (getline(ss, str, ';')) {
            sets.push_back(str);
        }

        for (int i = 0; i < sets.size(); i++) {
            int red = -1;
            int green = -1;
            int blue = -1;
            vector<string> colors;
            stringstream ss1(sets[i]);
            string tmpStr;

            while (getline(ss1, tmpStr, ',')) {
                colors.push_back(tmpStr);
            }

            for (int j = 0; j < colors.size(); j++) {
                if (colors[j].find("red") != string::npos) {
                    sscanf(colors[j].c_str(), "%d red", &red);
                }
                if (colors[j].find("green") != string::npos) {
                    sscanf(colors[j].c_str(), "%d green", &green);
                }
                if (colors[j].find("blue") != string::npos) {
                    sscanf(colors[j].c_str(), "%d blue", &blue);
                }
            }

            if (red > r || green > g || blue > b) {
                skip = true;
                break;
            }
        }
        if (!skip) {
            sum += stoi(game);
        }
    }

    cout << sum << endl;
}
