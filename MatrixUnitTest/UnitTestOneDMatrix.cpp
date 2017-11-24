#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Matrix/OneDArray.h"
#include "../Matrix/TwoDArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(OneDMatrixCreatedAndDeleted)
		{	
			OneDMatrix *m = CreateOneDMatrix(10);
			deleteOneDMatrix(m);
		}	
		TEST_METHOD(ThrowExceptionIfMatrixSizeArgumentIsZero)
		{
			Assert::ExpectException<std::invalid_argument>([]() {CreateOneDMatrix(0); });
		}
		TEST_METHOD(InvalidGetFunctionArguments)
		{
	
		}
		TEST_METHOD(InvalidSetFunctionArguments)
		{
			
		}
		TEST_METHOD(SetAndGetFunctionWorkingCorrectly)
		{
			OneDMatrix* Matrix = CreateOneDMatrix(3);
			set_ijOneDMatrix(Matrix, 1, 1, "Hello");
			Assert::AreEqual<std::string>(get_ijOneDMatrix(Matrix, 1, 1), "Hello");
			deleteOneDMatrix(Matrix);
		}
	};
}