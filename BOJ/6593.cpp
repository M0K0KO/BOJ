#include <bits/stdc++.h>

int L, R, C;

std::tuple<int, int, int> S, E;

char building[32][32][32];
int dist[32][32][32];


void Input() {

}

int dx[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };

void Solve() {
	while (true) {

		std::cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) return;

		std::memset(dist, 0, sizeof(dist));

		std::cin.ignore();

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				std::cin >> building[i][j];
				for (int k = 0; k < C; k++) {
					if (building[i][j][k] == 'S') S = { i,j,k };
					if (building[i][j][k] == 'E') E = { i,j,k };
				}
			}
		}

		bool escape = false;
		std::queue<std::tuple<int, int, int>> q;
		int x, y, z;
		std::tie(x, y, z) = S;
		dist[x][y][z] = 1;
		q.push(S);

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			std::tie(x, y, z) = cur;

			if (cur == E) {
				std::cout << "Escaped in " << dist[x][y][z] - 1 << " minute(s).\n";
				escape = true;
				break;
			}

			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) continue;
				if (building[nx][ny][nz] == '#' || dist[nx][ny][nz] != 0) continue;

				dist[nx][ny][nz] = dist[x][y][z] + 1;
				q.push({ nx,ny,nz });
			}
		}

		if(!escape) std::cout << "Trapped!\n";
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}