

#include <iostream>

#include "LongestCommonPrefix.h"

int main()
{
	Solution s;
	std::vector<std::string> first = { "flower", "flow", "flight" };
	std::vector<std::string> second = { "a" };
	std::vector<std::string> third = { "dog", "done", "dug" };
	std::vector<std::string> fourth = { "dog", "", "dug" };
	std::vector<std::string> fifth = { "aaa", "aa", "aaa" };
	std::vector<std::string> sixth = { "c","acc","ccc" };
	std::vector<std::string> seventh = { "ab", "a" };
	std::vector<std::string> eight = { "reflower","flow","flight" };
	std::vector<std::string> ninth = { "cir","car" };

	auto printVector = [](std::vector<std::string> v)
	{
		std::cout << "[";
		for (auto& str : v)
		{
			std::cout << str << ", ";
		}
		std::cout << "]  ";
	};

	printVector(first); 
	std::cout << s.longestCommonPrefix(first) << std::endl;

	printVector(second); 
	std::cout << s.longestCommonPrefix(second) << std::endl;

	printVector(third); 
	std::cout << s.longestCommonPrefix(third) << std::endl;

	printVector(fourth); 
	std::cout << s.longestCommonPrefix(fourth) << std::endl;

	printVector(fifth); 
	std::cout << s.longestCommonPrefix(fifth) << std::endl;

	printVector(sixth); 
	std::cout << s.longestCommonPrefix(sixth) << std::endl;

	printVector(seventh); 
	std::cout << s.longestCommonPrefix(seventh) << std::endl;

	printVector(eight); 
	std::cout << s.longestCommonPrefix(eight) << std::endl;

	printVector(ninth); 
	std::cout << s.longestCommonPrefix(ninth) << std::endl;

	system("pause");
}
