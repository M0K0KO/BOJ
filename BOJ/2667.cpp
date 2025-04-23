#include <bits/stdc++.h>

int N;
std::string board[27];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
std::queue<std::pair<int, int>> q;
std::vector<int> v;

void Input() {
	std::cin >> N;

	std::cin.ignore();

	for (int i = 0; i < N; i++) {
		std::cin >> board[i];
	}
}

int BFS(int x, int y) {
	int space = 0;

	board[x][y] = '0';
	space++;
	q.push({ x,y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[nx][ny] == '0') continue;

			board[nx][ny] = '0';
			space++;
			q.push({ nx,ny });
		}
	}

	return space;
}

void Solve() {
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '1')
			{
				v.push_back(BFS(i, j)); 
				cnt++;
			}
		}
	}

	std::cout << cnt << '\n';
	std::sort(v.begin(), v.end());
	for (auto elem : v) {
		std::cout << elem << '\n';
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}