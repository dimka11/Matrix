#include "StringComp.h"
using namespace std;

string TestCase = "Hello";
vector<int> Result;
void CreateMatrixAndSetValues()
{
	Matrix *matrix = CreateGeneralOneDMatrix(3);
	set_ij(*matrix, 0, 0, "Hello");
}



void FindString(std::vector<int>&, It&)
{
	//todo вызов итератора	
}
