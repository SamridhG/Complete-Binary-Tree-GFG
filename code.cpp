 bool isCompleteBT(Node* root){
        //code here
        stack<int>check;
        queue<Node *>q;
        vector<vector<int>>res;
        vector<int>A;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node *temp=q.front();
                q.pop();
                if(temp!=NULL)
                {
                    A.push_back(temp->data);
                    q.push(temp->left);
                    q.push(temp->right);
                }
                else
                {A.push_back(-1);
            }
            }
            res.push_back(A);
            A.clear();
        }
      
        int p=res.size();
        
        for(int i=0;i<p-2;i++)
        {
            int node=pow(2,i);
            if(res[i].size()!=node || find(res[i].begin(),res[i].end(),-1)!=res[i].end())
            {
                return false;
            }
        }
        check.push(res[p-2][res[p-2].size()-1]);
        for(int i=res[p-2].size()-2;i>=0;i--)
        {
          
            if(check.top()>0 && res[p-2][i]<0)
            {
                return false;
            }
            check.push(res[p-2][i]);
        }
        return true;
    }
