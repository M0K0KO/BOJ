#include <iostream>
#include <deque>

int main() {
	int n;
	int num;
	int target;
	int importance;
	std::deque<std::pair<int, int>> dq;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		dq.clear();

		std::cin >> num >> target;

		for (int j = 0; j < num; j++) {
			std::cin >> importance;
			dq.push_back(std::make_pair(j, importance));
		}

		int cnt = 0;

		while (!dq.empty()) {
			while (true) {
				bool flag = 0;
				for (int i = 1; i < dq.size(); i++) {
					if (dq.front().second < dq[i].second) {
						flag = 1;
					}
				}

				if (flag == 1) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
				else {
					break;
				}
			}

			cnt++;
			if (dq.front().first == target) {
				std::cout << cnt << '\n';
				break;
			}
			else {
				dq.pop_front();
			}
		}
	}
}
