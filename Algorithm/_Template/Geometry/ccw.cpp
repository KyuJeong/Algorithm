double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	double ret = x1 * y2 + x2 * y3 + x3 * y1;
	ret += (-y1 * x2 - y2 * x3 - y3 * x1);
	return ret / 2;
}