//https://leetcode.com/problems/rotting-oranges/

/* You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1. */

class Solution {
    func orangesRotting(_ grid: [[Int]]) -> Int {
        
        let rows = grid.count
        let cols = grid[0].count
        
        guard rows != 0, cols != 0 else { return -1 }
        
        var fresh = 0
        var rottings = [(Int, Int)]()
        
        for row in 0..<rows {
            for col in 0..<cols {

            	// looking for fresh oranges
                if grid[row][col] == 1 {
                    fresh += 1
                }
                
                // looking for rotten oranges
                if grid[row][col] == 2 {
                    rottings.append((row, col))
                }
            }
        }
        
        guard fresh != 0 else { return 0 }
        
        var minutes = 0
        var newGrid = grid
        
        while rottings.count != 0, fresh != 0 {
            let count = rottings.count
            
            minutes += 1
            
            for index in 0..<count {
                let (row, col) = rottings.removeFirst()
                
                // up
                if row - 1 >= 0, newGrid[row - 1][col] == 1 {
                    rottings.append((row - 1, col))
                    newGrid[row-1][col] = 2
                    fresh -= 1
                }
                
                // down
                if row + 1 < rows, newGrid[row + 1][col] == 1 {
                    rottings.append((row + 1, col))
                    newGrid[row + 1][col] = 2
                    fresh -= 1
                }
                
                // left
                if col - 1 >= 0, newGrid[row][col - 1] == 1 {
                    rottings.append((row, col - 1))
                    newGrid[row][col - 1] = 2
                    fresh -= 1
                }
                
                // right
                if col + 1 < cols, newGrid[row][col + 1] == 1 {
                    rottings.append((row, col + 1))
                    newGrid[row][col + 1] = 2
                    fresh -= 1
                }
            }
        }
        
        return fresh == 0 ? minutes : -1
    }
}