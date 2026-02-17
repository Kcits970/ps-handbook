vector<vec2d> cvxh(vector<vec2d> v)
{
	vec2d p0 = *min_element(v.begin(), v.end());
	sort(v.begin(), v.end(), [&p0](auto a, auto b)
	{
		int dir = ccw(p0, a, b);
		return dir ? dir > 0 : p0.dist(a) < p0.dist(b);
	});

	vector<vec2d> h;
	for (vec2d p : v)
	{
		while (h.size() >= 2 && ccw(h[h.size()-2], h.back(), p) <= 0)
			h.pop_back();
		h.push_back(p);
	}
	return h;
}