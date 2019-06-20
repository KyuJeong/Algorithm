#include <iostream>

using namespace std;

int x;
int hh, mm;
int ans;

bool Lucky()
{
	if (hh % 10 == 7 || hh / 10 == 7 || mm % 10 == 7 || mm / 10 == 7)
		return true;
	else
		return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> x >> hh >> mm;

	while (!Lucky())
	{
		mm -= x;
		if (mm < 0)
		{
			hh--;
			mm += 60;
			if (hh < 0)
				hh += 24;
		}
		ans++;
	}

	cout << ans;

	return 0;
}