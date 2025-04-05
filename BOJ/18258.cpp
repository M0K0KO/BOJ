#include <bits/stdc++.h>

int N;
int dat[2000005];
int head;
int tail;

void Input() {
	std::cin >> N;
}

void Solve() {
	while (N--) {
		std::string c;
		std::cin >> c;
		if (c == "push") {
			int temp;
			std::cin >> temp;
			dat[tail++] = temp;
		}
		else if (c == "pop") {
			if (head != tail)
			{
				std::cout << dat[head] << '\n';
				head++;
			}
			else {
				std::cout << -1 << '\n';
			}
		}
		else if (c == "size") {
			std::cout << tail - head << '\n';
		}
		else if (c == "empty") {
			if (tail == head) std::cout << 1 << '\n';
			else std::cout << 0 << '\n';
		}
		else if (c == "front") {
			if (head != tail) std::cout << dat[head] << '\n';
			else std::cout << -1 << '\n';
		}
		else if (c == "back") {
			if (head != tail) std::cout << dat[tail - 1] << '\n';
			else std::cout << -1 << '\n';
		}

	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}