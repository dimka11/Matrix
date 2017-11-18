#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Matrix/OneDArray.h"

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
			TwoDMatrix *m = createTwoDMatrix(3);
			deleteOneDMatrix(m);
		}
		
		TEST_METHOD(InvalidSize1D)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(InvalidSize2D)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(SetGet1D)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(SetGet2D)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(InvalidCoord1D)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(InvalidCoord2D)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(AreEqual)
		{
			// TODO: Your test code here
		}
	};
}