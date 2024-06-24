def is_sorted_and_rotated(arr, n):
    if n <= 1:
        return "No"  # A single element array or empty array is not considered rotated and sorted
    
    # Find the number of times the array order breaks
    count_breaks = 0
    for i in range(1, n):
        if arr[i-1] > arr[i]:
            count_breaks += 1
    
    # Also check the last element with the first element to account for rotation
    if arr[n-1] > arr[0]:
        count_breaks += 1
    
    # For an array to be sorted and rotated, there should be exactly one break
    if count_breaks == 1:
        return "Yes"
    else:
        return "No"

# Example 1
arr1 = [3, 4, 1, 2]
n1 = 4
print(is_sorted_and_rotated(arr1, n1))  # Output: Yes
