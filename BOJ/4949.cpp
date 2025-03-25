#include <iostream>
#include <string>
#include <stack>

int main() {
	while (true) {
		std::string input;
		std::getline(std::cin, input);
		std::stack<char> st;

		bool result = true;

		if (input == ".") break;

		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '(' || input[i] == '[') {
				st.push(input[i]);
			}
			
			if (input[i] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					result = false;
					break;
				}
			}
			else if (input[i] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					result = false;
					break;
				}
			}
		}
		if (result && st.empty()) std::cout << "yes" << '\n';
		else std::cout << "no" << '\n';
	}
}