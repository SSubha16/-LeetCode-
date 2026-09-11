from collections import deque
from typing import List


class Solution:

  def containsCycle(self, grid: List[List[str]]) -> bool:
    m, n = len(grid), len(grid[0])
    visited = [[False] * n for _ in range(m)]

    for r in range(m):
      for c in range(n):
        if visited[r][c]:
          continue

        # Start a BFS traversal for an unvisited component
        char = grid[r][c]
        visited[r][c] = True
        # Queue stores: (current_row, current_col, parent_row, parent_col)
        queue = deque([(r, c, -1, -1)])

        while queue:
          curr_r, curr_c, parent_r, parent_c = queue.popleft()

          for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = curr_r + dr, curr_c + dc

            # Check bounds and matching character
            if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == char:
              # Ignore the cell we just came from
              if nr == parent_r and nc == parent_c:
                continue

              # If already visited in the same traversal, a cycle exists
              if visited[nr][nc]:
                return True

              visited[nr][nc] = True
              queue.append((nr, nc, curr_r, curr_c))

    return False