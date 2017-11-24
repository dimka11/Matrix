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
			
		}
		TEST_METHOD(GeneralMatrixTwoDInvalidGetFunctionArguments)
		{
			
		}
		TEST_METHOD(GeneralMatrixOneDInvalidSetFunctionArguments)
		{

		}
		TEST_METHOD(GeneralMatrixTwoDInvalidSetFunctionArguments)
		{

		}
		TEST_METHOD(GeneralMatrixOneDSetAndGetFunctionWorkingCorrectly)
		{

		}
		TEST_METHOD(GeneralMatrixTwoDSetAndGetFunctionWorkingCorrectly)
		{

		}
		TEST_METHOD(GeneralMatrixOneD)
		{

		}
		TEST_METHOD(GeneralMatrixTwoD)
		{

		}
	};
	
}