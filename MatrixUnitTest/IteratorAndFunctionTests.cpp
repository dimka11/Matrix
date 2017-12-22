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

		TEST_METHOD(IteratorTest)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(2);
			set_ij(*matrix, 0, 0, "Hello");
			set_ij(*matrix, 0, 1, "String");
			set_ij(*matrix, 1, 0, "String");
			set_ij(*matrix, 1, 1, "String");

			It *iterator = begin(matrix);
			for (size_t i = 0; i < 2; ++i)
			{
				Assert::IsTrue(next(iterator));
			}
			for (size_t i = 0; i < 4; ++i)
			{
				Assert::IsFalse(next(iterator)); //Message: Îøèáêà Assert
			}
			//delete &iterator;	// C0000005
			deleteMatrix(matrix);
		}
		TEST_METHOD(IteratorCount)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(3);
			set_ij(*matrix, 0, 0, "Hello");
			It *iterator = begin(matrix);
			int itCounterTest = 0;
			while(next(iterator))
			{
				itCounterTest++;
				//std::string TestString = current(iterator);
			}
			Assert::AreEqual(3, itCounterTest);
			deleteMatrix(matrix);
		}
		TEST_METHOD(IteratorEqualValues)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(2);
			set_ij(*matrix, 0, 0, "1");
			set_ij(*matrix, 0, 1, "2");
			set_ij(*matrix, 1, 0, "3");
			set_ij(*matrix, 1, 1, "4");
			It *iterator = begin(matrix);
			int itCounterTest = 0;
			while (next(iterator))
			{
				std::string TestString = current(iterator);
				//Assert::AreEqual(itCounterTest + 1, std::stoi(TestString));
				itCounterTest++;
			}
		}
		TEST_METHOD(FindStringTest)
		{
		
		}
	};
}