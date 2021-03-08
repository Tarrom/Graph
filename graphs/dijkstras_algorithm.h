//
// Created by Jon on 3/7/2021.
//

#ifndef GRAPHS_DIJKSTRAS_ALGORITHM_H
#define GRAPHS_DIJKSTRAS_ALGORITHM_H
#define V 9
bool array_bool_test(bool visited[]){
    for (int i=0;i<V;++i){
        if (visited[i]==false){
            return false;
        }
    }
    return true;
}
int smallest_dist(int dist[], bool visited[]){
    int smallest_value=INT16_MAX;
    int smallest;
    for (int i=0;i<V;++i){
        if (!visited[i]&& dist[i]<smallest_value) {
            smallest = i;
            smallest_value = dist[i];
        }
    }
    return smallest;
}
int * dijkstras_algo(int graph[V][V], int source) {
    static int dist[V];
    bool visited[V];
    for (int i = 0; i < V; ++i) {
        if (i == source) {
            dist[i] = 0;
            visited[i] = false;
        } else {
            dist[i] = INT16_MAX;
            visited[i] = false;
        }
    }
    bool check_visit = array_bool_test(visited);
    int new_node;
    while (!check_visit) {
        new_node = smallest_dist(dist, visited);
        visited[new_node] = true;
        for (int i = 0; i < V; ++i) {
            if (!visited[i] && graph[new_node][i] != 0 && (dist[new_node] + graph[new_node][i]) < dist[i]) {
                dist[i] = (dist[new_node] + graph[new_node][i]);
            }
        }
        check_visit = array_bool_test(visited);

    }
    return dist;
}
#endif //GRAPHS_DIJKSTRAS_ALGORITHM_H
