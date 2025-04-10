#include <bits/stdc++.h>

std::string str;
std::stack<int> st;

int sum, bar;

void Input() {
	std::cin >> str;
}

void Solve() {
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')')
			{
				sum += bar;
				i++;
			}
			else {
				bar++;
				sum++;
				st.push(str[i]);
			}
		}
		else if (str[i] == ')') {
			if (!st.empty() && st.top() == '(') {
				st.pop();
				bar--;
			}
		}
	}

	std::cout << sum;
}	


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}