#include <bits/stdc++.h>
using namespace std;

void bubble(int a[], int n)
{
    for (int j = 0; j < n - 1; ++j)
        for (int i = 0; i < n - 1 - j; ++i)
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
}

void cockTail(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        for (int i = left; i < right; ++i)
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        --right;
        for (int i = right; i > left; --i)
            if (a[i - 1] > a[i])
                swap(a[i - 1], a[i]);
        ++left;
    }
}

void select(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[min])
                swap(a[j], a[min]);
        if (min != i)
            swap(a[i], a[min]);
    }
}

void insert(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int get = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > get)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = get;
    }
}

void insertDichotomy(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int get = a[i];
        int left = 0;
        int right = i - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (a[mid] > get)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; --j)
            a[j + 1] = a[j];
        a[left] = get;
    }
}

void shell(int a[], int n)
{
    int h = 0;
    while (h <= n)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < n; ++i)
        {
            int j = i - h;
            int get = a[i];
            while (j >= 0 && a[j] > get)
            {
                a[j + h] = a[j];
                j -= h;
            }
            a[j + h] = get;
        }
        h = (h - 1) / 3;
    }
}

void merge(int a[], int left, int mid, int right)
{
    int len = right - left + 1;
    int *tmp = new int[len];
    int index = 0;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        tmp[index++] = a[i] <= a[j] ? a[i++] : a[j++];
    }
    while (i <= mid)
    {
        tmp[index++] = a[i++];
    }
    while (j <= right)
    {
        tmp[index++] = a[j++];
    }
    for (int k = 0; k < len; ++k)
        a[left++] = tmp[k];
}

void mergeSortRecursion(int a[], int left, int right)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;
    mergeSortRecursion(a, left, mid);
    mergeSortRecursion(a, mid + 1, right);
    merge(a, left, mid, right);
}

void mergeSortIteration(int a[], int len)
{
    int left, mid, right;
    for (int i = 1; i < len; i *= 2)
    {
        left = 0;
        while (left + i < len)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;
            merge(a, left, mid, right);
            left = right + 1;
        }
    }
}

void heapify(int a[], int i, int size) //从a[i]向下进行堆调整
{
    int left_child = 2 * i + 1;  //左孩子索引
    int right_child = 2 * i + 2; //右孩子索引
    int max = i;                 //选出i和左孩子和右孩子中最大值
    if (left_child < size && a[left_child] > a[max])
        max = left_child;
    if (right_child < size && a[right_child] > a[max])
        max = right_child;
    if (max != i)
    {
        swap(a[i], a[max]);
        heapify(a, max, size); //继续向下调整
    }
}

int buildHeap(int a[], int n) //建堆,时间复杂度O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; --i) //对每一个非叶结点开始向下进行堆调整
        heapify(a, i, heap_size);
    return heap_size;
}

void heapSort(int a[], int n)
{
    int heap_size = buildHeap(a, n);
    while (heap_size > 1)
    {
        swap(a[0], a[--heap_size]);
        heapify(a, 0, heap_size);
    }
}

int partition(int a[], int left, int right)
{
    int pivot = a[right];
    int tail = left - 1; //小于基准的子数组的最后一个元素的索引
    for (int i = left; i < right; ++i)
        if (a[i] <= pivot)
            swap(a[++tail], i);
    swap(a[tail + 1], a[right]);
    return tail + 1;
}

void quick(int a[], int left, int right)
{
    if (left >= right)
        return;
    int pivot = partition(a, left, right);
    quick(a, left, pivot - 1);
    quick(a, pivot + 1, right);
}

int main()
{
    int a[] = {6, 5, 3, 1, 8, 2, 7, 4, 9};
    // bubble(a, 9);

    for (int i = 0; i < 9; ++i)
        cout << a[i];
    return 0;
}