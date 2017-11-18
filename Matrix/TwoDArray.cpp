
#include <stdexcept>
#include "TwoDArray.h"
struct TwoDMatrix
{
	int **body;
	size_t size;
};
TwoDMatrix* CreateTwoDMatrix(size_t s) throw(std::invalid_argument, std::bad_alloc)
{
	if (0 == s)
	{
		throw std::invalid_argument("Size Of Matrix Must Be More Then Zero");
	}
	TwoDMatrix *res = new TwoDMatrix();
	try
	{
		res->body = new int*[s];
		int i = 0;
		try
		{
			for (i = 0; i < s; ++i)
			{
				res->body[i] = new int[s];
			}
			res->size = s;
			return res;
		}
		catch (std::bad_alloc const &ex)
		{
			for (int j = 0; j < i; ++j)
			{
				delete[] res->body[j];
				delete[] res->body;
				throw ex;
			}
		}
	}
	catch (std::bad_alloc const &ex)
	{
		delete res;
		throw ex;
	}
}

void deleteTwoDMatrix(void *M) throw()
{
	TwoDMatrix *_M = static_cast<TwoDMatrix*>(M);
	for (int i = 0; i < _M->size; i++)
	{
		delete[] _M->body[i];
		delete[] _M->body;
		delete M;
	}
}
void set_ijTwoDMatrix(void *M, size_t i, size_t j, int value) throw(std::invalid_argument)
{
	TwoDMatrix *_M = static_cast<TwoDMatrix*>(M);
	_M->body[i][j] = value;
}
double get_ijTwoDMatrix(void *M, size_t i, size_t j) throw(std::invalid_argument)
{
	TwoDMatrix *_M = static_cast<TwoDMatrix*>(M);
	return _M->body[i][j];
}
size_t sizeTwoDMatrix(void *Matrix) throw()
{
	TwoDMatrix *_Matrix = static_cast<TwoDMatrix*>(Matrix);
	return _Matrix->size;
}