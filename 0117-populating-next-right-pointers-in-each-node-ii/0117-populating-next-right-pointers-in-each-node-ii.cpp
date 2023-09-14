class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node*> q;
        if(root)q.push(root);
        
        int ln;
        while(!q.empty()){
            
            ln= q.size();
            for(int i=0;i<ln;i++){
                
                auto temp= q.front();
                q.pop();
                
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);

                if(i== ln-1) temp->next= NULL;
                else temp->next= q.front();
            }
        }
        return root;
    }
};