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

	// ���� �� ��° ��ũ�� ������ ����
	for (int i = 0; i < n; i++)
		cnt[sfx[i].nr + 1]++; // nr�� -1�� �� �� �����Ƿ� +1
	for (int i = 1; i < m + 1; i++)
		cnt[i] += cnt[i - 1];
	for (int i = n - 1; i >= 0; i--)
		tmp_sfx[--cnt[sfx[i].nr + 1]] = sfx[i];

	for (int i = 0; i < m + 1; i++)
		cnt[i] = 0;

	// ù ��° ��ũ�� ������ ����
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
		sfx[i].nr = (i + 1) < n ? str[i + 1] - 'a' : -1; // �ڿ� ���ڰ� ���� ��� -1
	}

	sort(sfx, sfx + n, cmp);
	for (int t = 2; ; t <<= 1) {
		tmp[0] = 0; // rank�� �ʱⰪ�� 0
		for (int i = 1; i < n; i++) {
			if (cmp(sfx[i - 1], sfx[i])) // �ٷ� ���� suffix�� ���ؼ� ���� rank�� ���
				tmp[i] = tmp[i - 1] + 1;
			else
				tmp[i] = tmp[i - 1];
		}

		// (tmp[n - 1] == n - 1)�� ��� ��� suffix�� ������� ���ĵ� ����̹Ƿ� ����
		if (tmp[n - 1] == n - 1) break;

		for (int i = 0; i < n; i++)
			inv[sfx[i].sa] = i; // sa�� inverse �迭

		for (int i = 0; i < n; i++)
			sfx[i].r = tmp[i]; // ���� rank ����

		for (int i = 0; i < n; i++) {
			int nxt = sfx[i].sa + t; // next rank ����� ���� t�� ������
			sfx[i].nr = nxt < n ? sfx[inv[nxt]].r : -1; // str�� ����ٸ� next rank�� -1
		}

		radixSort(t, tmp[n - 1] + 1);
	}
}

void makeLCP() {
	for (int i = 0; i < n; i++)
		inv[sfx[i].sa] = i;
	int len = 0;
	for (int i = 0; i < n; i++) {
		int k = inv[i]; // i��° suffix�� ����ִ� index(i�� 0�̶�� �Է¹��� str)
		if (k) {
			int j = sfx[k - 1].sa; // ���� suffix�� �ٷ� �տ� �ִ� suffix
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