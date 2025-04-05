#include <bits/stdc++.h>

int N;
std::queue<int> q;

void Input() {
	std::cin >> N;
}

void Solve() {
	while (N--) {
		std::string c;
		std::cin >> c;
		if (c == "push") {
			int temp;
			std::cin >> temp;
			q.push(temp);
		}
		else if (c == "pop") {
			if (!q.empty()) {
				std::cout << q.front() << '\n';
				q.pop();
			}
			else std::cout << -1 << '\n';
		}
		else if (c == "size") {
			std::cout << q.size() << '\n';
		}
		else if (c == "empty") {
			if (q.empty()) std::cout << 1 << '\n';
			else std::cout << 0 << '\n';
		}
		else if (c == "front") {
			if (!q.empty()) std::cout << q.front() << '\n';
			else std::cout << -1 << '\n';
		}
		else if (c == "back") {
			if (!q.empty()) std::cout << q.back() << '\n';
			else std::cout << -1 << '\n';
		}
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}