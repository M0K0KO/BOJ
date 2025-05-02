#include <bits/stdc++.h>

int N, M, P;
std::string board[1001];
int vis[1001][1001];
int power[10];

int castle[10];

std::queue<std::pair<int, int>> q;

void Input() {
	std::cin >> N >> M >> P;
	for (int i = 0; i < P; i++) {
		std::cin >> power[i];
	}

	for (int i = 0; i < N; i++) {
		std::fill(vis[i], vis[i] + M, -1);
	}

	for (int i = 0; i < N; i++) {
		std::cin >> board[i];
		for (int j = 0; j < M; j++) {
			if (board[i][j] >= '1' && board[i][j] <= '9') {
				vis[i][j] = board[i][j] - '1';
				castle[vis[i][j]]++;
			}
		}
	}
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void Solve() {
	bool expanded = true;

	while (expanded) {
		expanded = false;

		for (int player = 0; player < P; player++) {
			std::queue<std::pair<int, int>> currentPos;

			// 순회하면서 player 값과 같은 좌표 push
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (vis[i][j] == player) {
						currentPos.push({ i, j });
					}
				}
			}
			// 순회하면서 player 값과 같은 좌표 push

			for (int step = 0; step < power[player] && !currentPos.empty(); step++) {
				int size = currentPos.size();

				for (int k = 0; k < size; k++) {
					auto cur = currentPos.front();
					currentPos.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (board[nx][ny] == '#' || vis[nx][ny] != -1) continue;

						vis[nx][ny] = player;
						castle[player]++;
						currentPos.push({ nx, ny });
						expanded = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < P; i++) {
		std::cout << castle[i] << " ";
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}
