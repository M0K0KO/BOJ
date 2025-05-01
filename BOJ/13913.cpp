#include <bits/stdc++.h>

int startPos, targetPos;
int dist[100002];
std::stack<int> st;
std::queue<int> q;

int result;

void Input() {
	std::cin >> startPos >> targetPos;
	
	std::fill(dist, dist + 100002, -1);
	dist[startPos] = 0;
}


int BFS() {
	q.push(startPos);

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur == targetPos) {
			return dist[cur];
		}

		if (cur * 2 < 100002 && dist[cur * 2] == -1) {
			dist[cur * 2] = dist[cur] + 1;
			q.push(cur * 2);
		}

		for (auto i : { 1, -1 }) {
			int nx = cur + i;

			if (nx < 0 || nx >= 100002) continue;
			if (dist[nx] != -1) continue;

			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}

	return -1;
}

void BackTrack(int idx) {
	while (idx != startPos) {

		st.push(idx);

		// idx°¡ 0ÀÌ ¾Æ´Ï°í Â¦¼öÀÏ ¶§¸¸ 2·Î ³ª´²º½
		if (idx != 0 && idx % 2 == 0) {
			if (dist[idx / 2] == dist[idx] - 1) {
				idx /= 2;
				continue;
			}
		}

		if (idx + 1 < 100002) {
			if (dist[idx + 1] == dist[idx] - 1) {
				idx += 1;
				continue;
			}
		}

		if (idx - 1 >= 0) {
			if (dist[idx - 1] == dist[idx] - 1) {
				idx -= 1;
				continue;
			}
		}
	}

	st.push(idx);
}

void Solve() {
	result = BFS();
	int idx = targetPos;
	BackTrack(idx);

	std::cout << result << "\n";

	while (!st.empty()) {
		std::cout << st.top() << " ";
		st.pop();
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}