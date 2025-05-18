#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int n;
vector <pii> arr;
vector <pii> arr2;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	arr.resize(n);
	arr2.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < n; i++) {
		cin >> arr2[i].first >> arr2[i].second;
	}

	sort(arr.begin(), arr.end());
	sort(arr2.begin(), arr2.end());

	int move_x = arr2[0].first - arr[0].first;
	int move_y = arr2[0].second - arr[0].second;

	cout << move_x << " " << move_y;

	return 0;
}