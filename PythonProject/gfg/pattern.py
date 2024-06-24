def pattern(N):
    # code here
    ans = []
    num = N
    isDecreasing = True
    
    while True:
        if num > 0 and isDecreasing:
            ans.append(num)
            num = num - 5
        else:
            isDecreasing = False
            if num > N:
                break
            ans.append(num)
            num = num + 5
            
    return ans

n = 16
result = pattern(16)
print(result)