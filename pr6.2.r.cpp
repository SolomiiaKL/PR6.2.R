#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

// Рекурсивна функція формування масиву
void Create(int* a, const int size, const int Low, const int High, int i)
{
	if (i < size)
	{
		a[i] = Low + rand() % (High - Low + 1);
		Create(a, size, Low, High, i + 1);
	}
}

// Рекурсивна функція виведення масиву
void Print(const int* a, const int size, int i)
{
	if (i < size)
	{
		cout << setw(4) << a[i];
		Print(a, size, i + 1);
	}
	else
		cout << endl;
}

// Рекурсивна функція обчислення суми елементів з непарними індексами
int SumOddIndices(const int* a, const int size, int i)
{
	if (i >= size)
		return 0;
	return a[i] + SumOddIndices(a, size, i + 2);
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;       
	int a[n];
	int Low = -10;          
	int High = 10;          

	Create(a, n, Low, High, 0);
	cout << "Started massiv:\n";
	Print(a, n, 0);

	int totalSum = SumOddIndices(a, n, 1);
	cout << "Sum of elements with odd indices = " << totalSum << endl;

	return 0;
}