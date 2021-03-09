# Graph
Graph Algorithms
This repository will contain my implementation of graph algorithms.

So far, I have Dijkstra's algorithm.  Here is a short explanation of my implementation.

Our purpose is to find the minimum distance to each node from a designated source node.  We are given a graph and a source node.  The graph is implemented using an adjacency list and any unconnected nodes have a 0 for it's entry to the graph.

Given a graph and source node:
First a distance array is initialized representing the distance from the source node of each node in the graph.  The array is initialized as 0 for the source node and infinity for all other nodes.

For each node:
Pick the node q of minimum distance in the distance array that has not been picked yet.

For each node p that has not been picked yet, and that is connected to the node that was just picked, check:
if dist p>dist q+graph(p,q) then update dist p=dist q+graph(p,q)

I also initialize another boolean array that stores if each node has been picked.  This lets us know which nodes we can update the distance of and lets us know when the algorithm is done.

Because we pick each node, and then check every node attached to that node, this algorithm is O(V^2)
