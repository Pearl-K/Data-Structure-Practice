#include <stdio.h>

// Min Heap을 Max Heap으로 (배열로 나타내기)

// 스왑 함수
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 비교하면서 Max Heap 조건에 맞게
void arrange_MaxHeap(int arr[], int i, int N)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < N && arr[l] > arr[i])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        arrange_MaxHeap(arr, largest, N);
    }
}

// Max Heap으로 만들기
void convertMaxHeap(int arr[], int N)
{
    // Log N 의 시간복잡도
    for (int i = (N - 2) / 2; i >= 0; --i)
        arrange_MaxHeap(arr, i, N);
}

// 배열 프린트하는 함수
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

int main()
{
    // 주어진 Min Heap
    int arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
    int N = sizeof(arr) / sizeof(arr[0]); //배열의 크기 저장

    printf("Min Heap array : ");
    printArray(arr, N); // 기존 Min Heap 배열 프린트

    // Max Heap 만들기
    convertMaxHeap(arr, N);

    printf("\nMax Heap array : ");
    printArray(arr, N); // 만든 Max Heap 배열 프린트

    return 0;
}