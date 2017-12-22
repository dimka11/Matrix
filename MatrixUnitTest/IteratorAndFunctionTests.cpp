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
			for (size_t i = 0; i < 3; ++i)
			{
				Assert::IsFalse(next(iterator));
			}
			delete &iterator;
			deleteMatrix(matrix);
		}
		TEST_METHOD(IteratorCount)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(3);
			It *iterator = begin(matrix);
			int itCounter = 0;
			while(next(iterator))
			{
				itCounter++;
			}
			Assert::AreEqual(6, itCounter);

			deleteMatrix(matrix);
		}
		TEST_METHOD(FindString)
		{


		}
	};
}