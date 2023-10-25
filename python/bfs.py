from collections import deque

def bfs(graph, start, visited):
    queue = deque([start])

    visited[start] = True

    while queue:
        v = queue.popleft()
        print(v, end = ' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

graph = [[], [2, 3, 7], [1, 4, 7], [1, 5, 6], [2], [3, 6], [3, 5], [1, 2]]
visited = [False] * 8
bfs(graph, 1, visited)
