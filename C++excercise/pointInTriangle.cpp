#include <iostream>

//�㵽ֱ���ϵ�ͶӰ

/*
�жϵ��Ƿ����������ڣ������ڷ����ᶨ������ֱ�ͶӰ�������ε��������ϣ�
ֻҪ��һ�ߵ�ͶӰ�㲻�������ε�ǰ�ı��ϣ���˵���㲻���������ڲ���
��㵽ֱ���ϵ�ͶӰ��http ://blog.csdn.net/gf771115/article/details/26721055
*/
class vec2
{
	friend float distance(const vec2& A, const vec2& B);
	friend vec2 operator-(vec2 left, const vec2& right);
	friend vec2 operator+(vec2 left, const vec2& right);
	friend float operator*(vec2 left, const vec2& right);
	friend vec2 operator*(float left, const vec2& right);
private:
	float m_x, m_y;
public:
	vec2(float x = 0.0, float y = 0.0)
		: m_x(x), m_y(y)
	{

	}

	vec2& add(const vec2& other)
	{
		m_x += other.m_x;
		m_y += other.m_y;
		return *this;
	}

	vec2& subtract(const vec2& other)
	{
		m_x -= other.m_x;
		m_y -= other.m_y;
		return *this;
	}

	float multiply(const vec2& other)
	{
		return m_x * other.m_x + m_y * other.m_y;
	}

	vec2 projectionOfPoint(const vec2& A, const vec2& B)//AB is a line
	{
		float k = (*this - A) * (B - A) / distance(A, B);
//		return vec2(k * (B - A).m_x + A.m_x, k * (B - A).m_y + A.m_y);
		return k * (B - A) + A;
	}

};

vec2 operator-(vec2 left, const vec2& right)
{
	return left.subtract(right);
}

vec2 operator+(vec2 left, const vec2& right)
{
	return left.add(right);
}

float operator*(vec2 left, const vec2& right)
{
	return left.multiply(right);
}

vec2 operator*(float left, const vec2& right)
{
	return vec2(left * right.m_x, left * right.m_y);
}


float distance(const vec2& A, const vec2& B)
{
	return (A.m_x - B.m_x) * (A.m_x - B.m_x) + (A.m_y - B.m_y) * (A.m_y - B.m_y);
}

bool pointInLine(const vec2& P, const vec2& A, const vec2& B)//P�ǵ���AB�ϵ�ͶӰ��
//�ж�ͶӰ���ڲ����߶���
{
	if (distance(P, A) > distance(A, B))
		return false;
//	std::cout << "true" << std::endl;
	return true;
}

float main()
{
	vec2 A(0, 0);
	vec2 B(2, 0);
	vec2 C(2, 2);
	vec2 P(3, 1);

	if (pointInLine(P.projectionOfPoint(A, B), A, B) && pointInLine(P.projectionOfPoint(B, C), B, C) && pointInLine(P.projectionOfPoint(C, A), C, A))
		std::cout << "P in triangle" << std::endl;
	else
		std::cout << "P not in triangle" << std::endl;
	std::cin.get();
}