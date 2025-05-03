#include <bits/stdc++.h>

int N, M, P;

std::string board[1001];
int vis[1001][1001];
int playerCastle[10];
int playerPower[10];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

std::vector<std::queue<std::pair<int, int>>> playerQueues;

void Input() {
	std::cin >> N >> M >> P;

	for (int i = 0; i < N; i++) {
		std::fill(vis[i], vis[i] + M, -1);
	}

	for (int i = 0; i < P; i++) {
		std::cin >> playerPower[i];
	}

	playerQueues.resize(P);

	for (int i = 0; i < N; i++) {
		std::cin >> board[i];
		for (int j = 0; j < M; j++) {
			if (board[i][j] >= '1' && board[i][j] <= '9') {
				int playerIdx = board[i][j] - '1';
				if (playerIdx >= 0 && playerIdx < P) {
					playerCastle[playerIdx]++;
					vis[i][j] = playerIdx;
					playerQueues[playerIdx].push({ i, j });
				}
			}
		}
	}
}

void Solve() {
	bool expanded = true;
	while (expanded) {
		expanded = false;

		for (int playerIdx = 0; playerIdx < P; playerIdx++) {
			for (int step = 0; step < playerPower[playerIdx]; step++) {
				int qSize = playerQueues[playerIdx].size();
				if (qSize == 0) break; 

				for (int i = 0; i < qSize; i++) {
					auto cur = playerQueues[playerIdx].front();
					playerQueues[playerIdx].pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (board[nx][ny] == '#' || vis[nx][ny] != -1) continue;

						vis[nx][ny] = playerIdx;
						playerCastle[playerIdx]++;
						playerQueues[playerIdx].push({ nx, ny });
						expanded = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < P; i++) {
		std::cout << playerCastle[i] << " ";
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}