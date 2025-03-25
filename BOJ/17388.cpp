#include <iostream>

using namespace std;

int main() {
    int S, K, H;
    cin >> S >> K >> H;

    int sum = S + K + H;

    if (sum >= 100) {
        cout << "OK" << endl;
    }
    else {
        if (S < K && S < H) {
            cout << "Soongsil" << endl;
        }
        else if (K < S && K < H) {
            cout << "Korea" << endl;
        }
        else {
            cout << "Hanyang" << endl;
        }
    }
}
