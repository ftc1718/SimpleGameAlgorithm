#include <iostream>
#include <vector>

//����4���� �ж��Ƿ��ܹ���������
/*
�жϸ���ĵ��ܹ����������Σ� �Խ��ߴ�ֱ����ȡ�
���ĸ��㰴���������������Ӻ�������С������ɹ���һ���Խ���
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