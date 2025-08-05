from collections import deque
maze = [
    ['S', '.', '.', '#', '.', '.', '.'],
    ['#', '#', '.', '#', '.', '#', '.'],
    ['.', '.', '.', '.', '.', '#', '.'],
    ['.', '#', '#', '#', '.', '#', '.'],
    ['.', '.', '.', '#', '.', '.', 'G']
]

def bfs(maze):
    rows, cols = len(maze), len(maze[0])
    for r in range(rows):
        for c in range(cols):
            if maze[r][c] == 'S':
                start = (r, c)
            if maze[r][c] == 'G':
                goal = (r, c)

    queue = deque([start])
    visited = set([start])
    parent = {}

    while queue:
        r, c = queue.popleft()
        if (r, c) == goal:
            break
        for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols:
                if maze[nr][nc] != '#' and (nr, nc) not in visited:
                    queue.append((nr, nc))
                    visited.add((nr, nc))
                    parent[(nr, nc)] = (r, c)

    return reconstruct_path(parent, start, goal)

def dfs(maze):
    rows, cols = len(maze), len(maze[0])
    for r in range(rows):
        for c in range(cols):
            if maze[r][c] == 'S':
                start = (r, c)
            if maze[r][c] == 'G':
                goal = (r, c)

    stack = [start]
    visited = set()
    parent = {}

    while stack:
        r, c = stack.pop()
        if (r, c) == goal:
            break
        if (r, c) in visited:
            continue
        visited.add((r, c))
        for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols:
                if maze[nr][nc] != '#' and (nr, nc) not in visited:
                    stack.append((nr, nc))
                    if (nr, nc) not in parent:
                        parent[(nr, nc)] = (r, c)

    return reconstruct_path(parent, start, goal)

def reconstruct_path(parent, start, goal):
    if goal not in parent:
        return None
    path = [goal]
    while path[-1] != start:
        path.append(parent[path[-1]])
    path.reverse()
    return path

print("BFS Path:")
print(bfs(maze))

print("DFS Path:")
print(dfs(maze))

