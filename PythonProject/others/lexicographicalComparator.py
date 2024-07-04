def lexicographical_sort(numbers):
    sorted_numbers = sorted(numbers, key=lambda x: str(x))
    return sorted_numbers

numbers = [1, 2, 10, 20, 3, 30]
sorted_numbers = lexicographical_sort(numbers)
print("Lexicographically sorted numbers:", sorted_numbers)