#include <iostream>
#include <memory>

class String
{
private:
	char* m_str;
	unsigned int m_size;
public:
	String(const char* str)
	{
		m_size = strlen(str);
		m_str = new char[m_size + 1];
		memcpy(m_str, str, m_size + 1);
//		m_str[m_size] = 0;
	}

	String(const String& other)//deep copy
		: m_size(other.m_size)
	{
		m_str = new char[m_size + 1];
		memcpy(m_str, other.m_str, m_size + 1);
	}

	~String()
	{
		delete[] m_str;
	}

	char& operator[](unsigned int index)
	{
		return m_str[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_str;
	return stream;
}


int main()
{
	String first("hello");
	String second = first;

	second[2] = 'A';
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cin.get();
}