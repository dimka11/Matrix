#pragma warning( disable : 4290 )  
#include <stdexcept>
#include "TwoDArray.h"
#include <string>
using namespace std;
struct TwoDMatrix
{
	string **body;
	size_t size;
};
TwoDMatrix* CreateTwoDMatrix(size_t s) throw(std::invalid_argument, std::bad_alloc)
{
	if (0 == s)
	{
		throw std::invalid_argument("Invalid Matrix size argument");
	}
	TwoDMatrix *res = new TwoDMatrix();
	try
	{
		res->body = new string*[s];
		size_t i = 0;
		try
		{
			for (i = 0; i < s; ++i)
			{
				res->body[i] = new string[s];
			}
			res->size = s;
			return res;
		}
		catch (std::bad_alloc const&ex)
		{
			for (size_t j = 0; j < i; ++j)
			{
				delete[] res->body[j];
				delete[] res->body;
				throw ex;
			}
		}
	}
	catch (std::bad_alloc const&ex)
	{
		delete res;
		throw ex;
	}
}
void deleteTwoDMatrix(void *Matrix) throw()
{
	TwoDMatrix *_M = static_cast<TwoDMatrix*>(Matrix);
	for (size_t i = 0; i < _M->size; i++)
	{
		delete[] _M->body[i];
	}
	delete[] _M->body;
	delete Matrix;
}
void set_ijTwoDMatrix(void *Matrix, size_t i, size_t j, string value) throw(std::invalid_argument)
{
	TwoDMatrix *_M = static_cast<TwoDMatrix*>(Matrix);
	if (i > _M->size || j > _M->size)
	{
		throw std::invalid_argument("i or j are greather than matrix size");
	}
	_M->body[i][j] = value;
}
string get_ijTwoDMatrix(void *Matrix, size_t i, size_t j) throw(std::invalid_argument)
{
	TwoDMatrix *_M = static_cast<TwoDMatrix*>(Matrix);
	if (i > _M->size || j > _M->size)
	{
		throw std::invalid_argument("i or j are greather than matrix size");
	}
	return _M->body[i][j];
}
size_t sizeTwoDMatrix(void *Matrix) throw()
{
	TwoDMatrix *_Matrix = static_cast<TwoDMatrix*>(Matrix);
	return _Matrix->size;
}