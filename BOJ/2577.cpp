#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, mult;
    cin >> a >> b >> c;
    mult = a * b * c;

    string s = to_string(mult);

    int arr[10];
    fill(arr, arr + 10, 0);

    for (char num : s) {
        arr[num - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << '\n';
    }
}