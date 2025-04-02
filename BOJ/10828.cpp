#include <bits/stdc++.h>

int st[100001];
int pos = 1;
int N;

void Input() {
	std::cin >> N;
}

void Solve() {
	for (int i = 0; i < N; i++) {
		std::string c;
		std::cin >> c;
		if (c == "push") {
			int val;
			std::cin >> val;
			st[pos++] = val;
		}
		else if (c == "pop") {
			if (pos != 1) {
				std::cout << st[pos - 1] << '\n';
				pos--;
			}
			else std::cout << -1 << '\n';
		}
		else if (c == "top") {
			if (pos != 1) std::cout << st[pos - 1] << '\n';
			else std::cout << -1 << '\n';
		}
		else if (c == "size") {
			std::cout << pos - 1 << '\n';
		}
		else if (c == "empty") {
			if (pos == 1) std::cout << 1 << '\n';
			else std::cout << 0 << '\n';
		}
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}