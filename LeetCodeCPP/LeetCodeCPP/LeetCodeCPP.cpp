

#include <iostream>

#include "ContainerWithMostWater.h"

int main()
{
	Solution s;

	auto PrintResult = [](Solution& s, std::vector<int>& v)
	{
		std::cout << "{ ";
		for (const int& i : v)
		{
			std::cout << i << ", ";
		}
		std::cout << "} => MaxArea = " << s.maxArea(v) << std::endl;
	};
	std::vector<int> height1 = { 1,8,6,2,5,4,8,3,7 };//49
	std::vector<int> height2 = { 1,1 };//1
	std::vector<int> height3 = { 8,1,9,6,7,8,7 };//42
	std::vector<int> height4 = { 1,1000,1000,6,2,5,4,8,3,7 };//1000
	std::vector<int> height5 = { 1,2,1 };//2
	std::vector<int> height6 = { 2,3,4,5,18,17,6 };//17
	PrintResult(s, height1);
	PrintResult(s, height2);
	PrintResult(s, height3);
	PrintResult(s, height4);
	PrintResult(s, height5);
	PrintResult(s, height6);

	system("pause");
}
