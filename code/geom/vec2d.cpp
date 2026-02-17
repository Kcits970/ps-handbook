struct vec2d
{
	ll x, y;
	vec2d() {}
	vec2d(ll x, ll y): x(x), y(y) {}
	bool operator<(vec2d a) const {return x == a.x ? y < a.y : x < a.x;}
	bool operator<=(vec2d a) const {return x == a.x ? y <= a.y : x < a.x;}
	bool operator>(vec2d a) const {return a < *this;}
	bool operator>=(vec2d a) const {return a <= *this;}
	vec2d operator+(vec2d a) const {return vec2d(x+a.x, y+a.y);}
	vec2d operator-(vec2d a) const {return vec2d(x-a.x, y-a.y);}
	vec2d operator-() const {return vec2d(-x, -y);}
	vec2d operator*(ll a) const {return vec2d(a*x, a*y);}
	ll dot(vec2d a) const {return x*a.x+y*a.y;}
	ll cross(vec2d a) const {return x*a.y-y*a.x;}
	ll dist(vec2d a) const {return (x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);}
};