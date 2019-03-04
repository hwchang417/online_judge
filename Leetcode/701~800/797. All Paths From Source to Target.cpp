
#define foreach(index, size) for(index = 0;index < size;index++)
#define foreach(index, from, size) for(index = from;index < size;index++)


class Solution {
public:
	int cnt;
	void dfs(vector<vector<int>>& graph, vector<vector<int>>& link, vector<int>& used, int index, int from){
		int i, size;
		size = graph.size();
		
		if(from == size - 1){
			link.push_back(vector<int>(index + 1));
			for(i = 0;i < size;i++)
				if(used[i] != -1)
					link[cnt][used[i]] = i;
			cnt++;
			return;
		}
		
		used[from] = index;
		size = graph[from].size();
		for(i = 0;i < size;i++){
			int to = graph[from][i];
			used[to] = index + 1;
			dfs(graph, link, used, index + 1, to);
			used[to] = -1;
		}
		used[from] = -1;
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int index;
		vector<vector<int>> link;
		vector<int> used(graph.size());
		
		for(index = 0;index < graph.size();index++)
		   used[index] = -1;
		
		cnt = 0;
		dfs(graph, link, used, 0, 0);
		
		return link;
	}
};