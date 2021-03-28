# 매출 하락 최소화
def solution(sales, links):
    answer = 0

    dp = [[int(1e9),int(1e9)] for _ in range(300001)]
    adj = [[]for _ in range(300001)]

    for link in links:
        a, b = link
        adj[a].append(b)

    def DFS(start):
        if len(adj[start]) == 0:
            dp[start][1] = sales[start-1]
            dp[start][0] = 0
            return
        for i in range(len(adj[start])):
            DFS(adj[start][i])

        sum = 0
        join = False
        min_join = int(1e9)
        for i in range(len(adj[start])):
            n = adj[start][i]
            sum += min(dp[n][1],dp[n][0])
            if dp[n][1] <= dp[n][0]:
                join = True
            if min_join > dp[n][1] - dp[n][0]:
                min_join = dp[n][1] - dp[n][0]

        dp[start][1] = sales[start-1]+sum
        dp[start][0] = sum + min_join
        if join:
            dp[start][0] = sum



        return

    DFS(1)
    answer = min(dp[1][1],dp[1][0])

    return answer


print(solution([14, 17, 15, 18, 19, 14, 13, 16, 28, 17],[[10, 8], [1, 9], [9, 7], [5, 4], [1, 5], [5, 10], [10, 6], [1, 3], [10, 2]]))
print(solution([5, 6, 5, 3, 4],[[2,3], [1,4], [2,5], [1,2]]))
print(solution([5, 6, 5, 1, 4],	[[2,3], [1,4], [2,5], [1,2]]))
print(solution([10, 10, 1, 1],	[[3,2], [4,3], [1,4]]))