#include <bits/stdc++.h>

int N;

void Input() {
	std::cin >> N;
}

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
std::queue<std::pair<int, int>> f_q;
std::queue<std::pair<int, int>> sk_q;

std::string board[1002];
int fire_dist[1002][1002];
int sk_dist[1002][1002];

void Solve() {
	while (N--) {
		// input
		int w, h;
		std::cin >> w >> h;
		for (int i = 0; i < h; i++) {
			std::cin >> board[i];
		}

		for (int i = 0; i < h; i++) {
			std::fill(fire_dist[i], fire_dist[i] + w, 0);
			std::fill(sk_dist[i], sk_dist[i] + w, 0);
		}

		while (!f_q.empty()) f_q.pop();
		while (!sk_q.empty()) sk_q.pop();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					fire_dist[i][j] = 1;
					f_q.push({ i,j });
				}
				else if (board[i][j] == '@') {
					sk_dist[i][j] = 1;
					sk_q.push({ i,j });
				}
			}
		}
		// input

		auto start = sk_q.front();
		if (start.first == 0 || start.second == 0 || start.first == h - 1 || start.second == w - 1) {
			std::cout << 1 << '\n';
			continue;
		}

		// 불에 대해 dist
		while (!f_q.empty()) {
			auto cur = f_q.front(); f_q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= h|| ny < 0 || ny >= w) continue;
				if (fire_dist[nx][ny] != 0 || board[nx][ny] == '#') continue;

				fire_dist[nx][ny] = fire_dist[cur.first][cur.second] + 1;
				f_q.push({ nx, ny });
			}
		}
		// 불에 대해 dist
		
		bool canEscape = false;

		// 상근이 dist 할 때 수를 비교
		while (!sk_q.empty()) {
			auto cur = sk_q.front(); sk_q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (sk_dist[nx][ny] != 0 || board[nx][ny] == '#') continue;
				if (fire_dist[nx][ny] != 0 && fire_dist[nx][ny] <= sk_dist[cur.first][cur.second] + 1) continue;

				sk_dist[nx][ny] = sk_dist[cur.first][cur.second] + 1;

				if (nx == 0 || ny == 0 || nx == h - 1 || ny == w - 1) {
					std::cout << sk_dist[nx][ny] << '\n';	
					while (!sk_q.empty()) sk_q.pop();
					canEscape = true;
					break;
				}

				sk_q.push({ nx, ny });
			}
		}

		if (!canEscape)
			std::cout << "IMPOSSIBLE" << '\n';
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}