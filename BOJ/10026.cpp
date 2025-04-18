#include <bits/stdc++.h>

int N;
std::string arr[101];
bool vis[101][101];

void Input() {
	std::cin >> N;
	std::cin.ignore();
	for (int i = 0; i < N; i++) {
		std::getline(std::cin, arr[i]);
	}
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

std::queue<std::pair<int, int>> q;

void normal_BFS(int i, int j) {
	char target = arr[i][j];
	vis[i][j] = true;
	q.push({ i,j });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (vis[nx][ny] == true || arr[nx][ny] != target) continue;
			vis[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

void abnormal_BFS(int i, int j) {
	bool isBlue = false;
	if (arr[i][j] == 'B') isBlue = true;
	vis[i][j] = true;
	q.push({ i, j });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (vis[nx][ny] == true) continue;

			if (isBlue) {
				if (arr[nx][ny] != 'B') continue;
			}
			else {
				if (arr[nx][ny] == 'B') continue;
			}

			vis[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}


int normal_cnt = 0;
int abnormal_cnt = 0;

void Solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				normal_BFS(i, j);
				normal_cnt++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		std::fill(vis[i], vis[i] + N, false);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j])
			{
				abnormal_BFS(i, j);
				abnormal_cnt++;
			}
		}
	}

	std::cout << normal_cnt << " " << abnormal_cnt;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}