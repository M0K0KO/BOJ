#include <bits/stdc++.h>

int N;
std::string str;
std::stack<char> st;

void Input() {
	std::cin >> N;
}

void Solve() {
	while (N--) {
		std::cin >> str;
		for (auto elem : str) {
			if (elem == '(') st.push(elem);
			else {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					st.push(elem);
				}
			}
		}

		if (st.empty()) std::cout << "YES" << '\n';
		else
		{
			std::cout << "NO" << '\n';
			while (!st.empty()) st.pop();
		}
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}