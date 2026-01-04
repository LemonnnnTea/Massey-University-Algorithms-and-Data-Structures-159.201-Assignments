#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;
struct edge{
    int to;
    int weight;
    edge(const int to, const int weight):to(to),weight(weight){}
};

struct compare {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
    return p1.second < p2.second;}
};
void Dijkstra(const vector<list<edge>>&, int V);

int main() {
    string input;
    int numOfNodes, numOfEdges;
    getline(cin, input);
    istringstream in(input);
    in >> numOfNodes >> numOfEdges;
    vector<list<edge>> adjacencyList(numOfNodes);
    for(int i = 0; i < numOfEdges; i++) {
        getline(cin, input);
        int from, to, weight;
        istringstream iss(input);
        iss >> from >> to >> weight;
        adjacencyList[from].emplace_back(to, weight);
    }
    Dijkstra(adjacencyList, numOfNodes);
}

void Dijkstra(const vector<list<edge>> &adjList, int V) {
    vector <int> distance(V, INT_MAX);
    priority_queue <pair<int, int>, vector<pair<int, int>>, compare> pq;
    distance[0] = 0;
    pq.emplace(0, distance[0]);
    while(!pq.empty()) {
        const int u = pq.top().first;
        const int shortest = pq.top().second;
        pq.pop();
        if(distance[u] < shortest) {
            continue;
        }
        for(const edge e : adjList[u]) {
            int to = e.to;
            if(const int weight = e.weight; shortest + weight < distance[to]) {
                distance[to] = shortest + weight;
                pq.emplace(to, distance[to]);
            }
        }
    }
    for(int i = 0; i < V; i++) {
        if(distance[i] == INT_MAX) {
            cout << "inf ";
            continue;
        }
        cout << distance[i] << " ";
    }
}
