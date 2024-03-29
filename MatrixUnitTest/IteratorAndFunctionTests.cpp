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

		TEST_METHOD(CreateAndNextIterator)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(2);
			set_ij(*matrix, 0, 0, "Hello");
			set_ij(*matrix, 0, 1, "String");
			set_ij(*matrix, 1, 0, "String");
			set_ij(*matrix, 1, 1, "String");

			It *iterator = begin(matrix);
			for (size_t i = 0; i < 4; ++i)
			{
				Assert::IsTrue(next(iterator),L"NextIsReturnFalseWhereIteratorInShouldBeInMatrix");
			}
			for (size_t i = 4; i < 10; ++i)
			{
				Assert::IsFalse(next(iterator),L"NextIsReturnTrueWhereMatrixIsEnd");
			}
			deleteIterator(iterator);
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
			}
			Assert::AreEqual(16, itCounterTest, L"IteratorsCountIsNotCorrect");
			deleteMatrix(matrix);
			deleteIterator(iterator);
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

			//while (IsNotDone(iterator))
			while (next(iterator))
			{
				++itCounterTest;
				std::string TestString = current(iterator);
				Assert::AreEqual(itCounterTest, std::stoi(TestString),L"ValueGottenByIteratorIsNotCorrect");
				//next(iterator);
			}
			deleteMatrix(matrix);
			deleteIterator(iterator);
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
			Assert::AreEqual(1, Numstr.at(0),L"FirstStringNumberNotInVector");
			Assert::AreEqual(3, Numstr.at(1),L"ThirdStringNumberNotInVector");
			Assert::AreEqual<int>(2, Numstr.size(),L"VectorSizeIsNotCorrect");
		}
		TEST_METHOD(FindStringInOneCellMatrix)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(3);
			set_ij(*matrix, 0, 0, "World");
			std::vector<int> Numstr;
			FindString(matrix, Numstr);
			Assert::IsTrue((std::find(Numstr.begin(), Numstr.end(), 1) != Numstr.end()) == false, L"StringNumberNotShouldBeInVectorButItsFound");
			
			Matrix *matrix1 = CreateGeneralOneDMatrix(3);
			set_ij(*matrix1, 0, 0, "Hello");
			std::vector<int> Numstr1;
			FindString(matrix1, Numstr1);
			if (Numstr1.size() >0)
			{
				Assert::AreEqual(1, Numstr1.at(0), L"StringNumberNotEqualComparedStoredInVector");
			}
			else Assert::Fail(L"StringNumberShouldBeInVectorButVectorIsEmpty");
		}
	};
}