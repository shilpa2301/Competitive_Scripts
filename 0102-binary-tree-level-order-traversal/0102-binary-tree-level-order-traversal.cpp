/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> Q;
        vector<vector<int>> ret;
        if (!root)
            return ret;
        
        Q.push(root);
        Q.push(NULL);
        TreeNode *temp;
        vector<int> vec_ind;
        while(!Q.empty())
        {
            temp=Q.front();
          //  if(temp)
            // cout<<"temp= "<<temp->val<<endl;
            Q.pop();
            if(!temp)
            {
                if(!Q.empty())
                {
                    Q.push(NULL);
                   // cout<<"end of a  level"<<endl;
                    ret.push_back(vec_ind);
                    vec_ind.clear();
                }
            }
            else{
            vec_ind.push_back(temp->val);
          //  cout<<"Pushed "<<temp->val<<endl;
            
            if(temp->left)
            {
                Q.push(temp->left);
            }
            if(temp->right)
            {
                Q.push(temp->right);
            }
            }
        }
        
         if(Q.empty())
                {
                    Q.push(NULL);
                  //  cout<<"end of last  level"<<endl;
                    ret.push_back(vec_ind);
                    vec_ind.clear();
                }
        return ret;
    }
};