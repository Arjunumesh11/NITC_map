#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;
vector<pair<int, int>> *G;       //weighted edge
vector<int> dist;               //distance from source
typedef pair<int, int> pii;      //pair int
typedef vector< pii > vii;      //vector of pair int int
vector<int> *map_direction;   //string containing the shortest map
void dj(int source, int N)
{
	vector<bool> visited(N, false);
	dist.assign(N, INT_MAX);
	dist[source] = 0;
	map_direction[source].push_back(source);
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push({ source,0 });
	while (!Q.empty())
	{
		int u = Q.top().first;
		Q.pop();
		visited[u] = true;
		for (auto &c : G[u])
		{
			if (!visited[c.first])
			{
				int w = c.second;
				int v = c.first;
				if (dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					map_direction[v] = map_direction[u];
					map_direction[v].push_back(v);
					Q.push({ v,dist[v] });
				}
			}
		}


	}
}
int main()
{
	int N, M, u, v, w, source, destination;
	vector<string> place;
	string temp_place; int index_place;
	ifstream fin("map.txt");
	fin >> N;
	map_direction = new vector<int>[N];
	fin >> M;
	G = new vii[N + 1];
	for (int i = 0; i < N; i++)
	{
		fin >> index_place; fin >> temp_place;
		place.push_back (temp_place);
	}
	for (int i = 0; i < M; ++i)
	{
		fin >> u;
		fin >> v;
		fin >> w;
		G[u].push_back({ v,w });
		G[v].push_back({ u,w });
	}
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < G[i].size(); j++)
			cout << "(" << G[i][j].first << " ," << G[i][j].second << ")";
		cout << endl;
	}*/
	cout << "Enter source : \n";
	for (int i = 0; i < N; i++)
	{
		cout << endl << i << " . " << place[i];
	}
	cout << endl << "Enter no 0-" << N - 1 << " : ";
	cin >> source;
	system("CLS");
	dj(source, N);
	cout <<endl<< "Enter destination : \n";
	for (int i = 0; i < N; i++)
	{
		cout << endl << i << " . " << place[i];
	}
	cout << endl << "Enter no 0-" << N - 1<<" : ";
	cin >> destination;
	 /* for(int i=0;i<N;i++)
		  cout<<dist[i]<<" ";
	  cout<<endl;*/
	  fin.close();
	  system("CLS");
	  cout << endl << endl << endl;
	  for (int i = 0; i < map_direction[destination].size()-1; i++)
	  {
		  cout << place[map_direction[destination][i]] << " -> ";
	}
	  cout << place[map_direction[destination].back()];
	  cin.get();
	  cin.get();
	return 0;
	
}