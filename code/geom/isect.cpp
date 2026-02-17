bool isect(vec2d a, vec2d b, vec2d c, vec2d d)
{
	int o1 = ccw(a, b, c) * ccw(a, b, d);
	int o2 = ccw(c, d, a) * ccw(c, d, b);
	if (!o1 && !o2)
	{
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return b >= c || d >= a;
	}
	return o1 <= 0 && o2 <= 0;
}