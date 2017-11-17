#include <iostream>
struct Matrix {
	double **body;
	size_t size;
	Matrix *res;
};

int myf()
{
	Matrix *res = new Matrix();
	int s;
	try {
		res->body = new double*[s];
		int i = 0;
		int j = 0;
		try {
			for (i = 0; i < s; ++i) {
				res->body[i] = new double*[s];
			}
			res->size = 0;
			return s;
		}
		catch (std::bad_alloc const& ex) {
			for (j = 0; j < i; ++j) {
				delete[] res->body[j];
			}
			delete[] res->body;
			throw ex;
		}
	}
	catch (std::bad_alloc const& ex) {
		delete res;
		throw ex;
	}
}