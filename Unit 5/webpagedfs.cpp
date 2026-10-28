#include <iostream>
#include <vector>
using namespace std;

class WebGraph {
    int pages;
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    WebGraph(int n) {
        pages = n;
        adj.resize(n);
        visited.resize(n, false);
    }

    void addLink(int from, int to) {
        adj[from].push_back(to);
    }

    void DFS(int page) {
        visited[page] = true;
        cout << "Web Page " << page << " visited" << endl;

        for (int next : adj[page]) {
            if (!visited[next]) {
                DFS(next);
            }
        }
    }

    void explorePages(int start) {
        fill(visited.begin(), visited.end(), false);

        cout << "\nDFS Traversal:\n";
        DFS(start);
    }
};

int main() {
    int n, links, from, to, start;

    cout << "Enter number of web pages: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of pages must be positive.\n";
        return 0;
    }

    WebGraph web(n);

    cout << "Enter number of hyperlinks: ";
    cin >> links;

    if (links < 0) {
        cout << "Invalid number of hyperlinks.\n";
        return 0;
    }

    cout << "Enter hyperlinks (source destination):\n";

    for (int i = 0; i < links; i++) {
        cin >> from >> to;

        if (from < 0 || from >= n || to < 0 || to >= n) {
            cout << "Invalid page number. Try again.\n";
            i--;
            continue;
        }

        web.addLink(from, to);
    }

    cout << "Enter starting web page (0 to "
         << n - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= n) {
        cout << "Invalid starting page.\n";
        return 0;
    }

    web.explorePages(start);

    return 0;
}