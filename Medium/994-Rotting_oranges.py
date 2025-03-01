class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        time,fresh=0,0
        rows,cols = len(grid),len(grid[0])

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    fresh += 1
                if grid[r][c] == 2:
                    q.append([r,c])

        
        while q and fresh > 0:
            length = len(q)
            for i in range(length):
                r,c = q.popleft()
                neighbours = [[r+1,c],[r-1,c],[r,c+1],[r,c-1]]
                for nr,nc in neighbours:
                    if nr >= 0 and nr < rows and nc >= 0 and nc < cols and grid[nr][nc]==1:
                        grid[nr][nc] = 2
                        q.append([nr,nc])
                        fresh -= 1
                
            time += 1
            
        return time if fresh == 0 else -1

