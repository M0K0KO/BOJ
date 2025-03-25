#include <bits/stdc++.h>

int n, m;
std::vector<std::vector<int>> s(2000);
std::vector<int> l (2000);

void Input() {
	std::cin >> n >> m;
	s.resize(n);
	l.resize(m, 0);

	for (int i = 0; i < n; i++) {
		s[i].resize(m, 0);

		int temp;
		std::cin >> temp;

		for (int j = 0; j < temp; j++) {
			int a;
			std::cin >> a;

			s[i][a - 1]++;
			l[a-1]++;
		}
	}
}

void Test(int index) {
	for (int i = 0; i < m; i++) {
		l[i] -= s[index][i];
	}
}

void Reset(int index) {
	for (int i = 0; i < m; i++) {
		l[i] += s[index][i];
	}
}

void Solve() {
	Input();
	bool flag = 0;
	for (int i = 0; i < n; i++){
		Test(i);
		bool isZero = 0;
		for (int j = 0; j < m; j++) {
			if (l[j] == 0) {
				isZero = 1;
				break;
			}
		}
		Reset(i);
		if (isZero == 0) {
			flag = 1;
			break;
		}
	}

	std::cout << flag;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Solve();
}