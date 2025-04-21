#include <bits/stdc++.h>

int N, I;
std::pair<int, int> currentPos, targetPos;

int dist[302][302];

std::queue<std::pair<int,int>> q;

void Input() {
	std::cin >> N;
}

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void Solve() {
	while (N--) {
		std::cin >> I;
		std::cin >> currentPos.first >> currentPos.second;
		std::cin >> targetPos.first >> targetPos.second;


		for (int i = 0; i < I; i++) {
			std::fill(dist[i], dist[i] + I, 0);
		}

		if (currentPos == targetPos) {
			std::cout << 0 << '\n';
			continue;
		}

		dist[currentPos.first][currentPos.second] = 1;
		q.push(currentPos);

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
				if (dist[nx][ny] != 0) continue;

				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				q.push({ nx, ny });

				if (nx == targetPos.first && ny == targetPos.second) {
					std::cout << dist[nx][ny] - 1 << '\n';
					while (!q.empty()) q.pop();
					break;
				}
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