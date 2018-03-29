#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair <int, string> pis;

int Q;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	pis album[] = {
		{ 1967, "DavidBowie" },
		{ 1969, "SpaceOddity" },
		{ 1970, "TheManWhoSoldTheWorld" },
		{ 1971, "HunkyDory" },
		{ 1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars" },
		{ 1973, "AladdinSane" },
		{ 1973, "PinUps" },
		{ 1974, "DiamondDogs" },
		{ 1975, "YoungAmericans" },
		{ 1976, "StationToStation" },
		{ 1977, "Low" },
		{ 1977, "Heroes" },
		{ 1979, "Lodger" },
		{ 1980, "ScaryMonstersAndSuperCreeps" },
		{ 1983, "LetsDance" },
		{ 1984, "Tonight" },
		{ 1987, "NeverLetMeDown" },
		{ 1993, "BlackTieWhiteNoise" },
		{ 1995, "1.Outside" },
		{ 1997, "Earthling" },
		{ 1999, "Hours" },
		{ 2002, "Heathen" },
		{ 2003, "Reality" },
		{ 2013, "TheNextDay" },
		{ 2016, "BlackStar" }
	};

	cin >> Q;

	while (Q--)
	{
		int S, E;

		cin >> S >> E;

		vector <pis> ans;

		for (int i = 0; i < 25; i++)
		{
			if (album[i].first >= S && album[i].first <= E)
				ans.push_back(album[i]);
		}

		cout << ans.size() << "\n";
		for (auto i : ans)
		{
			cout << i.first << " " << i.second << "\n";
		}

	}

	return 0;
}

