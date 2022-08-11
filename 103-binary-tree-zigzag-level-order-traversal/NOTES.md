**2 APPROACHES**
**1-USING QUEUE**
```
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int f=0;
        while(!q.empty()){
            vector<int> lev;
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* node=q.front();
                q.pop();
                lev.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            f++;
            if(f%2==0) reverse(lev.begin(),lev.end());
            ans.push_back(lev);
        }
        return ans;
    }
```

**2-USING TWO STACKS**
```
void solve(TreeNode* root,vector<vector<int>> &ans){
        if(root==NULL) return ;
        
        stack<TreeNode*> curr;
        stack<TreeNode*> next;
        
        bool leftToRight=true;
        
		//push  root to the curr
        curr.push(root);
         vector<int> v;
        while(!curr.empty()){
            TreeNode* node=curr.top();
            curr.pop();
            if(node){
                v.push_back(node->val);
				
				//add data in the next according to the order (leftToRight)
                if(leftToRight){
                    if(node->left){
                        next.push(node->left);
                    }
                    if(node->right){
                        next.push(node->right);
                    }
                }
                else{
                    if(node->right){
                        next.push(node->right);
                    }
                    if(node->left){
                        next.push(node->left);
                    }
                }
            }
            
            if(curr.empty()){
                ans.push_back(v);
                leftToRight=!leftToRight;
                swap(curr,next);
                v.clear();
            }
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,ans);
        return ans;
    }
```
