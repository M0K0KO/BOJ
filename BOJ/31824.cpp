#include <iostream>
#include <string>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::pair<std::string, std::string>> info;
	
	for (int i = 0; i < n; i++) {
		std::string a, b;
		std::cin >> a >> b;

		info.push_back(std::make_pair(a, b));
	}


	std::string target;
	for (int j = 0; j < m; j++) {
		int flag = 0;
		target.clear();
		std::cin >> target;

		std::string temp;

		for (int k = 0; k < target.size(); k++) {
			for (int a = 0; a <= target.size() - k; a++) {
				temp = target.substr(k, a);
				for (int l = 0; l < n; l++) {
					if (temp == info[l].first) {
						std::cout << info[l].second;
						flag = 1;
					}
				}
			}
		}
		if (flag == 0) std::cout << -1 << '\n';
		else std::cout << '\n';
	}
}