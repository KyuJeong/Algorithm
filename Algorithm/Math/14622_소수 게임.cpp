#include <bits/stdc++.h>

using namespace std;

#define MAX 5000000

typedef vector <int> vi;

int N;
bool not_prime[MAX + 1];
bool check[MAX + 1];
long long A, B;
vi va, vb;

bool cmp(const int &num1, const int &num2)
{
	return num1 > num2;
}

void Prime()
{
	not_prime[1] = true;
	for (int i = 2; i * i <= MAX; i++)
	{
		if (not_prime[i])
			continue;
		for (int j = i * i; j <= MAX; j += i)
		{
			not_prime[j] = true;
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	Prime();

	int a, b;

	while (N--)
	{
		cin >> a >> b;
		if (not_prime[a])
		{
			if (vb.size() < 3)
				B += 1000;
			else
				B += vb[2];
		}
		else if (check[a])
			A -= 1000;
		else
		{
			check[a] = true;
			if (va.size() < 3)
			{
				va.push_back(a);
				sort(va.begin(), va.end(), cmp);
			}
			else
			{
				if (va[2] < a) 
				{
					va.pop_back();
					va.push_back(a);
					sort(va.begin(), va.end(), cmp);
				}
			}
		}

		if (not_prime[b])
		{
			if (va.size() < 3)
				A += 1000;
			else
				A += va[2];
		}
		else if (check[b])
			B -= 1000;
		else
		{
			check[b] = true;
			if (vb.size() < 3)
			{
				vb.push_back(b);
				sort(vb.begin(), vb.end(), cmp);
			}
			else
			{
				if (vb[2] < b)
				{
					vb.pop_back();
					vb.push_back(b);
					sort(vb.begin(), vb.end(), cmp);
				}
			}
		}
	}

	if (A > B)
		cout << "소수의 신 갓대웅";
	else if (A < B)
		cout << "소수 마스터 갓규성";
	else
		cout << "우열을 가릴 수 없음";

	return 0;
}