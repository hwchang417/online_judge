class Solution {
public:
    
    int isConnected(string& a, string& b){
        int diff = 0, index, len;
        
        len = a.size();
        for(index = 0;index < len && diff <= 1;index++)
            if(a[index] != b[index])
                diff++;
        return diff == 1;
    }
    
    void constructGraph(vector<vector<int>>& graph, vector<string>& wordList){
        int row, col, wordSize;
        
        wordSize = wordList.size();
        for(row = 0;row < wordSize;row++){
            for(col = 0;col < wordSize;col++){
                if(row != col && isConnected(wordList[row], wordList[col])){
                    graph[row].push_back(col);
                }
            }
        }
    }
    
    int getShortestPath(vector<bool>& visit, vector<vector<int>>& graph, int end, vector<string>& wordList){
        int len, index, wordSize, listSize;
        queue<int> q;
        
        len = 1;
        wordSize = wordList.size();
        q.push(wordSize - 1);
        while(!q.empty()){
            int qsize = q.size();
            len++;
            while(qsize--){
                int from = q.front();
                q.pop();
                
                //avoid repetitive attempt in same word
                visit[from] = true;
                listSize = graph[from].size();
                for(index = 0;index < listSize;index++){
                    int to = graph[from][index];
                    //find shortest path
                    if(to == end) return len;
                    
                    if(visit[to]) continue;
                    
                    q.push(to);
                }
            }
        }
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int end, wordListSize;
        
        wordList.push_back(beginWord);
        wordListSize = wordList.size();
        
        vector<bool> visit(wordListSize);
        vector<vector<int>> graph(wordListSize);
        
        //check whether endWord is existing in wordList or not?
        for(end = 0;end < wordListSize 
            && wordList[end] != endWord;end++);
        if(end == wordListSize) return 0;
        
        fill(visit.begin(), visit.end(), false);
        visit[end] = visit[wordListSize - 1] = true;
        
        constructGraph(graph, wordList);
        return getShortestPath(visit, graph, end, wordList);
    }
};
