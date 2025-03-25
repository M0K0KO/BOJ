#include <iostream>
#include <stack>

int main() {
	std::string input;
	std::cin >> input;

	std::stack<int> st;
	int result = 0;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') st.push(-1);
		else if (input[i] == 'H') st.push(1);
		else if (input[i] == 'C') st.push(12);
		else if (input[i] == 'O') st.push(16);
		else if (input[i] == ')') {
			int num = 0;
			while (st.top() != -1) {
				num += st.top();
				st.pop();
			}
			st.pop();
			st.push(num);
		}
		else if (input[i] >= '2' && input[i] <= '9') {
			int temp = st.top() * (input[i] - '0');
			st.pop();
			st.push(temp);
		}
	}

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	std::cout << result;
}