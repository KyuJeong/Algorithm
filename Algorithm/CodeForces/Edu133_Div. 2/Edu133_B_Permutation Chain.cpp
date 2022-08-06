#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << n << "\n";
		int arr[101];
		for (int i = 0; i < n; i++) {
			arr[i] = i + 1;
		}
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < n - 1; i++) {
			swap(arr[i], arr[i + 1]);
			for (int j = 0; j < n; j++) {
				cout << arr[j] << " ";
			}
			cout << "\n";
		}

	}

	return 0;
}