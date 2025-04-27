#include <bits/stdc++.h>
int T, N;
int arr[100001];
int state[100001];

void Input() {
    std::cin >> T;
}
void BFS(int startPos) {
    int cur = startPos;
    while (true) {
        state[cur] = startPos;
        cur = arr[cur];

        if (state[cur] == startPos) {
            while (state[cur] != -1) {
                state[cur] = -1;
                cur = arr[cur];
            }
            return;
        }
        else if (state[cur] != 0) return;
    }
}

void Solve() {
    while (T--) {
        int cnt = 0;
        std::cin >> N;
        std::fill(state + 1, state + N + 1, 0);
        for (int i = 1; i <= N; i++) {
            std::cin >> arr[i];
        }
        for (int i = 1; i <= N; i++) {
            if (state[i] == 0) BFS(i);
        }

        for (int i = 1; i <= N; i++) {
            if (state[i] != -1) cnt++;
        }
        std::cout << cnt << '\n';
    }
}
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    Input();
    Solve();
}