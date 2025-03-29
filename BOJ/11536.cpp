#include <bits/stdc++.h>

int n;
std::vector<std::string> v, increasingV, decreasingV;

void Input() {
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		std::string temp;
		std::cin >> temp;
		v.push_back(temp);
	}
}

void Solve() {
	increasingV = v;
	decreasingV = v;

	std::sort(increasingV.begin(), increasingV.end(), std::less<std::string>());
	std::sort(decreasingV.begin(), decreasingV.end(), std::greater<std::string>());

	if (v == increasingV) std::cout << "INCREASING";
	else if (v == decreasingV) std::cout << "DECREASING";
	else std::cout << "NEITHER";
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}