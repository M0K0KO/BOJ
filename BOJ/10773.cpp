#include <bits/stdc++.h>

int K;
std::stack<int> st;

void Input() {
	std::cin >> K;
}

void Solve() {
	for (int i = 0; i < K; i++) {
		int c;
		std::cin >> c;
		if (c) st.push(c);
		else st.pop();
	}

	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	std::cout << sum;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}