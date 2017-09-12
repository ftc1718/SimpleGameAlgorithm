#include <iostream>

class Entity
{
private:
	int m_x;
	int m_y;

	Entity(int x, int y)
		: m_x(x), m_y(y)
	{

	}

	Entity(const Entity& obj)
	{
		m_x = obj.m_x;
		m_y = obj.m_y;
	}

	Entity& operator=(const Entity& obj)
	{
		m_x = obj.m_x;
		m_y = obj.m_y;
		return *this;
	}

	~Entity()
	{

	}
};