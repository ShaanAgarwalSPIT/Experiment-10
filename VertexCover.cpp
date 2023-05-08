#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vertexCover(int V, vector<vector<int>>& edges) {
    vector<int> cover; 

    while (!edges.empty()) {
        sort(edges.begin(), edges.end(), [&](const vector<int>& a, const vector<int>& b) {
            return count(cover.begin(), cover.end(), a[0]) + count(cover.begin(), cover.end(), a[1]) <
                   count(cover.begin(), cover.end(), b[0]) + count(cover.begin(), cover.end(), b[1]);
        });

        vector<int>& edge = edges.back();

        if (count(cover.begin(), cover.end(), edge[0]) == 0) {
            cover.push_back(edge[0]);
        }
        if (count(cover.begin(), cover.end(), edge[1]) == 0) {
            cover.push_back(edge[1]);
        }

        for (auto it = edges.begin(); it != edges.end();) {
            if (count(cover.begin(), cover.end(), (*it)[0]) > 0 ||
                count(cover.begin(), cover.end(), (*it)[1]) > 0) {
                it = edges.erase(it);
            } else {
                ++it;
            }
        }
    }
    
    return cover;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter edges (as pairs of vertices):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    vector<int> cover = vertexCover(V, edges);
    
    cout << "Vertex cover: ";
    for (int i : cover) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
