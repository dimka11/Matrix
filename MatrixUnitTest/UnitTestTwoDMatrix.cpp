#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Matrix/TwoDArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTest2D
{
	TEST_CLASS(UnitTestTwoDDMatrix)
	{
	public:

		TEST_METHOD(TwoDMatrixCreatedAndDeleted)
		{
			TwoDMatrix *Matrix = CreateTwoDMatrix(10);
			deleteTwoDMatrix(Matrix);
		}
		TEST_METHOD(TwoDMatrixThrowExceptionIfMatrixSizeArgumentIsZero)
		{
			Assert::ExpectException<std::invalid_argument>([]() {CreateTwoDMatrix(0); });
		}
		TEST_METHOD(TwoDMatrixInvalidGetFunctionArguments)
		{
			TwoDMatrix *Matrix = CreateTwoDMatrix(8);
			Assert::ExpectException<std::invalid_argument>([Matrix]() {get_ijTwoDMatrix(Matrix, 10, 0); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {get_ijTwoDMatrix(Matrix, 0, 10); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {get_ijTwoDMatrix(Matrix, 10, 10); });
			deleteTwoDMatrix(Matrix);
		}
		TEST_METHOD(TwoDMatrixInvalidSetFunctionArguments)
		{
			TwoDMatrix *Matrix = CreateTwoDMatrix(8);
			Assert::ExpectException<std::invalid_argument>([Matrix]() {set_ijTwoDMatrix(Matrix, 10, 0, "Hello"); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {set_ijTwoDMatrix(Matrix, 0, 10, "Hello"); });
			Assert::ExpectException<std::invalid_argument>([Matrix]() {set_ijTwoDMatrix(Matrix, 10, 10, "Hello"); });
			deleteTwoDMatrix(Matrix);
		}
		TEST_METHOD(TwoDMatrixSetAndGetFunctionWorkingCorrectly)
		{
			TwoDMatrix *Matrix = CreateTwoDMatrix(10);
			set_ijTwoDMatrix(Matrix, 1, 1, "Hello");
			Assert::AreEqual<std::string>("Hello", get_ijTwoDMatrix(Matrix, 1, 1));
			deleteTwoDMatrix(Matrix);
		}
		TEST_METHOD(TwoDMatrixGetSizeFunctionWorkingCorrectly)
		{
			TwoDMatrix *Matrix = CreateTwoDMatrix(10);
			Assert::AreEqual<int>(10, sizeTwoDMatrix(Matrix));
			deleteTwoDMatrix(Matrix);
		}
	};
}