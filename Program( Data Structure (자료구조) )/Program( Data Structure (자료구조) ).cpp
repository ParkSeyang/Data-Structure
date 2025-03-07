#include <iostream>

using namespace std;

#define SIZE 10
template<typename T>
class AdjacencyMatrix
{
private:
	int size;
	T vertex[SIZE];
	int matrix[SIZE][SIZE];

	// 정점의 개수
	// 정점의 집합
	//	인접 행렬
public:
	AdjacencyMatrix()
	{
		size = 0;

		for (int i = 0; i< SIZE; i++)
		{
			vertex[i] = NULL;

			for (int j = 0; j< SIZE; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	void push(T data)
	{
		int index = matrix[i][j];
		if (size >= SIZE)
		{
			cout << "AdjacencyMatrix is Over flow" << endl;
		}
		else
		{
			vertex[size++] = data;
		}

	}
	void edge(int i, int j)
	{
		if (size <=0)
		{
			cout << "AdjacencyMatrix is empty" << endl;
		}
		else if (i>=size || j >= size)
		{
			cout << "Index Out of Range" << endl;
		}
		else
		{
			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
	}
	void show()
	{
		
		for (int i = 0; i < SIZE; i++)
		{
			if ()
			{

			}
			else if ()
			{

			}
			else
			{

			}
			for (int j = 0; j < SIZE; j++)
			{
				if (matrix[i][j]  || matrix[j][i])
				{
					cout << " " << vertex[i] << endl;
				}
			}
			

			


		}
	}

};

int main()
{
	AdjacencyMatrix<int> adjacencyMatrix;

	return 0;
}