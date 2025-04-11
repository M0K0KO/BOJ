#include <bits/stdc++.h>

int N, M;
std::string board[102];
int dist[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void Input() {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> board[i];
		std::fill(dist[i], dist[i] + M, -1);
	}
}

void BFS(int sx, int sy) {
	std::queue<std::pair<int, int>> q;
	q.push({ sx, sy });
	dist[sx][sy] = 0;
	while (!q.empty()) {
		std::pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == '0') continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
}

void Solve() {
	BFS(0, 0);
	std::cout << dist[N - 1][M - 1] + 1;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}