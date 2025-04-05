#include <bits/stdc++.h>

int N;
std::queue<int> q;

void Input() {
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
}

void Solve() {
	while (q.size() != 1) {
		q.pop();
		int target = q.front();
		q.pop();
		q.push(target);
	}

	std::cout << q.front();
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}