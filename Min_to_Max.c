#include <stdio.h>

// Min Heap�� Max Heap���� (�迭�� ��Ÿ����)

// ���� �Լ�
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ���ϸ鼭 Max Heap ���ǿ� �°�
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

// Max Heap���� �����
void convertMaxHeap(int arr[], int N)
{
    // Log N �� �ð����⵵
    for (int i = (N - 2) / 2; i >= 0; --i)
        arrange_MaxHeap(arr, i, N);
}

// �迭 ����Ʈ�ϴ� �Լ�
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

int main()
{
    // �־��� Min Heap
    int arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
    int N = sizeof(arr) / sizeof(arr[0]); //�迭�� ũ�� ����

    printf("Min Heap array : ");
    printArray(arr, N); // ���� Min Heap �迭 ����Ʈ

    // Max Heap �����
    convertMaxHeap(arr, N);

    printf("\nMax Heap array : ");
    printArray(arr, N); // ���� Max Heap �迭 ����Ʈ

    return 0;
}