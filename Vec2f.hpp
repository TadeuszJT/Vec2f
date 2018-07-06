#ifndef VEC2F_HPP
#define VEC2F_HPP

struct Vec2f {
	float x, y;
	Vec2f();
	Vec2f(float X, float Y);
	
	float len() const;
	float theta() const;
	Vec2f normal() const;

	float dot(Vec2f b) const;
	float thetaTo(Vec2f b) const;
	Vec2f rotated(float rad) const;
	
	void operator += (Vec2f v);
	void operator -= (Vec2f v);
	void operator *= (float f);
	void operator /= (float f);
	
	Vec2f operator + (Vec2f v) const;
	Vec2f operator - (Vec2f v) const;
	Vec2f operator * (float f) const;
	Vec2f operator / (float f) const;
};

#endif
