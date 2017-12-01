#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Matrix/Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTestGeneral
{
	TEST_CLASS(UnitTestGeneral)
	{
	public:

		TEST_METHOD(GeneralMatrixOneDCreatedAndDeleted)
		{
			Matrix *M = CreateGeneralOneDMatrix(10);
			deleteMatrix(M);
		}
		TEST_METHOD(GeneralMatrixTwoDCreatedAndDeleted)
		{
			Matrix *M = CreateGeneralTwoDMatrix(10);
			deleteMatrix(M);
		}
		TEST_METHOD(GeneralMatrixOneDThrowExceptionIfMatrixSizeArgumentIsZero)
		{
			Assert::ExpectException<std::invalid_argument>([]() {CreateGeneralOneDMatrix(0); });
		}
		TEST_METHOD(GeneralMatrixTwoDThrowExceptionIfMatrixSizeArgumentIsZero)
		{
			Assert::ExpectException<std::invalid_argument>([]() {CreateGeneralTwoDMatrix(0); });
		}
		TEST_METHOD(GeneralMatrixOneDInvalidGetFunctionArguments)
		{
			Matrix *M = CreateGeneralOneDMatrix(8);
			Assert::ExpectException <std::invalid_argument>([M]() 
			{get_ij(*M, 10, 0); });
			Assert::ExpectException <std::invalid_argument>([M]() {get_ij(*M, 0, 10); });
			Assert::ExpectException <std::invalid_argument>([M]() {get_ij(*M, 10, 10); });
			deleteMatrix(M);
		}
		TEST_METHOD(GeneralMatrixTwoDInvalidGetFunctionArguments)
		{
			Matrix *M = CreateGeneralTwoDMatrix(12);
			Assert::ExpectException <std::invalid_argument>([M]() {get_ij(*M, 10, 0); });
			Assert::ExpectException <std::invalid_argument>([M]() {get_ij(*M, 0, 10); });
			Assert::ExpectException <std::invalid_argument>([M]() {get_ij(*M, 10, 10); });
			deleteMatrix(M);
		}
		TEST_METHOD(GeneralMatrixOneDInvalidSetFunctionArguments)
		{
			Matrix *M = CreateGeneralOneDMatrix(12);
			Assert::ExpectException <std::invalid_argument>([M]() {set_ij(*M, 16, 0, "Hello"); });
			Assert::ExpectException <std::invalid_argument>([M]() {set_ij(*M, 0, 16, "Hello"); });
			Assert::ExpectException <std::invalid_argument>([M]() {set_ij(*M, 16, 16, "Hello"); });

			deleteMatrix(M);
		}
		TEST_METHOD(GeneralMatrixTwoDInvalidSetFunctionArguments)
		{
			Matrix *M = CreateGeneralTwoDMatrix(12);
			Assert::ExpectException <std::invalid_argument>([M]() {set_ij(*M, 16, 0, "Hello"); });
			Assert::ExpectException <std::invalid_argument>([M]() {set_ij(*M, 0, 16, "Hello"); });
			Assert::ExpectException <std::invalid_argument>([M]() {set_ij(*M, 16, 16, "Hello"); });
			deleteMatrix(M);
		}
		TEST_METHOD(GeneralMatrixOneDSetAndGetFunctionWorkingCorrectly)
		{
			Matrix *M = CreateGeneralOneDMatrix(10);
			set_ij(*M, 1, 1, "Hello");
			Assert::AreEqual<std::string>("Hello", get_ij(*M, 1, 1));
			deleteMatrix(M);
		}
		TEST_METHOD(GeneralMatrixTwoDSetAndGetFunctionWorkingCorrectly)
		{
			Matrix *M = CreateGeneralTwoDMatrix(10);
			set_ij(*M, 1, 1, "Hello");
			Assert::AreEqual<std::string>("Hello", get_ij(*M, 1, 1));
			deleteMatrix(M);
		}
		TEST_METHOD(GeneralMatrixOneDSizeFunctionWorkingCorrectly)
		{
			Matrix *M = CreateGeneralOneDMatrix(8);
			Assert::AreEqual<const int>(8, sizeMatrix(*M));
		}
		TEST_METHOD(GeneralMatrixTwoDSizeFunctionWorkingCorrectly)
		{
			Matrix *M = CreateGeneralTwoDMatrix(10);
			Assert::AreEqual<const int>(8, sizeMatrix(*M));
		}
	};
}