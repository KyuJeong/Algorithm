#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int countMeeting;
int preEndTime;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
		return a.first < b.first;
	else
		return false;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;

	vector <pair <long long, long long>> tme(n);

	for (int i = 0; i < n; i++)
	{
		cin >> tme[i].first >> tme[i].second;
	}

	sort(tme.begin(), tme.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		if (tme[i].first >= preEndTime)
		{
			preEndTime = tme[i].second;
			countMeeting++;
		}
	}

	cout << countMeeting;

	return 0;
}