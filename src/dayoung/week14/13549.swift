/*BFS와 배열을 사용. 다른 사람들의 코드를 찾아보니 dequeue를 사용한 코드들이 많이 보였다.
 한번도 사용해 본 적 없으므로 다음에 dequeue를 사용해 볼 것.*/
 
import Foundation

let nk = readLine()!.split(separator: " ").map { Int(String($0))! }

var values = [Int](repeating: 100000, count: 100001)
values[nk[0]] = 0
var visit = [Bool](repeating: false, count: 100001)
var queue = [nk[0]]

while !queue.isEmpty {
    let cur = queue.removeFirst()

    guard cur != nk[1] else {
        print(values[nk[1]]); break
    }
    
    if cur * 2 <= 100000, !visit[cur*2] {
        queue.insert(cur*2, at: 0)
        values[cur*2] = values[cur]
        visit[cur*2] = true
    }
    if cur+1 <= 100000, !visit[cur+1] {
        queue.append(cur+1)
        values[cur+1] = values[cur]+1
        visit[cur+1] = true
    }
    if cur-1 >= 0, !visit[cur-1] {
        queue.append(cur-1)
        values[cur-1] = values[cur]+1
        visit[cur-1] = true
    }
}
