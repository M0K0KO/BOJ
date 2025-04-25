#include <bits/stdc++.h>

int N;

int maxheight;

int heightmap[102][102];
bool vis[102][102];

void Input() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> heightmap[i][j];
			maxheight = std::max(maxheight, heightmap[i][j]);
		}
	}
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

std::queue<std::pair<int, int>> q;

void BFS(int x, int y, int limit) {
	vis[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (heightmap[nx][ny] > limit && vis[nx][ny] == false) {
				vis[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void Solve() {
	int maxlimit = 0;
	int maxcnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			maxlimit = std::max(heightmap[i][j], maxlimit);
		}
	}

	for (int limit = 0; limit <= maxlimit; limit++) {
		for (int i = 0; i < N; i++) {
			std::fill(vis[i], vis[i] + N, false);
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++){
				if (heightmap[i][j] > limit && vis[i][j] == 0) {
					BFS(i, j, limit);
					cnt++;
				}
			}
		}
		maxcnt = std::max(cnt, maxcnt);
	}
	std::cout << maxcnt;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}