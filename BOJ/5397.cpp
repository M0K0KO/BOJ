#include <bits/stdc++.h>

std::string str;
int N;

void Input() {
	std::cin >> N;
}

void Solve() {
	while (N--) {
		std::cin >> str;
		std::vector<char> v(str.begin(), str.end());
		std::list<char> lst;
		std::list<char>::iterator cursor = lst.begin();

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == '<') {
				if (cursor != lst.begin()) cursor--;
			}
			else if (v[i] == '>') {
				if (cursor != lst.end()) cursor++;
			}
			else if (v[i] == '-') {
				if (cursor != lst.begin()) {
					cursor--;
					cursor = lst.erase(cursor);
				}
			}
			else {
				lst.insert(cursor, v[i]);
			}
		}

		for (auto elem : lst) std::cout << elem;
		std::cout << '\n';
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}