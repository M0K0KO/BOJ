#include <bits/stdc++.h>

int n;
std::vector<std::string> v;

void Input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string temp;
		std::cin >> temp;
		v.push_back(temp);
	}
}

bool cmp(std::string first, std::string second) {
	if (first.length() != second.length()) return first.length() < second.length();

	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < first.length(); i++) {
		if (std::isdigit(first[i])) sum1 += first[i] - '0';
	}
	for (int i = 0; i < second.length(); i++) {
		if (std::isdigit(second[i])) sum2 += second[i] - '0';
	}
	
	if (sum1 != sum2) return sum1 < sum2;

	return first < second;
}

void Solve() {
	std::sort(v.begin(), v.end(), cmp);

	for (auto elem : v) {
		std::cout << elem << "\n";
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}