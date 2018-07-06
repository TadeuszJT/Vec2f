#include "Vec2f.hpp"
#include <cmath>
using namespace std;

Vec2f::Vec2f() {
	x = 0;
	y = 0;
}

Vec2f::Vec2f(float X, float Y) {
	x = X;
	y = Y;
}

float
Vec2f::len() const {
	return sqrt(x*x + y*y);
}

float
Vec2f::theta() const {
	return atan2(y, x);
}

Vec2f
Vec2f::normal() const {
	float l = len();
	if (isnormal(l)) { // positive len
		float inv = 1.0/l;
		return Vec2f(x*inv, y*inv);
	}
	else if (isinf(l)) { // infinite len
		if (!isinf(x)) {
			return Vec2f(0, y>0 ? 1:-1);
		} else if (!isinf(y)) {
			return Vec2f(x>0 ? 1:-1, 0);
		} else {
			return Vec2f(0, 0);
		}
	}
	else { // 0 or nan len
		return Vec2f(0, 0);
	}
}

float
Vec2f::dot(Vec2f b) const {
	return x*b.x + y*b.y;
}

float
Vec2f::thetaTo(Vec2f b) const {
	return atan2f(x*b.y-y*b.x, x*b.x+y*b.y);
}

Vec2f
Vec2f::rotated(float rad) const {
	const float s = sin(rad);
	const float c = cos(rad);
	return Vec2f(c*x - s*y, s*x + c*y);
}

void
Vec2f::operator += (Vec2f v) {
	x += v.x;
	y += v.y;
}

void
Vec2f::operator -= (Vec2f v) {
	x -= v.x;
	y -= v.y;
}

void
Vec2f::operator *= (float f) {
	x *= f;
	y *= f;
}

void 
Vec2f::operator /= (float f) {
	const float inv = 1.0 / f;
	x *= inv;
	y *= inv;
}

Vec2f
Vec2f::operator + (Vec2f v) const {
	return Vec2f(x+v.x, y+v.y);
}

Vec2f
Vec2f::operator - (Vec2f v) const {
	return Vec2f(x-v.x, y-v.y);
}

Vec2f
Vec2f::operator * (float f) const {
	return Vec2f(x*f, y*f);
}

Vec2f
Vec2f::operator / (float f) const {
	const float inv = 1.0 / f;
	return Vec2f(x*inv, y*inv);
}

