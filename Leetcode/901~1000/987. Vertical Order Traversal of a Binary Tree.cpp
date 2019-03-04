/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef struct coord{
    int y, val;
}Coord;

bool cmp(Coord &a, Coord &b){
    return a.y > b.y || a.y == b.y && a.val < b.val;
}

class Solution {
public:
    map<int, vector<Coord>> coord;
    void dfs(TreeNode *root, int x, int y){
        Coord c;
        if(root == NULL) return;
        dfs(root->left, x - 1, y - 1);
        dfs(root->right, x + 1, y - 1);
        c.y = y; c.val = root->val;
        coord[x].push_back(c);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<Coord>>::iterator iter;
        vector<vector<int>> res;
        dfs(root, 0, 0);
        for(iter = coord.begin();iter != coord.end();iter++){
            vector<int> tmp;
            sort(iter->second.begin(), iter->second.end(), cmp);
            for(Coord n : iter->second)
                tmp.push_back(n.val);
            res.push_back(tmp);
        }
        return res;
    }
};