#include <bits/stdc++.h>

const int MX = 5001;
int pre[MX], nxt[MX];
std::vector<int> v;

int N, K, len;
void Input() {
	std::cin >> N >> K;
}

void Solve() {
	for (int i = 1; i <= N; i++) {
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}
	pre[1] = N;
	nxt[N] = 1;
	
	int cnt = 1;
	int idx = 1;
	while (idx != nxt[idx]) {
		if (cnt == K) {
			v.push_back(idx);
			nxt[pre[idx]] = nxt[idx];
			pre[nxt[idx]] = pre[idx];
			cnt = 0;
		}
		idx = nxt[idx];
		cnt++;
	}
	v.push_back(idx);

	std::cout << '<';
	for (int i = 0; i < v.size() - 1; i++) std::cout << v[i] << ", ";
	std::cout << v[v.size()-1] << '>';
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}