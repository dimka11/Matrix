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
	};
	
}