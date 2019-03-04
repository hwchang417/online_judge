class Solution {
public:
    string s;
    vector<string> wordDict;
    vector<int> visited;
    int wsize;
    bool existInDictionary(int index){
        //wsize: word string size
        //tsize: test string size
        //rsize: remain string size
        
        int i, tsize, rsize;
        rsize = s.size() - index;
        
        if ( std::find(visited.begin(), visited.end(), rsize) != visited.end() )
           return false;
        
        visited.push_back(rsize);
        
        for(i = 0;i < wsize;i++){
            tsize = wordDict[i].size();
            if(rsize >= tsize){
                string tmp = s.substr(index, tsize);
                if(tmp == wordDict[i]){
                    if(rsize == tsize || existInDictionary(index + tsize))
                        return true;
                }
            }
        }
        
        
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict){
        this->s = s;
        this->visited = vector<int>();
        this->wordDict = wordDict;
        this->wsize = wordDict.size();
        return existInDictionary(0);
    }
};