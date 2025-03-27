#include <bits/stdc++.h>

int n;
int temp;
long long koong[68];

void Input() {
	std::cin >> n;
	koong[0] = 1;
	koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;
}

void Solve() {
	for (int i = 4; i < 68; i++) {
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
	}

	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		std::cout << koong[temp] << "\n";
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}