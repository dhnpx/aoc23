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
    string line;
    int sum = 0;

    while (getline(file, line)) {
        vector<string> sets;
        stringstream ss(line);
        string str;
        int maxRed = 0;
        int maxGreen = 0;
        int maxBlue = 0;

        getline(ss, str, ':');
        while (getline(ss, str, ';')) {
            sets.push_back(str);
        }

        for (int i = 0; i < sets.size(); i++) {
            int red = -1;
            int green = -1;
            int blue = -1;
            vector<string> colors;
            stringstream ss(sets[i]);
            string str;

            while (getline(ss, str, ',')) {
                colors.push_back(str);
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

            if (red > maxRed) {
                maxRed = red;
            }
            if (green > maxGreen) {
                maxGreen = green;
            }
            if (blue > maxBlue) {
                maxBlue = blue;
            }

        }

        sum += maxRed * maxGreen * maxBlue;
    }

    cout << sum << endl;
}
