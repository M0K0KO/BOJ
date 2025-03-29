#include <bits/stdc++.h>

long long n, a, b;


int GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}

void Input() {
	std::cin >> n;
}

void Solve() {
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b;
		int temp = GCD(a, b);
		std::cout << temp * (a / temp) * (b / temp) << "\n";
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}