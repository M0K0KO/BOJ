#include <bits/stdc++.h>

std::string S;
int size;
std::vector<std::string> v;

void Input() {
	std::cin >> S;
	size = S.size();
}

void Solve() {
	v.push_back(S);
	for (int i = 0; i < size - 1; i++) {
		S.erase(0, 1);
		v.push_back(S);
	}

	std::sort(v.begin(), v.end(), std::less<std::string>());

	for (auto elem : v) {
		std::cout << elem << "\n";
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}