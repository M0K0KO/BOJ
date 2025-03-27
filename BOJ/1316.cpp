#include <bits/stdc++.h>

int N;
std::vector<std::string> v;

int arr[26];

char cache;
int cnt;

void Input() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string temp;
		std::cin >> temp;
		v.push_back(temp);
	}
}

void Solve() {
	for (auto elem : v) {
		int flag = 1;

		cache = elem[0];
		arr[elem[0] - 'a']++;
		for (int i = 1; i < elem.size(); i++) {
			if (arr[elem[i] - 'a'] != 0 && cache != elem[i]) {
				flag = 0;
				break;
			}
			else {
				arr[elem[i] - 'a']++;
				cache = elem[i];
			}
		}
		std::fill(arr, arr + 26, 0);
		if (flag) cnt++;
	}

	std::cout << cnt;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}