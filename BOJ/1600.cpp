#include <bits/stdc++.h>

// 행 H개, 열 W개
int K, W, H;
bool board[201][201];
int dist[201][201][31];
std::tuple<int, int, int> startPos = { 0,0,0 };


void Input() {
	std::cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cin >> board[i][j];
		}
	}	

	std::memset(dist, -1, sizeof(dist));
}

std::queue<std::tuple<int,int,int>> q;

int horseDX[8] = { 1,2,2,1,-1,-2,-2,-1 };
int horseDY[8] = { 2,1,-1,-2,-2,-1,1,2 };

int monkeyDX[4] = { 1,0,-1,0 };
int monkeyDY[4] = { 0,1,0,-1 };

void BFS() {
	int x, y, horseCnt;
	std::tie(x, y, horseCnt) = startPos;
	dist[x][y][horseCnt] = 0;
	q.push(startPos);

	while (!q.empty()) {
		auto cur = q.front(); 
		q.pop();

		int curX, curY, curHorseCnt;
		std::tie(curX, curY, curHorseCnt) = cur;
		if (curX == H - 1 && curY == W - 1) {
			std::cout << dist[curX][curY][curHorseCnt];
			return;
		}

		if (curHorseCnt < K) {
			for (int i = 0; i < 8; i++) {
				int nx = curX + horseDX[i];
				int ny = curY + horseDY[i];
				int nhorseCnt = curHorseCnt + 1;

				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue; // Out of Bound
				if (board[nx][ny] == true) continue; // Board에 장애물 존재
				if (dist[nx][ny][nhorseCnt] != -1) continue; // 이미 지나간 곳

				dist[nx][ny][nhorseCnt] = dist[curX][curY][curHorseCnt] + 1;
				q.push({ nx,ny,nhorseCnt });
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = curX + monkeyDX[i];
			int ny = curY + monkeyDY[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue; // Out of Bound
			if (board[nx][ny] == true) continue; // Board에 장애물 존재
			if (dist[nx][ny][curHorseCnt] != -1) continue; // 이미 지나간 곳

			dist[nx][ny][curHorseCnt] = dist[curX][curY][curHorseCnt] + 1;
			q.push({ nx,ny, curHorseCnt });
		}
	}
	std::cout << -1;
	return;
}

void Solve() {
	BFS();
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}