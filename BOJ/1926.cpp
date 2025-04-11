#include <bits/stdc++.h>

int N, M;
int board[502][502];

void Input() {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			std::cin >> temp;
			board[i][j] = temp;
		}
	}
}

bool vis[502][502];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int Mx;

int BFS(int startPointX, int startPointY) {
	std::queue<std::pair<int, int>> q;
	vis[startPointX][startPointY] = 1;
	q.push({ startPointX, startPointY });

	int sum = 0;

	while (!q.empty()) {
		std::pair<int, int> cur = q.front();
		q.pop();
		sum++;
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
			if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

	return sum;
}

void Solve() {

	int BFScnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				int val = BFS(i, j);
				BFScnt++;
				Mx = std::max(Mx, val);
			}
		}
	}

	std::cout << BFScnt << '\n' << Mx;
}

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}