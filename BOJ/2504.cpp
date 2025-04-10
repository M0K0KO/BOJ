#include <bits/stdc++.h>

std::string str;
std::stack<char> st;

void Input() {
	std::cin >> str;
}

int sum;
int temp = 1;

void Solve() {
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') {
				
			}
		}
		else if (str[i] == ')') {
			if (!st.empty() && st.top() == '(') {

			}
		}
		else if (str[i] == '[') {
			st.push(str[i]);
		}
		else if (str[i] == ']') {
			if (!st.empty() && st.top() == '[') {

			}
		}
	}
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}