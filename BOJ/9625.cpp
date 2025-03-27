#include <bits/stdc++.h>

int k;
int A = 1;
int B = 0;

void Input() {
	std::cin >> k;
}

void Solve() {
	for (int i = 0; i < k; i++) {
		int AVal = A;
		A = B;
		B += AVal;
	}

	std::cout << A << " " << B;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}