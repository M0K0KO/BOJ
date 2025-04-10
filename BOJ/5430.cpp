#include <bits/stdc++.h>
int T;
void Input() {
    std::cin >> T;
}
void Solve() {
    while (T--) {
        std::string func;
        std::cin >> func;
        int n;
        std::cin >> n;
        std::string arr;
        std::cin >> arr;
        std::deque<int> dq;

        std::string num;
        for (size_t i = 0; i < arr.size(); i++) {
            if (isdigit(arr[i])) {
                num += arr[i];
            }
            else if (arr[i] == ',' || arr[i] == ']') {
                if (!num.empty()) {
                    dq.push_back(std::stoi(num));
                    num.clear();
                }
            }
        }

        int reverse_cnt = 0;
        bool errorFlag = false;
        for (auto c : func) {
            if (c == 'R') {
                reverse_cnt++;
            }
            else if (c == 'D') {
                if (dq.empty()) {
                    errorFlag = true;
                    break;
                }
                if (reverse_cnt % 2 == 0) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (errorFlag) {
            std::cout << "error" << '\n';
        }
        else {
            std::cout << '[';
            if (reverse_cnt % 2 == 0) {
                for (size_t i = 0; i < dq.size(); i++) {
                    std::cout << dq[i];
                    if (i < dq.size() - 1) {
                        std::cout << ',';
                    }
                }
            }
            else {
                for (int i = dq.size() - 1; i >= 0; i--) {
                    std::cout << dq[i];
                    if (i > 0) {
                        std::cout << ',';
                    }
                }
            }
            std::cout << "]\n";
        }
    }
}
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    Input();
    Solve();
}