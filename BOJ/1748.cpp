#include <bits/stdc++.h>

int N, cnt;

void Input() {
	std::cin >> N;
}

void Solve() {
	for (int i = 1; i <= N; i *= 10) {
		cnt += N - i + 1;
	}

	std::cout << cnt;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}