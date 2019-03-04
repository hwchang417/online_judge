struct paper{
    int index, number;
    paper(int i, int n) : index(i), number(n){}
};

typedef struct paper Paper;

static bool compareNumber(const Paper& lhs, const Paper& rhs)
{
  return lhs.number < rhs.number;
}

static bool compareIndex(const Paper& lhs, const Paper& rhs)
{
  return lhs.index < rhs.index;
}

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int indexA, indexB;
        queue<int> qB;
        vector<Paper> b;
        vector<Paper> ans;
        vector<int> result;
        
        for(indexB = 0;indexB < B.size();indexB++)
            b.push_back(Paper(indexB, B[indexB]));
        
        sort(A.begin(), A.end());
        sort(b.begin(), b.end(), compareNumber);
        
        for(indexA = 0, indexB = 0;indexA < A.size();indexA++){
            if(A[indexA] > b[indexB].number){
                ans.push_back(Paper(b[indexB].index, A[indexA]));
                indexB++;
            }
            else
                qB.push(A[indexA]);
        }
        
        for(;indexB < B.size();indexB++){
            ans.push_back(Paper(b[indexB].index, qB.front()));
            qB.pop();
        }
        
        sort(ans.begin(), ans.end(), compareIndex);
        
        for(indexA = 0;indexA < ans.size();indexA++)
            result.push_back(ans[indexA].number);
        
        return result;
    }
};