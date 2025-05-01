#include <bits/stdc++.h>

int N, M, K;
bool map[1001][1001];
int dist[1001][1001][11];

void Input() {
	std::cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		std::string row;
		std::cin >> row;
		for (int j = 0; j < M; j++) {
			map[i][j] = (row[j] == '1');
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::fill(dist[i][j], dist[i][j] + 11, -1);
		}
	}
}

std::queue<std::tuple<int,int,int>> q;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS() {
	dist[0][0][0] = 1;
	q.push({ 0,0,0 });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		int curX, curY, breakCnt;
		std::tie(curX, curY, breakCnt) = cur;

		if (curX == N - 1 && curY == M - 1) {
			std::cout << dist[curX][curY][breakCnt];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // OOB
			if (dist[nx][ny][breakCnt] != -1) continue; // 이미 방문함

			if (breakCnt < K && map[nx][ny] == true && dist[nx][ny][breakCnt + 1] == -1) { // 장애물이 있고, 부술 수 있으면 부숨
				dist[nx][ny][breakCnt + 1] = dist[curX][curY][breakCnt] + 1;
				q.push({ nx, ny, breakCnt + 1 });
			}
			
			if (map[nx][ny] == false) {
				dist[nx][ny][breakCnt] = dist[curX][curY][breakCnt] + 1;
				q.push({ nx, ny, breakCnt });
			}
		}
	}

	std::cout << -1;
	return;
}

void Solve() {
	BFS();
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}