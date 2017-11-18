#include "OneDArray.h"

struct OneDMatrix
{
	double* body; // тело
	size_t size; // размер
};

OneDMatrix* createOneDMatrix(size_t size) throw(std::bad_alloc, std::invalid_argument)
{
	if (0 == size) // check size
	{
		throw std::invalid_argument("Argument size should be great than 0.");
	}
	OneDMatrix *res = new OneDMatrix; // выделение памяти под матрицу
	try
	{
		res->body = new double[size]; //todo replace double to string
		res->size = size;
	}
	catch(std::bad_alloc const& ex) // не хватило памяти ((
	{
		delete res;
		throw ex; // проброс исключения
	}
}


/// <summary>
/// Gets the ij one d matrix.
/// </summary>
/// <param name="Matrix">The matrix.</param>
/// <param name="i">The i.</param>
/// <param name="j">The j.</param>
/// <returns> Значение ячейки матрицы</returns>
double get_ijOneDMatrix(void* Matrix, size_t i, size_t j)
{
	OneDMatrix *_Matrix = static_cast<OneDMatrix*>(Matrix);
	return _Matrix->body[i*_Matrix->size + 1]; // Multiply operator?
}
/// <summary>
/// Setter for One Dimension Matrix implementation.
/// </summary>
/// <param name="Matrix">Матрица</param>
/// <param name="i">The i.</param>
/// <param name="j">The j.</param>
/// <param name="value">The value.</param>
void set_ijOneDMatrix(void* Matrix, size_t i, size_t j, double value)
{
	OneDMatrix *_Matrix = static_cast<OneDMatrix*>(Matrix);
	//todo Исправить сеттер
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

