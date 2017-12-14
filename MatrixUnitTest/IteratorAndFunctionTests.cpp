#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Matrix/TwoDArray.h"
#include "../Matrix/Iterator.h"
#include "../Matrix/FindString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IteratorUnitTest
{
	TEST_CLASS(UnitTestIteratorAndFunction)
	{
	public:

		TEST_METHOD(FindString)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(10); // creating a new matrix
			set_ij(*matrix, 0, 0, "myWordinStringinCell"); // filling in matrix
			std::vector<int> Numstr; // vector contains rows numbers.
			It *it = begin(matrix); // init iterator
			int itCounter = 0; 
			int currentString = 1;
			while (next(*it)) {
				itCounter++;
				if (current(*it).find("myWordinStringinCell"))
				{
					Numstr.push_back(currentString);
					itCounter = 0;
					currentString++;
					// there must be jump to next string
				}
				if (itCounter > sizeMatrix(*it->matrix)) // error: type 'It' is incompleate;
				{
					currentString++;
					itCounter = 0;
				}
			}
			deleteMatrix(matrix);
	}
		TEST_METHOD(IteratorTest)
		{

		}
		
	};
}