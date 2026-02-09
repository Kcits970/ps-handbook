struct vec2d
{
	ll x, y;
	vec2d() {}
	vec2d(ll x, ll y): x(x), y(y) {}
	bool operator<(vec2d a) {return x == a.x ? y < a.y : x < a.x;}
	bool operator<=(vec2d a) {return x == a.x ? y <= a.y : x < a.x;}
	bool operator>(vec2d a) {return a < *this;}
	bool operator>=(vec2d a) {return a <= *this;}
	vec2d operator+(vec2d a) {return vec2d(x+a.x, y+a.y);}
	vec2d operator-(vec2d a) {return vec2d(x-a.x, y-a.y);}
	vec2d operator-() {return vec2d(-x, -y);}
	vec2d operator*(ll a) {return vec2d(a*x, a*y);}
	ll dot(vec2d a) {return x*a.x+y*a.y;}
	ll cross(vec2d a) {return x*a.y-y*a.x;}
};

int sgn(ll x)
{
	return x > 0 ? 1 : x < 0 ? -1 : 0;
}

int ccw(vec2d a, vec2d b, vec2d c)
{
	return sgn((b-a).cross(c-b));
}

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