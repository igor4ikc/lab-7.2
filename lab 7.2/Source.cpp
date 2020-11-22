#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int IMinEven(int** a, const int rowCount, const int colNo);
int Sum(int** a, const int r, const int rowCount);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;

    int rowCount;
    int colCount;
    int r = 0;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    cout << "Original array" << endl;
    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);
   

    cout << "S = " << Sum(a, r, rowCount) <<  endl;

    system("pause");
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int IMinEven(int** a, const int rowCount, const int colNo)
{
    int min = a[0][colNo];
    int imin = 0;
    for (int r = 1; r < rowCount; r++)
    {
        if (a[r][colNo] < min)
        {
            min = a[r][colNo];
            imin = r;
        }
    }
    return imin;
}
int Sum(int** a, const int r, const int rowCount)
{
    int S = 0;
    for (int j = 0; j < rowCount; j++)
        S += a[r][j];

    return S;
}

