#include <cstdlib>
struct Matrix;
int n = 4; // matrix size
int main() {
	for (int a = 1 - n; a < 4; ++a) {
		for (int x = 0; x < n + 4; ++x) {

		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int matrixSize;
	int **matrix;



	matrixSize = 2;
	matrix = new int*[matrixSize]; // ��������

	for (int i = 0; i < matrixSize; i++)
	{
		matrix[i] = new int[matrixSize];
	}

	for (int i = 0; i < matrixSize; i++)
		delete matrix[i]; // ��������
	delete[]matrix;



	int *A, n, m;
	// n - ����� �����, m - ����� ��������
	A = (int *)calloc(n*m, sizeof(int));

	A = (int *)malloc(n*m * sizeof(int));

	A = new int(n*m);



	