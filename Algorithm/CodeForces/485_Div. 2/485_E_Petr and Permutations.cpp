#include <iostream>
using namespace std;

int N;
int A[500001];
int B[500001];
long long swap_count;

void merge(int start, int end)
{
	int mid = (start + end) / 2;

	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end)
	{
		if (A[i] <= A[j])
			B[k++] = A[i++];
		else
		{
			B[k++] = A[j++];
			swap_count += mid - i + 1;
		}
	}

	while (j <= end)
	{
		B[k++] = A[j++];
		swap_count += mid - i + 1;
	}

	while (i <= mid)
		B[k++] = A[i++];

	for (int i = start; i <= end; i++)
	{
		A[i] = B[i - start];
	}
}

void sort(int start, int end)
{
	if (start == end)
		return;

	int mid = (start + end) / 2;

	sort(start, mid);
	sort(mid + 1, end);
	merge(start, end);
}


int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	sort(1, N);

	if (N % 2 == 0)
	{
		if (swap_count % 2 == 0)
			cout << "Petr";
		else
			cout << "Um_nik";
	}
	else
	{
		if (swap_count % 2 == 0)
			cout << "Um_nik";
		else
			cout << "Petr";
	}


	return 0;
}