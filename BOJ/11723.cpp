#include <iostream>
#include <vector>
#include <algorithm>


// 못푼문제임 

class Solution {
private:
	std::vector<int>& s;
public:
	Solution(std::vector<int>& s) : s(s) {}

	void add(int x) {
		bool flag = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == x) flag = 1;
		}

		if (flag == 0) s.push_back(x);
	}
	
	void remove(int x) {
		s.erase(std::remove(s.begin(), s.end(), x), s.end());
	}

	void check(int x) {
		bool flag = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == x) flag = 1;
		}

		if (flag == 0) std::cout << 0 << '\n';
		else std::cout << 1 << '\n';
	}

	void toggle(int x) {
		bool flag = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == x) flag = 1;
		}

		if (flag == 0) s.push_back(x);
		else {
			s.erase(std::remove(s.begin(), s.end(), x), s.end());
		}
	}

	void all() {
		s.clear();
		for (int i = 0; i < 20; i++) {
			s.push_back(i + 1);
		}
	}

	void empty() {
		s.clear();
	}
};


int main() {
	int n;
	std::cin >> n;

	std::vector<int> s;
	Solution sol(s);

	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		if (s == "all") {
			sol.all();
		}
		else if (s == "empty") {
			sol.empty();
		}
		else {
			int a;
			std::cin >> a;

			if (s == "add") sol.add(a);
			else if (s == "remove") sol.remove(a);
			else if (s == "toggle") sol.toggle(a);
			else if (s == "check") sol.check(a);
		}
	}
}