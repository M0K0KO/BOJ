#include <iostream>
#include <string>
using namespace std;

int arr[9];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s = to_string(n);

	for (char c : s) {
		if (c - '0' == 6 || c - '0' == 9) arr[8]++;
		else {
			if (c - '0' <= 5) arr[c - '0']++;
			else arr[c - '0' - 1]++;
		}
	}

	if (arr[8] % 2 == 0) arr[8] /= 2;
	else arr[8] = arr[8] / 2 + 1;

	int max = -1;

	for (auto a : arr) {
		if (a > max) max = a;
	}

	cout << max;
}