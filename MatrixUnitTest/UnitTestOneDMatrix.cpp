#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Matrix/OneDArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTest1D
{		
	TEST_CLASS(UnitTestOneDMatrix)
	{
	public:

		TEST_METHOD(OneDMatrixCreatedAndDeleted)
		{	
			OneDMatrix *m = CreateOneDMatrix(10);
			deleteOneDMatrix(m);
		}
		TEST_METHOD(OneDMatrixThrowExceptionIfMatrixSizeArgumentIsZero)
		{
			Assert::ExpectException<std::invalid_argument>([]() {CreateOneDMatrix(0); });
		}
		TEST_METHOD(OneDMatrixInvalidGetFunctionArguments)
		{
			OneDMatrix* Matrix = CreateOneDMatrix(8);
			Assert::ExpectException<std::invalid_argument>([Matrix]() {get_ijOneDMatrix(Matrix, 10, 0); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {get_ijOneDMatrix(Matrix, 0, 10); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {
				get_ijOneDMatrix(Matrix, 10, 10); 
			});
			deleteOneDMatrix(Matrix);
		}
		TEST_METHOD(OneDMatrixInvalidSetFunctionArguments)
		{
			OneDMatrix* Matrix = CreateOneDMatrix(8);
			Assert::ExpectException<std::invalid_argument>([Matrix]() {set_ijOneDMatrix(Matrix, 10, 0, "Hello"); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {set_ijOneDMatrix(Matrix, 0, 10, "Hello"); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {set_ijOneDMatrix(Matrix, 10, 10, "Hello"); });
			deleteOneDMatrix(Matrix);
		}
		TEST_METHOD(OneDMatrixSetAndGetFunctionWorkingCorrectly)
		{
			OneDMatrix* Matrix = CreateOneDMatrix(3);
			set_ijOneDMatrix(Matrix, 1, 1, "Hello");
			Assert::AreEqual<std::string>("Hello", get_ijOneDMatrix(Matrix, 1, 1));
			deleteOneDMatrix(Matrix);
		}
		TEST_METHOD(OneDMatrixGetSizeFunctionWorkingCorrectly)
		{
			OneDMatrix* Matrix = CreateOneDMatrix(8);
			Assert::AreEqual<int>(8, sizeOneDMatrix(Matrix));
			deleteOneDMatrix(Matrix);
		}
	};
}