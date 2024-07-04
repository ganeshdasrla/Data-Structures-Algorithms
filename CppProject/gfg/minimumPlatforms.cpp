#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int ls = m - l + 1;
    int rs = r - m;

    int L[ls], R[rs];

    for (int i = 0; i < ls; i++)
    {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < rs; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < ls && j < rs)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < ls)
    {
        arr[k++] = L[i++];
    }
    while (j < rs)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Function to find the minimum number of platforms required at the
// railway station such that no train waits.
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    mergeSort(arr, 0, n - 1);
    mergeSort(dep, 0, n - 1);

    int i = 0, j = 0;
    int needed_platforms = 0;
    int max_platforms = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            needed_platforms++;
            i++;
            if (needed_platforms > max_platforms)
            {
                max_platforms = needed_platforms;
            }
        }
        else
        {
            needed_platforms--;
            j++;
        }
    }
    return max_platforms;
}

// Function definitions (merge, mergeSort, findPlatform) go here...

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    int platforms = findPlatform(arr, dep, n);
    cout << "Minimum number of platforms required: " << platforms << endl;

    return 0;
}
