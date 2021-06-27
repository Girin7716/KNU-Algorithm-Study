
import Foundation

let size = readLine()!.split(separator: " ").map{Int(String($0))!}
var arr = [[Character]]()

for _ in 0..<size[0] {
    arr.append(Array(readLine()!))
}
var dp: [[Int]] = .init(repeating: .init(repeating: 0, count: size[1]), count: size[0])

var maxSize = 0
for i in 1..<dp.count {
    for j in 1..<dp[i].count {
        if arr[i-1][j-1] == "0" { continue }
        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        maxSize = max(maxSize, dp[i][j])
    }
}

print(maxSize * maxSize)

