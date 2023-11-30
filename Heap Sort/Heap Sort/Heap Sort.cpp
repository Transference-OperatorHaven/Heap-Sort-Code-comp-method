// Heap Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

using namespace std;

void PrintArray(int array[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << array[i] << " ";
    cout << "\n";
}

void Heapification(int array[], int N, int i)
{
    int largest = i;
    int iLeft = 2 * i + 1;
    int iRight = 2 * i + 2;


    //iLeft is bigger than largest
    if (iLeft < N && array[iLeft] > array[largest])
    {
        largest = iLeft;
    }

    //iRight is bigger than largest
    if (iRight < N && array[iRight] > array[largest])
    {
        largest = iRight;
    }

    //largest isn't root
    if (largest != i) {

        swap(array[i], array[largest]);
        Heapification(array, N, largest);


    }
}

void heapSort(int array[], int N)
{
    //build heap
    for (int i = N / 2 - 1; i >= 0; i--)
        Heapification(array, N, i);
    //extract an element from heap 1b1
    for (int i = N - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        PrintArray(array, N);
        Heapification(array, i, 0);
    }
}


// Driver program
int main()
{
    int array[] = { 10, 15, 12, 12, 25, 16, 20, 14 ,28, 17 };
    int N = sizeof(array) / sizeof(array[0]);
    for (int i = N / 2 - 1; i >= 0; i--) {
        Heapification(array, N, i);
    }

    cout << "\n\nAfter heapifying array is \n";
    PrintArray(array, N);
    cout << "\n\n";

    heapSort(array, N);

    cout << "\n\nSorted array is \n";
    PrintArray(array, N);
    cout << "\n\n";
    return 0;
}

