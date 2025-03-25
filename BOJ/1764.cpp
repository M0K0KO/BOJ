#include <bits/stdc++.h>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n, m;
	std::cin >> n >> m;

	std::set<std::string> a;
	std::set<std::string> b;

	for (int i = 0; i < n; i++) {
		std::string temp;
		std::cin >> temp;
		a.insert(temp);
	}

	for (int i = 0; i < m; i++) {
		std::string temp;
		std::cin >> temp;
		b.insert(temp);
	}

	std::vector<std::string> result;
	result.resize(a.size() + b.size());
	auto it = std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), result.begin());
	result.erase(it, result.end());

	std::cout << result.size() << '\n';
	for (auto elem : result) std::cout << elem << '\n';
}