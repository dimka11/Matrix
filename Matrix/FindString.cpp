#include "FindString.h"
using namespace std;

void CreateMatrixAndSetValues()
{
	Matrix *matrix = CreateGeneralOneDMatrix(3);
	set_ij(*matrix, 0, 0, "Hello");
}

string TestCase = "Hello";
vector<int> Result;

void FindString(std::vector<int> &Result, It &it, string StringForFind)
{

	//todo вызов итератора	
}

void MyF()
{
	FindString(Result, "Hello", it);
}