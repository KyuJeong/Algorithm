#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <string> ans;

string s;

int idx = 0;
int mmap[67100000];
int _max = 0;
vector <int> tmp;

void solve(vector <int> v, int m) {

	int n = v.size();
	vector <int> seq;

	for (int i = 0; i < m; i++)
		seq.push_back(0);

	for (int i = 0; i < n - m; i++)
		seq.push_back(1);


	do {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (seq[i] == 0)  sum += (1 << v[i]);
		}

		mmap[sum]++;
		if (mmap[sum] == 2) tmp.push_back(sum);
		_max = max(_max, mmap[sum]);

	} while (next_permutation(seq.begin(), seq.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	int sz = orders.size();
	vector <int> arr[10];
	for (int i = 0; i < sz; i++) {
		for (auto& j : orders[i]) {
			arr[i].push_back(j -= 'A');
		}
	}

	int csz = course.size();
	for (int i = 0; i < csz; i++) {
		tmp.clear();
		_max = 0;
		for (int j = 0; j < sz; j++) {
			if (arr[j].size() >= course[i])
				solve(arr[j], course[i]);
		}
		for (auto j : tmp) {
			if (mmap[j] == _max) {
				string str = "";
				int num = j;
				for (int k = 26; k >= 0; k--) {
					if (num >= (1 << k)) {
						str.push_back(k + 'A');
						num -= (1 << k);
					}
				}
				reverse(str.begin(), str.end());
				ans.push_back(str);
			}
		}
	}

	sort(ans.begin(), ans.end());

	return ans;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	vector <string> a;
	vector <int> b;

	a.push_back("ABCFG");
	a.push_back("AC");
	a.push_back("ACDEH");

	b.push_back(2);
	b.push_back(3);
	b.push_back(4);

	solution(a, b);

	for (auto i : ans) cout << i << " ";

	return 0;
}