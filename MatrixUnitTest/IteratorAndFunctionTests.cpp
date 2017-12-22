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
			const int MS = 10;
			Matrix *matrix = CreateGeneralOneDMatrix(MS);
			set_ij(*matrix, 0, 0, "Hello");
			std::vector<int> Numstr;
			It *it = begin(matrix); 
			int itCounter = 0; 
			int currentString = 1;
			while (next(*it)) {
				++itCounter;
				if ((std::find(Numstr.begin(), Numstr.end(), currentString) != Numstr.end()) == false)
				{
					if (current(*it).find("Hello"))
					{
						Numstr.push_back(currentString);
						itCounter = 0;
						++currentString;
					}
					if (itCounter > MS)
					{
						currentString++;
						itCounter = 0;
					}
				}
				//todo проверяем, что текущая строка не находится в векторе
				//todo FALSE переходим к следующему элементу
				//todo TRUE проверяем элемент (добавляем в вектор)
				//todo Проверяем счетчик итератора, ++счетчик строки
			}
			delete &it;
			deleteMatrix(matrix);
		}

		TEST_METHOD(IteratorIsCreated)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(2);
			It *iterator = begin(matrix);
			//todo 
		}
		TEST_METHOD(IteratorCount)
		{

		}
		TEST_METHOD(FindString)
		{

		}
		TEST_METHOD(IteratorTest)
		{
			Matrix *matrix = CreateGeneralOneDMatrix(2);
			It *iterator = begin(matrix);
			Assert::IsTrue(next(*iterator));
			delete &iterator;
			deleteMatrix(matrix);
		}
	};
}