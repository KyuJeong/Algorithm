#include <iostream>

using namespace std;

int h, m, s;
int n;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> h >> m >> s >> n;

	int as = n % 60;
	int am = n / 60;

	int ns = s + as;
	if (ns > 59)
	{
		ns %= 60;
		am++;
	}
	int nm = m + am;
	int ah = nm / 60;
	if (nm > 59)
		nm %= 60;

	int nh = h + ah;
	if (nh > 23)
		nh %= 24;

	cout << nh << " " << nm << " " << ns;

	return 0;
}