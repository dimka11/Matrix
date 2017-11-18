#include "OneDArray.h"

struct OneDMatrix
{
	double* body; // ����
	size_t size; // ������
};

OneDMatrix* createOneDMatrix(size_t size) throw(std::bad_alloc, std::invalid_argument)
{
	if (0 == size) // check size
	{
		throw std::invalid_argument("Argument size should be great than 0.");
	}
	OneDMatrix *res = new OneDMatrix; // ��������� ������ ��� �������
	try
	{
		res->body = new double[size]; //todo replace double to string
		res->size = size;
	}
	catch(std::bad_alloc const& ex) // �� ������� ������ ((
	{
		delete res;
		throw ex; // ������� ����������
	}
}


/// <summary>
/// Gets the ij one d matrix.
/// </summary>
/// <param name="Matrix">The matrix.</param>
/// <param name="i">The i.</param>
/// <param name="j">The j.</param>
/// <returns> �������� ������ �������</returns>
double get_ijOneDMatrix(void* Matrix, size_t i, size_t j)
{
	OneDMatrix *_Matrix = static_cast<OneDMatrix*>(Matrix);
	return _Matrix->body[i*_Matrix->size + 1]; // Multiply operator?
}
/// <summary>
/// Setter for One Dimension Matrix implementation.
/// </summary>
/// <param name="Matrix">�������</param>
/// <param name="i">The i.</param>
/// <param name="j">The j.</param>
/// <param name="value">The value.</param>
void set_ijOneDMatrix(void* Matrix, size_t i, size_t j, double value)
{
	OneDMatrix *_Matrix = static_cast<OneDMatrix*>(Matrix);
	//todo ��������� ������
	_Matrix->body[i*_Matrix->size + 1] = value;
}

size_t sizeOneDMatrix(void* Matrix) throw()
{
	OneDMatrix *_Matrix = static_cast<OneDMatrix*>(Matrix);
	return _Matrix->size;
}


void deleteOneDMatrix(void *Matrix) throw()
{
	OneDMatrix *_Matrix = static_cast<OneDMatrix*>(Matrix);
	delete[] _Matrix->body;
}
bool CheckThatSecondArgNotGreatherFirst(OneDMatrix &m, size_t j)
{
	return m.body[m.size + j];
}
bool CheckThatIndexIsInRange(OneDMatrix &m, size_t j)
{
}

