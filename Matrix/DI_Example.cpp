#include <map>
#include <iostream>

void h()
{
	std::cout << "Hello";
}
typedef void(*action)();
action arr[10];
//std::map<std::string, action> actions;
std::map<char, action> actions;
//std::string CODE;
char CODE;
void MyFunc()
{
	std::cin >> CODE;
	/*
	actions[CODE]{
	}
	*/
}