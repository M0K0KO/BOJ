#include <bits/stdc++.h>

int N;
std::vector<int> v1;
std::vector<int> v2;

int sum;

void Input() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		std::cin >> temp;
		v1.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		int temp;
		std::cin >> temp;
		v2.push_back(temp);
	}
}

void Solve() {
	std::sort(v1.begin(), v1.end(), std::greater<int>());
	std::sort(v2.begin(), v2.end(), std::less<int>());

	for (int i = 0; i < N; i++) {
		sum += v1[i] * v2[i];
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();

	std::cout << sum;
}