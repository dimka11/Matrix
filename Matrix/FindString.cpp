#include "FindString.h"
using namespace std;

int const MS = 3;
std::vector<int> Numstr;
void MainFunction()
{
	Matrix *matrix = CreateGeneralOneDMatrix(MS);
	set_ij(*matrix, 0, 0, "Hello");
}

void FindString(Matrix *matrix, int MS, std::vector<int> &Numstr)
{	
	It *it = begin(matrix);
	int itCounter = 0;
	int currentString = 1;
	while (next(it)) {
		++itCounter;
		if ((std::find(Numstr.begin(), Numstr.end(), currentString) != Numstr.end()) == false)
		{
			if (current(it).find("Hello"))
			{
				Numstr.push_back(currentString);
				//itCounter = 0;
				//++currentString;
			}
			if (itCounter > MS)
			{
				++currentString;
				itCounter = 0;
			}
		}
		//todo ���������, ��� ������� ������ �� ��������� � �������
		//todo FALSE ��������� � ���������� ��������
		//todo TRUE ��������� ������� (��������� � ������)
		//todo ��������� ������� ���������, ++������� ������
	}
	delete it;
	deleteMatrix(matrix);
}