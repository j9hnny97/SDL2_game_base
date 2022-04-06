#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2
{
public:
	Vec2()
		: _x(0.0f)
		, _y(0.0f)
	{
	}

	Vec2(float xArg, float yArg)
		: _x(xArg)
		, _y(yArg)
	{
	}

	float getX() { return _x; }
	float getY() { return _y; }

	bool operator==(Vec2 cosnt& other)
	{
		return _x < 
	}

private:
	float _x;
	float _y;
};

#endif