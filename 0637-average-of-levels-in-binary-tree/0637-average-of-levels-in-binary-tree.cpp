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
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double>averages;

        queue<TreeNode *>nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            int levelSize=nodeQueue.size();

            double levelSum=0.0;

            for(int i=0;i<levelSize;i++){
                TreeNode * currentNode =nodeQueue.front();
                nodeQueue.pop();

                levelSum+=currentNode->val;

                if(currentNode->left!=nullptr){
                    nodeQueue.push(currentNode->left);
                }
                if(currentNode->right!=nullptr){
                    nodeQueue.push(currentNode->right);
                }
            }
            averages.push_back(levelSum/levelSize);
        }
        return averages;
        
    }
};