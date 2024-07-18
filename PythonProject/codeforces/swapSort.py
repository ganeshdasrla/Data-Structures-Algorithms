def sortWithSwaps(ar, n):
    swaps = []

    for i in range(n):
        min_index = i

        for j in range(i+1, n):
            if ar[j] < ar[min_index]:
                min_index = j
            
        if i != min_index:
            ar[i], ar[min_index] = ar[min_index], ar[i]
            swaps.append((i, min_index))
                
    print(len(swaps))
    for swap in swaps:
        print(swap[0], swap[1])
    

n = int(input())
array = list(map(int, input().split()))
sortWithSwaps(array, n)     