#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, v;
    cin >> N;
    int* arr = new int [N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> v;

    int cnt = 0;

    for (auto i = arr; i < arr + N; i++) {
        if (*i == v) cnt++;
    }

    cout << cnt;

}