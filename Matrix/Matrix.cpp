#pragma warning( disable : 4290 )  
#include "Matrix.h"
#include "OneDArray.h"
using namespace std;

// pointers:
struct Matrix{
	void* body;
	p_Of_get_ij _get_ij;
	p_Of_set_ij _set_ij;
	p_Of_delete _delete;
	p_Of_size _size;
};

Matrix* CreateGeneralOneDMatrix(size_t s)
{
	Matrix  *GeneralMatrix = new Matrix();
	GeneralMatrix->body = CreateOneDMatrix(s);
	GeneralMatrix->_get_ij = get_ijOneDMatrix;
	GeneralMatrix->_set_ij = set_ijOneDMatrix;
	GeneralMatrix->_delete = deleteOneDMatrix;
	GeneralMatrix->_size = sizeOneDMatrix;

	return GeneralMatrix;
}

Matrix *CreateGeneralTwoDMatrix(size_t s)
{
	Matrix *GeneralMatrix = new Matrix();
	GeneralMatrix->body = CreateGeneralTwoDMatrix(s);
	GeneralMatrix->_get_ij = get_ijTwoDMatrix;
	GeneralMatrix->_set_ij = set_ijOneDMatrix;
	GeneralMatrix->_delete = deleteOneDMatrix;
	GeneralMatrix->_size = sizeTwoDMatrix;
	return GeneralMatrix;
}
string get_ij(Matrix &M, size_t i, size_t j)
{
	return M._get_ij(M.body, i, j);
}
void  set_ij(Matrix &M, size_t i, size_t j, string value)
{
	M._set_ij(M.body, i, j, value);
}
void deleteMatrix(Matrix *M)
{
	return M->_delete(M->body);
	//return M._delete(M.body);
}
size_t size(Matrix const &M)
{
	return M._size(M.body);
}