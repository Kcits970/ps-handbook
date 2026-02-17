int sgn(ll x)
{
	return x > 0 ? 1 : x < 0 ? -1 : 0;
}

int ccw(vec2d a, vec2d b, vec2d c)
{
	return sgn((b-a).cross(c-b));
}