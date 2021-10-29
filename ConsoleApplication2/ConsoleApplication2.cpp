// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void initializeArray(int* arr, int LEN)
{

    for (int i = 0; i < LEN; ++i)
    {
        * (arr + i) = int(pow(i, 2) + 1);
        if ((i + 1) % 2 == 0) *(arr + i) *= -1;
    }

}


void printArray1D(int* arr, int LEN)
{
    for (int i = 0; i < LEN; ++i)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}


int** makeArray2D(int* arr, int N, int M, int LEN)
{
    int temp;
    for (int i = 0; i < LEN - 1; i++)
    {
        for (int j = i + 1; j < LEN; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int** arr2D = new int* [N]; // выделяем память под выходной массив
    for (int i = 0; i < N; ++i) // и еще под каждый ряд массива в отдельности
    {
        *(arr2D + i) = new int[M];
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            *(*(arr2D + i) + j) = *(arr + i * M + j);
        }
    }
    return arr2D;
}

void printArray2D(int** arr2D, int N, int M)
{
    for (int i = 0; i < N; ++i)
    {
        cout << endl;
        for (int j = 0; j < M; ++j)
        {
            cout << setw(5) << *(*(arr2D + i) + j);
        }
    }
}

void freeArray1D(int* arr)
{
    delete[] arr;
}

void freeArray2D(int** arr2D, int N)
{
    for (int i = 0; i < N; i++)
    {
        delete[] arr2D[i];
    }
    delete[] arr2D;
}

/*void func()
{
    int length = 18;
    int* arr = new int[length];
    int temp;

    for (int i = 0; i < length; i++)
    {
        arr[i] = pow(i, 2) + 1;
        if ((i + 1) % 2 == 0) arr[i] *= -1;
        cout << arr[i] << " ";
    }

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        cout << setw(5) << arr[i];
        if ((i + 1) % 2 == 0) cout << endl;
    }
    }
    */

int main()
{
    const int LEN = 18; // задаем все параметры
    const int N = 9;
    const int M = 2;
    int* arr = new int[LEN]; // выделяем память под входной массив
    initializeArray(arr, LEN); // инициализируем массив (по варианту)
    printArray1D(arr, LEN); // выводим на консоль массив
    // конвертируем 1-мерный массив в 2-мерный (по варианту)
    int** arr2D = makeArray2D(arr, N, M, LEN);
    printArray2D(arr2D, N, M); // выводим на консоль 2-мерный массив-результат
    freeArray1D(arr); // освобождаем память 1-мерного массива
    freeArray2D(arr2D, N); // освобождаем память 2-мерного массива
    return 0;
}
