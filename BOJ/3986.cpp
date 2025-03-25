#include <bits/stdc++.h>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	int sum = 0;

	for (int i = 0; i < n; i++) {
		std::string temp;
		std::cin >> temp;

		std::stack<char> st;

		if (temp.size() % 2 == 1) continue;

		for (char c : temp) {
			if (!st.empty() && st.top() == c) st.pop();
			else st.push(c);
		}

		if (st.empty()) sum += 1;
	}

	std::cout << sum;
}