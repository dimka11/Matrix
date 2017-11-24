#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Matrix/OneDArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTest
{		
	TEST_CLASS(UnitTestOneDMatrix)
	{
	public:

		TEST_METHOD(OneDMatrixCreatedAndDeleted)
		{	
			OneDMatrix *m = CreateOneDMatrix(10);
			deleteOneDMatrix(m);
		}	// мы можем тестировать отдельно удаление и создание матрицы?
		TEST_METHOD(ThrowExceptionIfMatrixSizeArgumentIsZero)
		{
			Assert::ExpectException<std::invalid_argument>([]() {CreateOneDMatrix(0); });
		}
		TEST_METHOD(InvalidGetFunctionArguments)
		{
			OneDMatrix* Matrix = CreateOneDMatrix(8);
			Assert::ExpectException<std::invalid_argument>([Matrix]() {get_ijOneDMatrix(Matrix, 10, 0); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {get_ijOneDMatrix(Matrix, 0, 10); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {get_ijOneDMatrix(Matrix, 10, 10); });
			deleteOneDMatrix(Matrix);
		}
		TEST_METHOD(InvalidSetFunctionArguments)
		{
			OneDMatrix* Matrix = CreateOneDMatrix(8);
			Assert::ExpectException<std::invalid_argument>([Matrix]() {set_ijOneDMatrix(Matrix, 10, 0, "Hello"); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {set_ijOneDMatrix(Matrix, 0, 10, "Hello"); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {set_ijOneDMatrix(Matrix, 10, 10, "Hello"); });
			deleteOneDMatrix(Matrix);
		}
		TEST_METHOD(SetAndGetFunctionWorkingCorrectly)
		{
			OneDMatrix* Matrix = CreateOneDMatrix(3);
			set_ijOneDMatrix(Matrix, 1, 1, "Hello");
			Assert::AreEqual<std::string>(get_ijOneDMatrix(Matrix, 1, 1), "Hello");
			deleteOneDMatrix(Matrix);
		}
		TEST_METHOD(GetSizeFunctionWorkingCorrectly)
		{
			OneDMatrix* Matrix = CreateOneDMatrix(8);
			Assert::AreEqual<int>(sizeOneDMatrix(Matrix), 8);
			deleteOneDMatrix(Matrix);
		}
	};
}