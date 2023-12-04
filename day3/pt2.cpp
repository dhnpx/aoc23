#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    fstream file;
    file.open("input.txt");

    vector<string> v;
    int sum = 0;
    string line;
    while (getline(file, line)) {
        v.push_back(line);
    }

    map<pair<int, int>, vector<int>> map;

    for (int h = 0; h < v.size(); h++) {
        for (int i = 0; i < v[h].size(); i++) {
            int num = 0;
            if (isdigit(v[h][i])) {
                int j = i;
                while (isdigit(v[h][j])) {
                    num = num * 10 + (v[h][j] - '0');
                    if (j + 1 < v.size()) {
                        j++;
                    } else {
                        break;
                    }
                }
                if (h > 0) {
                    for (int k = i - 1 > 0 ? i - 1 : 0; k <= j; k++) {
                        if (v[h - 1][k] == '*') {
                            if (map.find(make_pair(h - 1, k)) == map.end()) {
                                map.insert({make_pair(h - 1, k), {num}});
                            } else {
                                map[make_pair(h - 1, k)].push_back(num);
                            }
                        }
                    }
                }
                if (h + 1 < v.size()) {
                    for (int k = i - 1 > 0 ? i - 1 : 0; k <= j; k++) {
                        if (v[h + 1][k] == '*') {
                            if (map.find(make_pair(h + 1, k)) == map.end()) {
                                map.insert({make_pair(h + 1, k), {num}});
                            } else {
                                map[make_pair(h + 1, k)].push_back(num);
                            }
                        }
                    }
                }

                if (i > 0 && v[h][i - 1] == '*') {
                    if (map.find(make_pair(h, i - 1)) == map.end()) {
                        map.insert({make_pair(h, i - 1), {num}});
                    } else {
                        map[make_pair(h, i - 1)].push_back(num);
                    }
                }

                if (j < v[h].length() && v[h][j] == '*') {
                    if (map.find(make_pair(h, j)) == map.end()) {
                        map.insert({make_pair(h, j), {num}});
                    } else {
                        map[make_pair(h, j)].push_back(num);
                    }
                }
                i = j;
            }
        }
    }

    for (auto i = map.begin(); i!= map.end(); i++) {
        if (i->second.size() == 2) {
            sum += i->second[0] * i->second[1];
        }
    }

    cout << sum << endl;
}
