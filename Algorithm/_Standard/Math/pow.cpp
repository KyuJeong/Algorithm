typedef long long ll;
ll power(ll base, ll exp) {
	ll ret = 1;

	while (exp)	{
		if (exp & 1)
			ret *= base;
		exp >>= 1;
		base *= base;
	}
	return ret;
}