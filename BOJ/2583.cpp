#include <bits/stdc++.h>

int M, N, K;


bool board[102][102] = { false };
std::vector<int> v;

void Input() {
	std::cin >> M >> N >> K;

}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
std::queue<std::pair<int, int>> q;

int BFS(int x, int y) {
	int space = 0;

	board[x][y] = true;
	space++;
	q.push({ x,y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == true) continue;

			board[nx][ny] = true;
			space++;
			q.push({ nx,ny });
		}
	}
	
	return space;
}

void Solve() {
	while (K--) {
		std::pair<int, int> llcorner;
		std::pair<int, int> rhcorner;

		int a1, b1, a2, b2;
		std::cin >> a1 >> b1 >> a2 >> b2;
		llcorner = { N - a2, b1 };
		rhcorner = { N - a1, b2 };

		for (int i = llcorner.first; i < rhcorner.first; i++) {
			std::fill(board[i] + llcorner.second, board[i] + rhcorner.second, true); // ¹¹°¡ ÀÖ¾î == true
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == false) {
				v.push_back(BFS(i, j));
				cnt++;
			}
		}
	}

	std::sort(v.begin(), v.end());
	std::cout << cnt << '\n';
	for (auto elem : v) {
		std::cout << elem << ' ';
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}