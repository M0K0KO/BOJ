#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;


	for (int i = 0; i < N; i++) {
		int result = 1;

		string a, b;
		cin >> a >> b;

		int arr1[26], arr2[26];
		fill(arr1, arr1 + 26, 0);
		fill(arr2, arr2 + 26, 0);

		for (char c : a) {
			arr1[c - 'a']++;
		}
		for (char c : b) {
			arr2[c - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (arr1[i] != arr2[i]) {
				result = 0;
				break;
			}
		}

		if (result) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
	}
}