#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> v;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	vector <int> arr(N);
	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}

	M--;
	int idx = M;
	int mod = N;

	cout << "<";

	while (--N > 0)
	{
		cout << arr[idx] << ", ";
		arr.erase(arr.begin() + idx);
		idx += M;
		idx %= N;
		mod--;
	}

	cout << arr[0] << ">";

	return 0;
}