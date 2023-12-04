#include <fstream>
#include <iostream>
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
                        if (v[h - 1][k] != '.' && !isdigit(v[h - 1][k])) {
                            sum += num;
                            break;
                        }
                    }
                }
                if (h + 1 < v.size()) {
                    for (int k = i - 1 > 0 ? i - 1 : 0; k <= j; k++) {
                        if (v[h + 1][k] != '.' && !isdigit(v[h + 1][k])) {
                            sum += num;
                            break;
                        }
                    }
                }

                if (i > 0 && v[h][i - 1] != '.' && !isdigit(v[h][i - 1])) {
                    sum += num;
                }

                if (j < v[h].length() && v[h][j] != '.' && !isdigit(v[h][j])) {
                    sum += num;
                }
                i = j;
            }
        }
    }

    cout << sum << endl;
}
