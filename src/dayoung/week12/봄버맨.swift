//
//  main.swift
//  12주차
//
//  Created by 장다영 on 2021/05/23.
//

import Foundation

let inputValues = readLine()!.split(separator: " ")
let row = Int(inputValues[0])!
let col = Int(inputValues[1])!
let sec = Int(inputValues[2])!
let dy: [Int] = [1, -1, 0, 0]
let dx: [Int] = [0, 0, 1, -1]
var matrix: [[Character]] = Array(repeating: Array(repeating: "0", count: col), count: row)
var time: [[Int]] = Array(repeating: Array(repeating: 0, count: col), count: row)
var arr: [Character] = []

func InstallBomb(T: Int) {
    for i in 0...(row-1) {
        for j in 0...(col-1) {
            if matrix[i][j] == "O" {continue}
            matrix[i][j] = "O"
            time[i][j] = T + 3
        }
    }
}

func explode(T: Int) {
    for i in 0...(row-1) {
        for j in 0...(col-1) {
            if time[i][j] == T {
                for k in 0..<4 {
                    var nx: Int = i + dx[k]
                    var ny: Int = j + dy[k]
                    if (nx<0)||(ny<0)||(nx>=row)||(ny>=col) {continue}
                    if matrix[nx][ny] == "." {continue}
                    matrix[nx][ny] = "."
                }
                matrix[i][j] = "."
                time[i][j] = 0;
            }
        }
    }
}

func Print() {
    for i in 0...(row-1) {
        print("\(matrix[i])\n")
    }
}

for i in 0...(row-1) {
    arr = Array(readLine()!)
    matrix[i] = arr
}

for i in 0...(row-1) {
    for j in 0...(col-1) {
        if matrix[i][j] == "O" {time[i][j] = 3}
    }
}

var cnt: Int = 2
while(1 != 0) {
    if cnt == sec+1 {break}
    if cnt%2 == 0 {InstallBomb(T: cnt)}
    else {explode(T: cnt)}
    cnt += 1
}

Print()
