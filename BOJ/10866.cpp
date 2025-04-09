#include <bits/stdc++.h>

int N;
std::deque<int> q;

void Input() {
	std::cin >> N;
}

void Solve() {

	while (N--) {
		std::string s;
		std::cin >> s;

		if (s == "push_front") {
			int t;
			std::cin >> t;
			q.push_front(t);
		}
		else if (s == "push_back") {
			int t;
			std::cin >> t;
			q.push_back(t);
		}
		else if (s == "pop_front") {
			if (!q.empty())
			{
				std::cout << q.front() << '\n';
				q.pop_front();
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		else if (s == "pop_back") {
			if (!q.empty()) {
				std::cout << q.back() << '\n';
				q.pop_back();
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		else if (s == "size") {
			std::cout << q.size() << '\n';
		}
		else if (s == "empty") {
			if (q.empty()) std::cout << 1 << '\n';
			else std::cout << 0 << '\n';
		}
		else if (s == "front") {
			if (!q.empty()) {
				std::cout << q.front() << '\n';
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		else if (s == "back") {
			if (!q.empty()) {
				std::cout << q.back() << '\n';
			}
			else {
				std::cout << -1 << '\n';
			}
		}

	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}