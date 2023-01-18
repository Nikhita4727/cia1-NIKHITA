# cia1-NIKHITA



All the 3 algorithms i.e prim's,kruskals and dijkstras fails for the given problem.But in some cases dijkstras algorithm may be an exceptional case.Since the given problem is a directed graph with a negative edge in the graph

 *prims algorithm: fails because in general prims algorithm assumes that all vertices are connected but in a directed graph every node is not reachable from every other node.So prims algorithm fails.

*kruskals algorithm:fails because in general Kruskal’s algorithm in each step we check whether the edges form a cycle with the spanning-tree formed or not but in case of directed graph this algorithm fails to detect the cycles in a directed graph as there are cases when there is no cycle between the vertices but Kruskal’s Algorithm assumes it to cycle and don’t take consider some edges due to which Kruskal’s Algorithm fails for directed graph.

*dijkstras algorithm: this algorithm looks only through immediate neighbours of vertrex.when we apply dijkstras for a directed graph with a negative edge then we will not get the shortest path.But if the cycle is taken correctly it may be an exception case.
