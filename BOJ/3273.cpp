#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, x, nums[100001];
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[a]++;
		nums[i] = a;
	}

	cin >> x;

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (nums[i] < x && x -nums[i] < 1000001) {
			if (arr[x - nums[i]] != 0) cnt++;
		}
	}

	cout << cnt/2;
}


