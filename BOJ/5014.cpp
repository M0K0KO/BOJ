#include <bits/stdc++.h>

int F, S, G, U, D;
int dist[1000002];

void Input() {
	std::cin >> F >> S >> G >> U >> D;
	std::fill(dist, dist + F + 1, -1);
}

void Solve() {
	std::queue<int> q;
	dist[S] = 0;
	q.push(S);

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (auto nxt : { cur + U, cur - D }) {
			if (nxt > F || nxt <= 0 || dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	if (dist[G] != -1) {
		std::cout << dist[G];
		return;
	}

	std::cout << "use the stairs";
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}