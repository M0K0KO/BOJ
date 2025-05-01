#include <bits/stdc++.h>

int N, M, K;
bool map[1001][1001];
int dist[1001][1001][11][2];

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
			for (int k = 0; k <= K; k++) {
				std::fill(dist[i][j][k], dist[i][j][k] + 2, -1);
			}
		}
	}
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void Solve() {
	std::queue<std::tuple<int, int, int, int>> q;
	dist[0][0][0][0] = 1;
	q.push({ 0,0,0,0 });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		int curX, curY, curBreakCnt, isNight;
		std::tie(curX, curY, curBreakCnt, isNight) = cur;

		if (curX == N - 1 && curY == M - 1) {
			std::cout << dist[curX][curY][curBreakCnt][isNight];
			return;
		}

		if (dist[curX][curY][curBreakCnt][!isNight] == -1) {
			dist[curX][curY][curBreakCnt][!isNight] = dist[curX][curY][curBreakCnt][isNight] + 1;
			q.push({ curX, curY, curBreakCnt, !isNight });
		}

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (map[nx][ny] == false) { // 장애물 없음
				if (dist[nx][ny][curBreakCnt][!isNight] == -1) { // 방문하지  않음
					dist[nx][ny][curBreakCnt][!isNight] = dist[curX][curY][curBreakCnt][isNight] + 1;
					q.push({ nx, ny, curBreakCnt, !isNight });
				}
			}
			else { // 장애물 있음
				if (!isNight && curBreakCnt < K) { // 밤이 아님 + 부술 기회 남음
					if (dist[nx][ny][curBreakCnt + 1][!isNight] == -1) {
						dist[nx][ny][curBreakCnt + 1][!isNight] = dist[curX][curY][curBreakCnt][isNight] + 1;
						q.push({ nx, ny, curBreakCnt + 1, !isNight });
					}
				}
			}
		}
	}

	std::cout << -1;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}