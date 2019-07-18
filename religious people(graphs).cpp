#include<iostream>
#include<map>
#include<queue>
#include<list>
#define ll long long int
using namespace std;
ll elem = 0;
class graph {
	ll nodes;
	map<ll, list<ll>> adjList;
public:
	graph(){}
	graph(ll nodes) {
		this->nodes = nodes;

	}
	void addEdge(ll u,ll v,ll w=6,bool bidir=true){
		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
	}
	void dfs_helper(ll src,map<ll,bool>&isVisited){
	// whenever u come to a node mark it visited
		isVisited[src] = true;
		elem++;
	//traverse recursively
		for (ll neighbour : adjList[src]) {
			if (!isVisited[neighbour]) {
				dfs_helper(neighbour, isVisited);
			}
		}
	
	
	}
	void dfs(ll start){
		ll ans = 0;
		map<ll, bool> isVisited;
		dfs_helper(start, isVisited);
		ans = elem;
		for (auto neighbour : adjList) {
			elem = 0;
			ll city = neighbour.first;
			if (!isVisited[city]) {
				dfs_helper(city, isVisited);
			}
			if (elem == 0) {
				continue;
			}
			else {
				ans = ans * elem;
			}
		}
		cout << ans;
	}



};
int main() {
	ll cities, roads;
	cin >> cities >> roads;
	ll city1, city2;
	graph g(cities);
	for (ll i = 0; i < roads; i++) {
		cin >> city1 >> city2;
		g.addEdge(city1, city2);
	}
	g.dfs(city1);
}