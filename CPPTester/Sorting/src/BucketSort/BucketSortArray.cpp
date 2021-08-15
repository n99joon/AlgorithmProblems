#include <stdio.h>
 
void merge(float arr[], float temp[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
 
    while (i <= m && j <= r) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
 
    while (i <= m)
        temp[k++] = arr[i++];
 
    for (i = l; i < k; i++)
        arr[i] = temp[i];
}
 
void mergeSort(float arr[], float temp[], int l, int r)
{
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, temp, l, m);
        mergeSort(arr, temp, m + 1, r);
        merge(arr, temp, l, m, r);
    }
}
 
// Function to sort arr[] of size n using k buckets
void bucketSort(float arr[], int n, int k)
{
    // 1) Create (k+1) size empty array for index counting and n size empty array
    int* counts = new int[k + 1];
    float* temp = new float[n];
    int i;
 
    for (i = 0; i <= k; i++)
        counts[i] = 0;
 
    // 2) Count elements each bucket and copy all elements to the temp array
    for (i = 0; i < n; i++) {
        counts[(int)(k * arr[i])]++;
        temp[i] = arr[i];
    }
 
    // 3) Set the end index of buckets (accumulate sum) in the array
    for (i = 1; i <= k; i++)
        counts[i] += counts[i - 1];
 
    // 4) Put elements of the temp array into the different buckets
    for (i = 0; i < n; i++)
        arr[--counts[(int)(k * temp[i])]] = temp[i];
 
    // 5) Sort individual buckets
    for (i = 0; i < k; i++) {
        if (counts[i] < counts[i + 1]) {
            mergeSort(arr, temp, counts[i], counts[i + 1] - 1);
        }
    }
}
 
/* Driver program to test above funtion */
int main()
{
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n, 10); // bucket size can be adjustable to make the best performance 
 
    printf("Sorted array is \n");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
 
    return 0;
}


//https://greatzzo.tistory.com/17 [What a Great World!!]