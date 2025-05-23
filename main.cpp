/*
 Author: Carter Lewis
 Assignment title: Program 5
 Assignment description: Chromatic Number
 Due date: 3-2-2025
 Date created: 2-27-2025
 Date last modified: 2-27-2025
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

int chromaticNumber(vector<vector<int> > g, int* tab) {
    size_t n = g.size();
    int cNum = 1;
    
    for(size_t i = 1; i < n; i++) {
        set<int> unavailableColors;
        
        //fill unavailableColors
        for(int v: g[i]) {     //v = vertices reachable by i - edge(i,v)
            if(tab[v] != -1) {   // if v has been colored,
                                //insert color to unavailable colors
                unavailableColors.insert(tab[v]);
            }
        }
    
        //find smallest available color for v
        for(int c = 1;; c++) {
            if(unavailableColors.find(c)==unavailableColors.end()) {
                tab[i] = c;
                if(c > cNum) {
                    cNum = c;
                }
                break;
            }
        }
    }
    return cNum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    vector<vector<int> > graph;
    char a, b;
    int size = 0;
    
    while(n-- > 0) {
        cin >> a >> b;
        while(size <= max(a, b)) {
            size++;
            vector<int> p;
            graph.push_back(p);
        }
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int tab[graph.size()];
    memset(tab, -1, graph.size() * sizeof(int));
    
    cout << chromaticNumber(graph, tab) << endl;
    return 0;
}
