def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    cur = 1
    for i in range(n):
        if a[i] >= cur:
            cur += 1
    print(cur)

if __name__ == "__main__":
    main()
