def merge_and_count(arr, l, m, r):
    size_A = m - l + 1
    size_B = r - m
    
    A = arr[l:l + size_A]
    B = arr[m + 1:m + 1 + size_B]
    
    i = 0
    j = 0
    k = l
    inversions = 0
    
    while i < size_A and j < size_B:
        if A[i] <= B[j]:
            arr[k] = A[i]
            i += 1
        else:
            arr[k] = B[j]
            inversions += size_A - i
            j += 1
        k += 1
    
    while i < size_A:
        arr[k] = A[i]
        i += 1
        k += 1
    
    while j < size_B:
        arr[k] = B[j]
        j += 1
        k += 1
    
    return inversions

def merge_sort_and_count(arr, l, r):
    if l >= r:
        return 0
    
    m = (l + r) // 2
    inversion_count = 0
    
    inversion_count += merge_sort_and_count(arr, l, m)
    inversion_count += merge_sort_and_count(arr, m + 1, r)
    inversion_count += merge_and_count(arr, l, m, r)
    
    return inversion_count

def inversion_count(arr):
    n = len(arr)
    return merge_sort_and_count(arr, 0, n - 1)

arr = [1, 20, 6, 4, 5]
print("Number of inversions are", inversion_count(arr))