#include "FindString.h"
#include "Iterator.h"
using namespace std;

int const MS = 3;
std::vector<int> Numstr;

void FindString(Matrix *matrix, std::vector<int> &Numstr)
{	
	It *it = begin(matrix);
	int MS = sizeMatrix(*matrix);
	int itCounter = 0;
	int currentString = 1;
	while (next(it)) {
		++itCounter;
		if ((std::find(Numstr.begin(), Numstr.end(), currentString) != Numstr.end()) == false)
		{
			if ((current(it).find("Hello")) != std::string::npos)
			{
				Numstr.push_back(currentString);
			}
		}
		if (itCounter == MS)
		{
			++currentString;
			itCounter = 0;
		}
	}
	delete it;
	deleteMatrix(matrix);
}