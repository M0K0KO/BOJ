#include <bits/stdc++.h>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int N;
	std::cin >> N;

	std::vector<std::pair<char, int>> result;

	for (int i = 0; i < N; i++) {
		std::string temp;
		int n, d;

		std::cin >> temp >> n >> d;
		result.push_back(std::make_pair(std::toupper(temp[d-1]), n));
	}

	std::sort(result.begin(), result.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b){ return a.second < b.second; });

	for (auto elem : result) {
		std::cout << elem.first;
	}
}