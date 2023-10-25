def dfs(graph, v, visited):
    visited[v] = True
    print(v, end = ' ')

    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

graph = [[], [2, 3, 7], [1, 4, 7], [1, 5, 6], [2], [3, 6], [3, 5], [1, 2]]

visited = [False] * 8

dfs(graph, 1, visited)
