#include <bits/stdc++.h>

int n;
std::stack<std::pair<int, int>> st;
int arr[1000001];

void Input() {
	std::cin >> n;
}

void Solve() {
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		while (!st.empty() && st.top().first < temp) {
			arr[st.top().second] = temp;
			st.pop();
		}
		st.push({ temp, i });
	}

	while (!st.empty()) {
		arr[st.top().second] = -1;
		st.pop();
	}

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}