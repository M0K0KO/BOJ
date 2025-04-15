#include <bits/stdc++.h>

int N;
std::string arr[101];
bool vis[101][101];

void Input() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::getline(std::cin, arr[i]);
	}
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

std::queue<std::pair<int, int>> q;

void BFS(int i, int j, char color) {
	vis[i][j] = true;
	q.push({ i,j });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (vis[i][j] == true || arr[i][j] != color) continue;
		}
	}
}


int normal_cnt = 0;
int abnormal_cnt = 0;

void Solve() {
	for (auto color : { 'R', 'G', 'B' }) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == color) {
					BFS(i, j, color);
					normal_cnt++;
				}
			}
		}
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}