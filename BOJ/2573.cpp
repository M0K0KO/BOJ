#include <bits/stdc++.h>

int N, M;
int iceberg[300][300];
bool vis[300][300] = { false };
int temp[300][300] = { false };

void Input() {
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> iceberg[i][j];
		}
	}
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void melt() {

	// ���縦 �ؿ�
	std::memcpy(temp, iceberg, sizeof(iceberg));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] > 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (temp[nx][ny] == 0) cnt++;
				}
				iceberg[i][j] = std::max(0, temp[i][j] - cnt);
			}
		}
	}
}

void BFS(int x, int y) {
	std::queue<std::pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (iceberg[nx][ny] == 0 || vis[nx][ny] == true) continue;

			vis[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int year;

void Solve() {

	int cnt = 1;
	while (true) {
		// vis �ʱ�ȭ
		std::memset(vis, false, sizeof(vis));

		// �쿩�����
		melt();
		year++;
		// �쿩�����


		// ���� ����
		int testCnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (iceberg[i][j] != 0 && vis[i][j] == false) {
					BFS(i, j);
					testCnt++;
				}
			}
		}
		// ���� ����

		// ������ 0�����? -> 0 ����ϰ� return
		// ������ 1�����? -> �� ������ ����
		// ������ 2�� �̻��̶��? -> break�Ķ�
		if (testCnt == 0) {
			std::cout << 0;
			return;
		}
		else if (testCnt >= 2) {
			break;
		}
	}
	std::cout << year;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}