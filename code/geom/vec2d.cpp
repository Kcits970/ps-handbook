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