#include <bits/stdc++.h>

int N;
int* nums;
bool* visited;

void Input() {
	std::cin >> N;
}

void Permutation(int idx) {
	if (idx == N) {
		for (int i = 0; i < N; i++) {
			std::cout << nums[i] << " ";
		}
		std::cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] != true) {
			visited[i] = true;
			nums[idx] = i + 1;
			Permutation(idx + 1);
			visited[i] = false;
		}
	}
}

void Solve() {
	nums = new int[N];
	visited = new bool[N];

	Permutation(0);
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}