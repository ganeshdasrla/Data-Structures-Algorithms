def nthRowOfPascalTriangle(n):
    # code here
    MOD = 1e9+7
    ans = [1]*n
    for i in range(1, n):
        for j in range(i-1, 0, -1):
            ans[j] = int((ans[j] + ans[j-1])%MOD)
            
    return ans

# Example usage:
n = int(input())
print(nthRowOfPascalTriangle(n))