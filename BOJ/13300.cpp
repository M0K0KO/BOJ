#include <iostream>

using namespace std;

int arr[2][6];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;

	cin >> N >> K;


	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b-1]++;
	}

	int cnt = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != 0) {
				if (arr[i][j] % K == 0) cnt += arr[i][j] / K;
				else cnt += (arr[i][j] / K + 1);
			}
		}
	}

	cout << cnt;
}

/*
* 0 : 000000 / 0 : 000000
*/