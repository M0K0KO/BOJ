#include <bits/stdc++.h>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> ans = { std::make_pair(0, 0), std::make_pair(1,0), std::make_pair(2,0), std::make_pair(2, 1), std::make_pair(2, 2), std::make_pair(1, 2), std::make_pair(0, 2), std::make_pair(0, 1) };
	std::vector<std::vector<char>> v;
	std::vector<int> nums;

	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = 0; j < 3; j++) {
			std::string temp;
			std::cin >> temp;
			std::vector<char> a(temp.begin(), temp.end());
			v.push_back(a);
		}
		int m;
		std::cin >> m;
		nums.clear();
		for (int j = 0; j < m; j++) {
			int temp;
			std::cin >> temp;
			nums.push_back(temp);
		}

		std::deque<bool> dq;
		for (int j = 0; j < ans.size(); j++) {
			dq.push_back(v[ans[j].first][ans[j].second] == 'O');
		}

		for (int j = 0; j < dq.size(); j++) {
			if (!dq.front()) break;
			else {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}

		std::stack<bool> st;
		int flag = 1;

		for (int j = 0; j < dq.size(); j++) {
			if (!dq[j] && !st.empty()) {
				auto it = std::find(nums.begin(), nums.end(), st.size());
				if (it == nums.end()) {
					flag = 0; 
					break; 
				}
				else {
					nums.erase(it);
				}
				while (!st.empty()) st.pop();
			}
			else { 
				if (dq[j] == true) st.push(true); 
			}
		}

		if (!st.empty() && flag == 1) {
			auto it = std::find(nums.begin(), nums.end(), st.size());
			if (it == nums.end()) flag = 0;
			else nums.erase(it);
		}

		if (!nums.empty()) flag = 0;

		std::cout << flag << '\n';
	}
}