int gcd(int u, int v)
{
	while (v != 0)
	{
		int r = u % v;
		u = v;
		v = r;
	}
	return u;
}