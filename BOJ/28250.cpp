#include <iostream>

int main() {
	std::cin.tie(0)->sync_with_stdio(0);

	int N;
	std::cin >> N;

	long a = 0;
	long b = 0;

	for (int i = 0; i < N; i++) {
		int temp;
		std::cin >> temp;
		if (temp == 0) a++;
		else if (temp == 1) b++;
	}

	std::cout << (a * b * 2) + ((a * (a-1)) / 2) + (a * (N - a - b)) << '\n';
}