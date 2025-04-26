#include <bits/stdc++.h>

int N, M;
char board[1000][1000];
int dist[1000][1000][2];

void Input() {
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> board[i][j];
		}
	}
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int Solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}

	dist[0][0][0] = dist[0][0][1] = 1;
	std::queue<std::tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		int x, y, broken;
		std::tie(x, y, broken) = q.front();
		if (x == N - 1 && y == M - 1)
		{
			return dist[x][y][broken];
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
				dist[nx][ny][broken] = dist[x][y][broken] + 1;
				q.push({ nx, ny, broken });
			}
			if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = dist[x][y][broken] + 1;
				q.push({ nx, ny, 1 });
			}
		}
	}

	return -1;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	std::cout << Solve();
}