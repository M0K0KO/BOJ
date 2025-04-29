#include <bits/stdc++.h>

int N;
int world[101][101];
int vis[101][101];
int dist[101][101];

std::queue<std::pair<int, int>> q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void Input() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> world[i][j];
		}
	}

	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (world[i][j] == 0 || vis[i][j] == 1) continue;
			cnt++;
			vis[i][j] = 1;
			world[i][j] = cnt;
			q.push({ i,j });
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (world[nx][ny] == 0 || vis[nx][ny] != 0) continue;

					world[nx][ny] = cnt;
					vis[nx][ny] = 1;

					q.push({ nx, ny });
				}
			}

		}
	}
	// 섬 구분까지 완료
}

void Solve() {
	for (int i = 0; i < N; i++) {
		std::fill(dist[i], dist[i] + N, -1);
	}

	int result = 999999;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (world[i][j] == 0) continue;
			dist[i][j] = 0;
			q.push({ i,j });

			bool escape = false;

			while (!q.empty() && !escape) {
				auto cur = q.front(); q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (dist[nx][ny] != -1 || world[i][j] == world[nx][ny]) continue;
					if (world[nx][ny] != world[i][j] && world[nx][ny] != 0) {
						result = std::min(result, dist[cur.first][cur.second]);
						while (!q.empty()) q.pop();
						escape = true;	
						break;
					}

					dist[nx][ny] = dist[cur.first][cur.second] + 1;
					q.push({ nx, ny });
				}
			}

			for (int i = 0; i < N; i++) {
				std::fill(dist[i], dist[i] + N, -1);
			}
		}
	}

	std::cout << result;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}