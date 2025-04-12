#include <bits/stdc++.h>

int N, M;
int box[1002][1002];
int dist[1002][1002];
std::queue<std::pair<int, int>> q;

void Input() {
	std::cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> box[i][j];
			if (box[i][j] == 1)  q.push({ i, j });
			if (box[i][j] == 0) dist[i][j] = -1;
		}
	}
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int BFS() {
	while (!q.empty()) {
		std::pair<int, int> cur = q.front();  q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] == -1) {
				return -1;
			}
			ret = std::max(ret, dist[i][j]);
		}
	}

	return ret;
}

void Solve() {
	std::cout << BFS();
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}