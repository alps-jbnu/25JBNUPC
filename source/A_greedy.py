import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    cnt = 0
    ans = 0
    
    for i in range(1, n + 1):
        input_value = int(data[i])
        
        if input_value == 0:
            cnt += 1
        else:
            ans += max(min((cnt * (cnt + 1)) // 2, 5 * cnt - 10), 3 * cnt) + 3
            cnt = 0
            
    if cnt:
        ans += max(min((cnt * (cnt + 1)) // 2, 5 * cnt - 10), 3 * cnt)
    
    print(ans)

if __name__ == "__main__":
    main()

