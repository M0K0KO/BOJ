#include <iostream>
#include <string>
using namespace std;

int arr1[26], arr2[26];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;

	cin >> a >> b;

	for (auto c : a) {
		arr1[c - 'a']++;
	}
	for (auto c : b) {
		arr2[c - 'a']++;
	}

	int cnt = 0;

	for (int i = 0; i < 26; i++) {
		cnt += abs(arr1[i] - arr2[i]);
	}

	cout << cnt;
}