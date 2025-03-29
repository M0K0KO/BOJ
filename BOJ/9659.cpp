#include <bits/stdc++.h>

long long N;

void Input() {
	std::cin >> N;
}

void Solve() {
	if (N % 2) std::cout << "SK";
	else std::cout << "CY";
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}