def solve(n):
    MOD = 10**9 + 7
    dice_vals = [1, 2, 3, 4, 5, 6]
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        for j in dice_vals:
            if i-j>=0:
                dp[i]+=dp[i-j]
                dp[i]%=MOD
    return dp[n]%MOD

if __name__ == '__main__':
    n = int(input())
    print(solve(n))
