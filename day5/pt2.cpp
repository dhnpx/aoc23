#include <climits>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <tuple>

using namespace std;

void getLoc(long start, long end, vector<vector<tuple<long, long, long>>> &maps, long &min);

int main() {
    fstream file("input.txt");
    string line;
    vector<vector<tuple<long, long, long>>> maps;

    vector<long> seeds;

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
            line.erase(0, line.find(" ") + 1);
            string num2 = line.substr(0, line.find(" "));
            line.erase(0, line.find(" ") + 1);

            ranges.push_back(make_tuple(stol(num), stol(num2), stol(line)));
        }
        maps.push_back(ranges);
    }

    long locs[seeds.size() / 2];
    vector<thread> threads;

    for (int i = 0; i < seeds.size() - 2; i += 2) {
        thread t = thread(getLoc, seeds[i], seeds[i + 1], ref(maps), ref(locs[i / 2]));
        threads.push_back(move(t));
        //getLoc(seeds[i], seeds[i + 1], maps, locs[i / 2]);
    }
    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
    long min = locs[0];
    for (int i = 0; i < seeds.size() / 2; i++) {
        if (locs[i] < min) {
            min = locs[i];
        }
    }
    cout << min << endl;
}

void getLoc(long start, long end, vector<vector<tuple<long, long, long>>> &maps, long &min) {
    min = LONG_MAX;
    for (int i = 0; i < end; i++) {
        long src = start + i;
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
        if (dest < min) {
            min = dest;
        }
    }
}
