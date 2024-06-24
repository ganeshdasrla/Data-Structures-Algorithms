def subarraysWithSumK(a: [int], k: int) -> [[int]]:
    n = len(a)
    subarray = []
    start = 0
    sum = 0

    for end in range(n):
        sum += a[end]
        
        while sum > k and start <= end:
            sum -= a[start]
            start += 1
        
        if sum == k:
            currentSubarray = a[start:end+1]
            subarray.append(currentSubarray)
    
    return subarray

# Example usage:
arr = [1, 2, 3, 1, 1, 1]
k = 3
result = subarraysWithSumK(arr, k)
print("Subarrays with sum", k, "in", arr, "are:")
for subarr in result:
    print(subarr)
