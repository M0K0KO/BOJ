#include <bits/stdc++.h>

int n;
std::stack<std::pair<int,int>> st;

void Input() {
	std::cin >> n;
}

void Solve() {
	st.push({ 100000001, 0 });
	for (int i = 1; i <= n; i++) {
		int h;
		std::cin >> h;
		while (st.top().first < h) {
			st.pop();
		}
		std::cout << st.top().second << " ";
		st.push({ h, i });
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}