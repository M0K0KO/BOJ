#include <bits/stdc++.h>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	std::vector<int> v;
	
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		v.push_back(temp);
	}

	std::sort(v.begin(), v.end());
	int sum = 0;

	for (int i = 0; i <= v.size(); i++) {
		sum += std::accumulate(v.begin(), v.begin() + i, 0);
	}

	std::cout << sum;
}