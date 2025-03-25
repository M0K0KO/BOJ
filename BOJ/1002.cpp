#include <bits/stdc++.h>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		double dist1, dist2;

		std::cin >> x1 >> y1 >> dist1 >> x2 >> y2 >> dist2;
		
		double distance = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

		if (distance == 0) {
			if (dist1 == dist2) std::cout << -1 << '\n';
			else std::cout << 0 << '\n';
		}
		else {
			if (dist1 > distance || dist2 > distance) {
				if (abs(dist2 - dist1) > distance) std::cout << 0 << '\n';
				else if (abs(dist2 - dist1) == distance) std::cout << 1 << '\n';
				else std::cout << 2 << '\n';
			}
			else {
				if (dist1 + dist2 < distance) std::cout << 0 << '\n';
				else if (dist1 + dist2 == distance) std::cout << 1 << '\n';
				else std::cout << 2 << '\n';
			}
		}

	}
}