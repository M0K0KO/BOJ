#include <bits/stdc++.h>

int N;
long long cnt;
std::stack<std::pair<int, int>> st;

void Input() {
	std::cin >> N;
}

void Solve() {
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;

		int same_height = 1;

		while (!st.empty() && st.top().first <= temp) {
			cnt += st.top().second;

			if (st.top().first == temp) {
				same_height += st.top().second;
			}

			st.pop();
		}

		if (!st.empty()) cnt++;

		st.push({ temp, same_height });
	}

	std::cout << cnt;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}