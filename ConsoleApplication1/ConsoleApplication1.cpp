// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void processArr(int numbers[], const int size)
{
    int j = 1;
    int k = 1;
    int count = 0;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {

        if ((i+1) % 2 == 0 )
        {
            numbers[i] = static_cast<int>(pow(2, j));
            j++;
        }

        else
        {
            numbers[i] = static_cast<int>(pow(3, k));
            k++;
        }

        if (numbers[i] > 9 && numbers[i] < 100)
        {
            arr[count] = numbers[i];
            count++;
        }

        //cout << numbers[i] << " ";
        printf("%d", numbers[i]);
        printf("%s", " ");
    } 
    printf("%s", "\n");
    
    for (int j = 0; j < count; j++) printf("%d %s", arr[j], " ");       //cout << arr[j] << " ";
    
    printf("%s", "\n");
    printf("%d", count);

    delete[] arr;
}
int main()
{
    const int size = 16;
    int numbers[size];
    int count = 0;



    processArr(numbers, size);
    return 0;
}

