#include <iostream>
#include <string>

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;

    int arr[26];
    std::fill(arr, arr + 26, 0);

    for (char c : s) {
        arr[int(c) - 'a']++;
    }

    for (auto num : arr) {
        std::cout << num << ' ';
    }
}