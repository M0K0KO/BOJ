#include <bits/stdc++.h>

int R, C;
std::string board[1002];
int F_dist[1002][1002];
int J_dist[1002][1002];

std::pair<int, int> J;
std::vector<std::pair<int, int>> Fires;

void Input() {
	std::cin >> R >> C;
	std::cin.ignore();
	for (int i = 0; i < R; i++) {
		std::getline(std::cin, board[i]);
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'J')
				J = { i, j };
			else if (board[i][j] == 'F')
				Fires.push_back({ i, j });
		}
	}
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	Input();

	if (J.first == 0 || J.first == R - 1 || J.second == 0 || J.second == C - 1) {
		std::cout << 1 << '\n';
		return 0;
	}

	///////////////////////////////////////////////////////////////////
	std::queue<std::pair<int, int>> q;
	for (auto FireStart : Fires) {
		if (F_dist[FireStart.first][FireStart.second] == 0) {
			F_dist[FireStart.first][FireStart.second] = 1;
			q.push(FireStart);
		}
	}
	
	while (!q.empty()) {
		std::pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] == '#' || F_dist[nx][ny] != 0) continue;
			F_dist[nx][ny] = F_dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
	///////////////////////////////////////////////////////////////////

	J_dist[J.first][J.second] = 1;
	q.push(J);

	while (!q.empty()) {
		std::pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] == '#' || J_dist[nx][ny] != 0) continue;
			if (F_dist[nx][ny] != 0 && J_dist[cur.first][cur.second] + 1 >= F_dist[nx][ny]) continue;

			J_dist[nx][ny] = J_dist[cur.first][cur.second] + 1;

			if (nx == R - 1 || nx == 0 || ny == 0 || ny == C - 1) {
				std::cout << J_dist[nx][ny] <<'\n';
				return 0;
			}

			q.push({ nx, ny });
		}
	}
	std::cout << "IMPOSSIBLE";
}