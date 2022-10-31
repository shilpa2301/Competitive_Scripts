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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        stack<TreeNode*> Q, next;
        int leftToRight=1;
        Q.push(root);
        cout<<"first no: "<<Q.top()->val<<endl;
       // Q.push(NULL);
        
        TreeNode *temp;
        vector<int> individual;
        while(!Q.empty())
        {
            temp=Q.top();
            Q.pop();
            if (temp)
                cout<<"temp= "<<temp->val<<endl;
             if(temp)
            {
                individual.push_back(temp->val);
                cout<<"pushed= "<<temp->val<<endl;
                if(leftToRight)
                {
                    if(temp->left)
                        next.push(temp->left);
                    if(temp->right)
                        next.push(temp->right);
                    
                }
                else
                {
                    if(temp->right)
                        next.push(temp->right);
                    if(temp->left)
                        next.push(temp->left);
                    
                }
                
            }
            if(Q.empty())
                {
                  //  Q.push(NULL);
                    ret.push_back(individual);
                    individual.clear();
                    leftToRight=1-leftToRight;
                    
                    stack<TreeNode*> dummy=Q;
                    Q=next;
                    next=dummy;
                    cout<<"level done"<<endl;
                }
       
        }
       /* if(Q.empty())
                {
                    cout<<"Last level done"<<endl;
                    Q.push(NULL);
                    ret.push_back(individual);
                    individual.clear();
                    //leftToRight=1-leftToRight;
                    
        }*/
        return ret;
    }
};