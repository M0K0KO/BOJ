#include <bits/stdc++.h>

int N, K;
int dist[100002];

void Input() {
	std::cin >> N >> K;
	std::fill(dist, dist + 100001, -1);

	dist[N] = 0;
}

void Solve() {
	std::queue<int> q;
	q.push(N);

	while (dist[K] == -1) {
		int cur = q.front();
		q.pop();
		for (int nxt : {cur + 1, cur - 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}


	std::cout << dist[K];
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}