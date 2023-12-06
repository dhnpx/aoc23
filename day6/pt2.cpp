#include <iostream>

using namespace std;

int main() {
    int time = 58819676;
    long distance = 434104122191218;
    long count = 0;

    for (int i = 1; i < time; i++) {
        if (distance / (time - i) < i) {
            count++;
        }
    }

    cout << count << endl;
}
