#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 500002

struct Suffix {
	int sa; // suffix array
	int r; // rank
	int nr; // next rank
};

int n;
string str;
Suffix sfx[MAXN], tmp_sfx[MAXN];
int tmp[MAXN], inv[MAXN], cnt[MAXN + 1];
int lcp[MAXN];

void radixSort(int t, int m) {

	for (int i = 0; i < m + 1; i++)
		cnt[i] = 0;

	// 먼저 두 번째 랭크를 가지고 정렬
	for (int i = 0; i < n; i++)
		cnt[sfx[i].nr + 1]++; // nr은 -1이 될 수 있으므로 +1
	for (int i = 1; i < m + 1; i++)
		cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--)
		tmp_sfx[--cnt[sfx[i].nr + 1]] = sfx[i];

	for (int i = 0; i < m + 1; i++)
		cnt[i] = 0;

	// 첫 번째 랭크를 가지고 정렬
	for (int i = 0; i < n; i++)
		cnt[tmp_sfx[i].r]++;
	for (int i = 1; i < m; i++)
		cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--)
		sfx[--cnt[tmp_sfx[i].r]] = tmp_sfx[i];
}

bool cmp(Suffix& a, Suffix& b) {
	if (a.r == b.r)	return a.nr < b.nr;
	return a.r < b.r;
}

void makeSA() {
	for (int i = 0; i < n; i++) {
		sfx[i].sa = i;
		sfx[i].r = str[i] - 'a';
		sfx[i].nr = (i + 1) < n ? str[i + 1] - 'a' : -1; // 뒤에 글자가 없을 경우 -1
	}

	sort(sfx, sfx + n, cmp);
	for (int t = 2; ; t <<= 1) {
		tmp[0] = 0; // rank의 초기값은 0
		for (int i = 1; i < n; i++) {
			if (cmp(sfx[i - 1], sfx[i])) // 바로 앞의 suffix와 비교해서 현재 rank를 계산
				tmp[i] = tmp[i - 1] + 1;
			else
				tmp[i] = tmp[i - 1];
		}

		// (tmp[n - 1] == n - 1)일 경우 모든 suffix가 순서대로 정렬된 경우이므로 종료
		if (tmp[n - 1] == n - 1) break;

		for (int i = 0; i < n; i++)
			inv[sfx[i].sa] = i; // sa의 inverse 배열

		for (int i = 0; i < n; i++)
			sfx[i].r = tmp[i]; // 현재 rank 저장

		for (int i = 0; i < n; i++) {
			int nxt = sfx[i].sa + t; // next rank 계산을 위해 t를 더해줌
			sfx[i].nr = nxt < n ? sfx[inv[nxt]].r : -1; // str을 벗어난다면 next rank에 -1
		}

		radixSort(t, tmp[n - 1] + 1);
	}
}

void makeLCP() {
	for (int i = 0; i < n; i++)
		inv[sfx[i].sa] = i;
	int len = 0;
	for (int i = 0; i < n; i++) {
		int k = inv[i]; // i번째 suffix가 들어있는 index(i가 0이라면 입력받은 str)
		if (k) {
			int j = sfx[k - 1].sa; // 비교할 suffix의 바로 앞에 있는 suffix
			while (str[j + len] == str[i + len]) len++;
			lcp[k] = len;
			if (len) len--;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;

	n = str.size();

	makeSA();
	makeLCP();

	for (int i = 0; i < n; i++)
		cout << sfx[i].sa + 1 << " ";
	cout << "\nx ";
	for (int i = 1; i < n; i++)
		cout << lcp[i] << " ";

	return 0;
}