#include <bits/stdc++.h>

int startPos, targetPos;
int dist[100002];

void Input() {
	std::cin >> startPos >> targetPos;
	std::fill(dist, dist + 100002, -1);
}

void Solve() {
	std::queue<int> q;
	q.push(startPos);
	dist[startPos] = 0;

	while (!q.empty()) {
		auto cur = q.front(); 
		q.pop();

		if (cur == targetPos) {
			std::cout << dist[cur];
			return;
		}

		if (cur * 2 < 100002 && dist[cur * 2] == -1) {
			dist[cur * 2] = dist[cur];
			q.push(cur * 2);
		}

		for (int i : {-1, 1}) {
			int nx = cur + i;
			if (nx < 0 || nx >= 100002) continue;
			if (dist[nx] == -1) {
				dist[nx] = dist[cur] + 1;
				q.push(nx);
			}
		}
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}