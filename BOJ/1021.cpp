#include <bits/stdc++.h>

int N, M;
std::deque<int> dq;
int sum;
std::vector<int> v;

void Input() {
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		std::cin >> temp;
		v.push_back(temp);
	}
	
	for (int i = 0; i < N; i++) {
		dq.push_back(i + 1);
	}
}

void Solve() {
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		int target = v[i];

		while (dq.front() != target) {
			int temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
			cnt++;
		}

		std::cout << dq.front() << "<---\n";

		if (cnt > (dq.size() / 2)) {
			cnt = dq.size() - cnt;
			sum += cnt;
		}
		else {
			sum += cnt;
		}

		dq.pop_front();
	}

	std::cout << sum;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}