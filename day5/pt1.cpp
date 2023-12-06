#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    fstream file("input.txt");
    string line;
    vector<vector<tuple<long, long, long>>> maps;

    vector<long> seeds;
    vector<long> locs;

    getline(file, line);
    line.erase(0, line.find(":") + 2);
    while (line.find(" ") != string::npos) {
        seeds.push_back(stol(line.substr(0, line.find(" "))));
        line.erase(0, line.find(" ") + 1);
    }
    seeds.push_back(stol(line));
    line.erase(0, line.end() - line.begin());

    while (!file.eof() && getline(file, line)) {
        getline(file, line);
        line.erase(0, line.find(":") + 2);
        vector<tuple<long, long, long>> ranges;
        while (getline(file, line) && line != "") {
            string num = line.substr(0, line.find(" "));
            line.erase(0,line.find(" ") + 1);
            string num2 = line.substr(0, line.find(" "));
            line.erase(0, line.find(" ") + 1);

            ranges.push_back(make_tuple(stol(num), stol(num2), stol(line)));
        }
        maps.push_back(ranges);
    }

    for (int i = 0; i < seeds.size(); i++) {
        long src = seeds[i];
        long dest = src;

        for (int j = 0; j < maps.size(); j++) {
            src = dest;
            for (int k = 0; k < maps[j].size(); k++) {
                long diff = src - get<1>(maps[j][k]);
                if (diff < get<2>(maps[j][k]) && diff >= 0) { 
                    dest = get<0>(maps[j][k]) + diff;
                    break;
                }
            }
        }
        locs.push_back(dest);
    }
    
    long min = locs[0];
    for (int i = 0; i < locs.size(); i++) {
        if (locs[i] < min) {
            min = locs[i];
        }
    }

    cout << min << endl;
}
