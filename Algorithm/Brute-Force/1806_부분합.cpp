#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[100001];
int _min = 1e9;
int sum;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] >= k) {
			cout << "1";
			return 0;
		}
	}

	if (sum < k) {
		cout << "0";
		return 0;
	}

	int l = 0;
	int r = 1;
	sum = arr[0] + arr[1];

	while (r < n) {
		if (sum < k) {
			r++;
			sum += arr[r];
		}
		else {
			if (_min > r - l + 1) _min = r - l + 1;
			if (sum - arr[l] >= k) {
				sum -= arr[l];
				l++;
			}
			else {
				r++;
				sum += arr[r];
			}
		}
	}

	cout << _min;

	return 0;
}