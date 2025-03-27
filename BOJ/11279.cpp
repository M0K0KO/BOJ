#include <bits/stdc++.h>

int n, x;
std::vector<int> result;
std::priority_queue<int> q;

void Input() {
	std::cin >> n;
}

void Solve() {

	for (int i = 0; i < n; i++) {
		std::cin >> x;

		if (x != 0) {
			q.push(x);
		}
		else {
			if (q.empty()) result.push_back(0);
			else {
				result.push_back(q.top());
				q.pop();
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << '\n';
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}