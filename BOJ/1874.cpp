#include <bits/stdc++.h>

int n;
std::stack<int> st;
std::vector<std::string> v;

void Input() {
	std::cin >> n;
}

void Solve() {
	int num = 1;
	while (n--) {
		int target;
		std::cin >> target;

		while (num <= target) {
			st.push(num++);
			v.push_back("+");
		}

		if (st.top() != target) {
			std::cout << "NO\n";
			return;
		}
		st.pop();
		v.push_back("-");
	}

	for (auto elem : v) std::cout << elem << "\n";
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}