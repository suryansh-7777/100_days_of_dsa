#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Node;

void merge(Node* arr, int* res, int l, int m, int r) {
    int n = r - l + 1;
    Node* temp = (Node*)malloc(sizeof(Node) * n);

    int i = l, j = m + 1, k = 0;
    int rightCount = 0;

    while (i <= m && j <= r) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            res[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= m) {
        res[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int t = 0; t < n; t++) {
        arr[l + t] = temp[t];
    }

    free(temp);
}

void mergeSort(Node* arr, int* res, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    mergeSort(arr, res, l, m);
    mergeSort(arr, res, m + 1, r);
    merge(arr, res, l, m, r);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    Node* arr = (Node*)malloc(sizeof(Node) * numsSize);
    int* res = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, res, 0, numsSize - 1);

    free(arr);
    return res;
}
