#include <iostream>

using namespace std;

int main() {
    int time[4] = { 58, 81, 96, 76 };
    int distance[4] = { 434, 1041, 2219, 1218 };
    int count[4] = {};

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < time[i]; j++) {
            int d = (time[i] - j) * j;
            if ( d > distance[i]) {
                count[i] += 1;
            }
        }
    }

    long mult = 1;
    for (int i = 0; i < 4; i++) {
        mult *= count[i];
    }

    cout << mult << endl;
}
