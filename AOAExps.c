//Exp 1: Selection Sort

#include <stdio.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    selectionSort(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nExecution time: %f seconds\n", cpu_time_used);

    return 0;
}


//Exp 2: Insertion Sort

#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13, 5, 76, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertionSort(arr, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("CPU Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}

//Exp 3: Binary Search

#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[1000], n, key, i;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();
    int result = binarySearch(arr, n, key);
    end = clock();

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU execution time: %f seconds\n", cpu_time_used);

    return 0;
}

//Exp 4: Merge Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nCPU Execution Time: %f seconds\n", time_taken);
    return 0;
}

//Exp 5: Quick Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nExecution time: %f seconds\n", cpu_time_used);

    return 0;
}

//Exp 7: Kruskal's Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX], mst[MAX];
int parent[MAX];
int n, e;

int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    parent[j] = i;
}

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int main() {
    int i, j = 0, u, v;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (i = 0; i < e; i++) {
        printf("Enter edge %d (u v w): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    clock_t start = clock();

    qsort(edges, e, sizeof(Edge), cmp);

    for (i = 0; i < e && j < n - 1; i++) {
        u = find(edges[i].u);
        v = find(edges[i].v);
        if (u != v) {
            mst[j++] = edges[i];
            union_set(u, v);
        }
    }

    clock_t end = clock();

    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < j; i++)
        printf("%d - %d : %d\n", mst[i].u, mst[i].v, mst[i].w);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds\n", time_taken);

    return 0;
}

//Input sample

Enter number of vertices and edges: 4 5
Enter edge 1 (u v w): 0 1 10
Enter edge 2 (u v w): 0 2 6
Enter edge 3 (u v w): 0 3 5
Enter edge 4 (u v w): 1 3 15
Enter edge 5 (u v w): 2 3 4
