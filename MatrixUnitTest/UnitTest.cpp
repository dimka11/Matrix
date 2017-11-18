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
			OneDMatrix *m = createOneDMatrix(5);
			 deleteOneDMatrix(m);
		}
		TEST_METHOD(TwoDMatrixCreatedAndDeleted)
		{
			TwoDMatrix *m = CreateTwoDMatrix(3);
			 deleteTwoDMatrix(m);
		}
		
		TEST_METHOD(InvalidSizeTwoDMatrix)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(InvalidSizeTwoDMatrix)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(SetGetOneDMatrix)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(SetGetTwoDMatrix)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(InvalidCoordOneDMatrix)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(InvalidCoordTwoDMatrix)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(AreEqual)
		{
			// TODO: Your test code here
		}
	};
}