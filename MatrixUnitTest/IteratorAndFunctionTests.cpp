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

		TEST_METHOD(TemporalyIteratorTest)
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
			for (size_t i = 0; i < 3; ++i)
			{
				//Assert::IsFalse(next(iterator)); //Message: Îøèáêà Assert
			}
			delete iterator;
			deleteMatrix(matrix);
		}
		TEST_METHOD(IteratorCount)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(4);
			set_ij(*matrix, 0, 0, "Hello");
			It *iterator = begin(matrix);
			int itCounterTest = 0;
			while(next(iterator))
			{
				++itCounterTest;
				//std::string TestString = current(iterator);
			}
			Assert::AreEqual(16, itCounterTest);
			deleteMatrix(matrix);
		}
		TEST_METHOD(IteratorEqualValues)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(3);
			set_ij(*matrix, 0, 0, "1");
			set_ij(*matrix, 0, 1, "2");
			set_ij(*matrix, 0, 2, "3");
			set_ij(*matrix, 1, 0, "4");
			set_ij(*matrix, 1, 1, "5");
			set_ij(*matrix, 1, 2, "6");
			set_ij(*matrix, 2, 0, "7");
			set_ij(*matrix, 2, 1, "8");
			set_ij(*matrix, 2, 2, "9");
			It *iterator = begin(matrix);
			int itCounterTest = 0;
			
			while (next(iterator))
			{
				++itCounterTest;
				std::string TestString = current(iterator);
				Assert::AreEqual(itCounterTest, std::stoi(TestString));
			}
		}
		TEST_METHOD(FindStringTest)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(3);
			set_ij(*matrix, 0, 0, "Hello");
			set_ij(*matrix, 0, 1, "World");
			set_ij(*matrix, 0, 2, "World");
			set_ij(*matrix, 1, 0, "World");
			set_ij(*matrix, 1, 1, "World");
			set_ij(*matrix, 1, 2, "World");
			set_ij(*matrix, 2, 0, "World");
			set_ij(*matrix, 2, 1, "World");
			set_ij(*matrix, 2, 2, "Hello");

			std::vector<int> Numstr;
			FindString(matrix, Numstr);
			Assert::AreEqual(1, Numstr.at(0));
			Assert::AreEqual(3, Numstr.at(1));
			Assert::AreEqual<int>(2, Numstr.size());
		}
	};
}