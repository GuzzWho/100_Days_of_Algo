def solve(coins,sum):
    inf = 10**9
    dp = [inf] * (sum + 1)
    dp[0] = 0
    for i in range(1, sum + 1):
        for j in coins:
            if i-j>=0:
                dp[i] = min(dp[i - j] + 1, dp[i])
    return dp[sum] if dp[sum] != inf else -1
    

if __name__ == '__main__':
    n, sum = map(int, input().split())
    coins = list(map(int, input().split()))
    print(solve(coins,sum))