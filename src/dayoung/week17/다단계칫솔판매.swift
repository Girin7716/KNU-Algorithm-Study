//
//  main.swift
//  week17
//
//  Created by 장다영 on 2021/07/18.
//

import Foundation

func solution(_ enroll:[String], _ referral:[String], _ seller:[String], _ amount:[Int]) -> [Int] {
    
    var net = Dictionary<String, String>()
    var profits = Dictionary<String ,Int>()
    
    profits["-"] = 0
    
    func money(_ profit: Int) -> Int {
        return Int(Double(profit) * 0.1)
    }
    
    func pass(_ name: String, earn: Int) {
        if earn == 0 {
            return
        }
        
        profits[name]! += earn
        if name != "-" {
            profits[name]! -= money(earn)
            pass(net[name]!, earn: money(earn))
        }
    }
    
    for i in 0..<enroll.count {
        net[enroll[i]] = referral[i]
        profits[enroll[i]] = 0
    }
    
    for i in 0..<seller.count {
        pass(net[seller[i]]!, earn: money(amount[i] * 100))
        profits[seller[i]]! += amount[i] * 90
    }
    
    return enroll.map{profits[$0]!}
}
