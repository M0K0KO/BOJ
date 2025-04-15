#include <bits/stdc++.h>

int T, M, N, K;
int board[52][52];
bool vis[52][52];

void Input() {
	std::cin >> T;
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

std::queue<std::pair<int, int>> q;

void BFS(std::pair<int, int> startPoint) {
	vis[startPoint.first][startPoint.second] = 1;
	q.push(startPoint);

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

void Solve() {
	while (T--) {
		std::cin >> M >> N >> K;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			std::fill(board[i], board[i] + M, 0);
			std::fill(vis[i], vis[i] + M, false);
		}

		for (int i = 0; i < K; i++) {
			int a, b;
			std::cin >> a >> b;
			board[b][a] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 1 && vis[i][j] == 0) {
					BFS({ i, j });
					cnt++;
				}
			}
		}
		std::cout << cnt << '\n';
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}