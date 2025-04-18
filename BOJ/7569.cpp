#include <bits/stdc++.h>

int M, N, H;
int box[101][101][101];
int dist[101][101][101];

std::queue<std::tuple<int, int, int>> q;

void Input() {
	std::cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				std::cin >> box[j][k][i];
				int tmp = box[j][k][i];
				if (tmp == 1) q.push({ j,k,i });
				if (tmp == 0) dist[j][k][i] = -1;
			}
		}
	}
}

int dx[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };

void BFS() {
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		
		int curX, curY, curZ;
		std::tie(curX, curY, curZ) = cur;

		for (int i = 0; i < 6; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			int nz = curZ + dz[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
			if (dist[nx][ny][nz] >= 0) continue;

			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			q.push({ nx,ny,nz });
		}
	}
}

void Solve() {
	BFS();

	int result = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (dist[j][k][i] == -1) {
					std::cout << -1 << '\n';
					return;
				}
				result = std::max(result, dist[j][k][i]);
			}
		}
	}

	std::cout << result << '\n';
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}