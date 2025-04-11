#include <bits/stdc++.h>

std::string str;
std::stack<char> st;

void Input() {
	std::cin >> str;
}

int sum;
int multiplier = 1;
bool isPopped = false;
bool flag = false;

void Solve() {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			if (isPopped) isPopped = false;
			st.push(str[i]);
			multiplier *= 2;
		}
		else if (str[i] == ')') {
			if (!st.empty() && st.top() == '(') {
				if (!isPopped)
				{
					sum += multiplier;
					isPopped = true;
				}
				st.pop();
				multiplier /= 2;
			}
			else {
				flag = true;
				break;
			}
		}
		else if (str[i] == '[') {
			if (isPopped) isPopped = false;
			st.push(str[i]);
			multiplier *= 3;
		}
		else if (str[i] == ']') {
			if (!st.empty() && st.top() == '[') {
				if (!isPopped)
				{
					sum += multiplier;
					isPopped = true;
				}
				st.pop();
				multiplier /= 3;
			}
			else {
				flag = true;
				break;
			}
		}
	}

	if (flag || !st.empty()) std::cout << 0;
	else std::cout << sum;
}


int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	Input();
	Solve();
}