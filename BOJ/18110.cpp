#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	int n;
	int ex;
	std::cin >> n;

	std::vector<int> v;

	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		v.push_back(temp);
	}

	if (n == 0) std::cout << 0;
	else {
		int sum = 0;

		ex = std::floor((double(n) / 10 * 1.5) + 0.5);
		std::sort(v.begin(), v.end());
		for (int j = ex; j <= n - ex - 1; j++) {
			sum += v[j];
		}

		std::cout << std::floor((double(sum) / (n - 2 * ex)) + 0.5);
	}
}