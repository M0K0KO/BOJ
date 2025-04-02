#include <bits/stdc++.h>

std::string str;
int M;

void Input() {
	std::cin >> str >> M;
}

void Solve() {
	std::list<char> lst(str.begin(), str.end());
	std::list<char>::iterator it = lst.end();
	
	while (M--) {
		char op;
		std::cin >> op;

		if (op == 'P') {
			char add;
			std::cin >> add;
			lst.insert(it, add);
		}
		else if (op == 'L') {
			if (it != lst.begin()) it--;
		}
		else if (op == 'D') {
			if (it != lst.end()) it++;
		}
		else {
			if (it != lst.begin()) {
				it--;
				it = lst.erase(it);
			}
		}
	}

	for (auto elem : lst) std::cout << elem;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}