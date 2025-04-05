#include <bits/stdc++.h>

int n;
long long cnt;
std::stack<int> st;

void Input() {
	std::cin >> n;
}

void Solve() {
	while (n--) {
		long long h;
		std::cin >> h;

		while (!st.empty() && st.top() <= h) {
			st.pop();
		}
		cnt += st.size();
		st.push(h);
	}
	std::cout << cnt;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}