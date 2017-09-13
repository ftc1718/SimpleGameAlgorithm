#include <iostream>
#include <vector>

//给定4个点 判断是否能构成正方形
/*
判断给点的点能够构成正方形： 对角线垂直且相等。
将四个点按横坐标排序则连接横坐标最小，最大点可构成一个对角线
*/

int distance(int x, int y, int u, int v)
{
	return (u - x) * (u - x) + (v - y) * (v - y);
}

int main()
{
	int cnt;
	std::cin >> cnt;
	while (cnt--)
	{
		std::vector<int> positionX;
		std::vector<int> positionY;
		for (int i = 0; i < 4; i++)
		{
			int num;
			std::cin >> num;
			positionX.push_back(num);
		}

		for (int i = 0; i < 4; i++)
		{
			int num;
			std::cin >> num;
			positionY.push_back(num);
		}

		int minI = 0;
		int maxI = 0;
		for (int i = 1; i < 4; i++)
		{
			if (positionX[i] < positionX[minI])
				minI = i;
			else if (positionX[i] > positionX[minI])
				maxI = i;
		}

		int tmp = positionX[0];
		positionX[0] = positionX[minI];
		positionX[minI] = tmp;

		tmp = positionY[0];
		positionY[0] = positionY[minI];
		positionY[minI] = tmp; 
		
		tmp = positionX[3];
		positionX[3] = positionX[maxI];
		positionX[maxI] = tmp;

		tmp = positionY[3];
		positionY[3] = positionY[maxI];
		positionY[maxI] = tmp;

		int disA = distance(positionX[0], positionY[0], positionX[3], positionY[3]);
		int disB = distance(positionX[1], positionY[1], positionX[2], positionY[2]);

		int dot = (positionX[3] - positionX[0]) * (positionX[2] - positionX[1]) + (positionY[3] - positionY[0]) * (positionY[2] - positionY[1]);
		if((disA == disB) && (dot == 0))
		{
			std::cout << "YES" << std::endl;
		}
		else
			std::cout << "NO" << std::endl;
	}
	return 0;
}