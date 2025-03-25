#include <bits/stdc++.h>

int N;
std::vector<int> result;

void Input() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		std::cin >> temp;
		if (std::find(result.begin(), result.end(), temp) == result.end()) {
			result.push_back(temp);
		}
	}
}

void Solve() {
	std::sort(result.begin(), result.end(), std::less<int>());

	for (auto elem : result) {
		std::cout << elem << " ";
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}