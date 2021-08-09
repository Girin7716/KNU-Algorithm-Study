import Foundation

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
    
    var result = [String](repeating: "O", count: n)
    var deleted = Stack<Int>()
    var up: [Int] = []
    var down: [Int] = []
    var k = k
    
    for i in 0...n+1 {
        up[i] = i-1
        down[i] = i+1
    }
    k+=1
    
    for i in 0..<cmd.count {
        
        let cur = cmd[i].split(separator: " ")
        
        if cur[0] == "U" {
            for _ in 0..<Int(cur[1])! {
                k = up[k]
            }
        }
        
        else if cur[0] == "D" {
            for _ in 0..<Int(cur[1])! {
                k = down[k]
            }
        }
        
        else if cur[0] == "C" {
            deleted.push(element: k)
            down[up[k]] = down[k]
            up[down[k]] = up[k]
    
            if down[k] == n+1 {
    
                k = up[k]
            }
            
            else {
                k = down[k]
            }
            
        }
        
        else if cur[0] == "Z" {
            let restored = deleted.pop()!
            down[up[restored]] = restored
            up[down[restored]] = restored
        }
        
    }
    
    for _ in 0..<deleted.count {
        result[deleted.pop()!] = "X"
    }
    
    return result.joined()
    
}

public struct Stack<T> {
    private var elements = [T]()
    public init() {}
    
    public mutating func pop() -> T? {
        return self.elements.popLast()
    }
    
    public mutating func push(element: T) {
        self.elements.append(element)
    }
    
    public var count:Int {
        return self.elements.count
    }
}


