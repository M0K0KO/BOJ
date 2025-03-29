#include <bits/stdc++.h>

std::string str;
std::string test[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

void Input() {
	std::cin >> str;
}

void Solve() {
	for (int i = 0; i < 8; i++) {
		while (true) {
			if (str.find(test[i]) != std::string::npos) {
				str.replace(str.find(test[i]), test[i].length(), "#");
			}
			else break;
		}
	}

	std::cout << str.length();
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}