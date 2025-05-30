   struct trieNode{
        trieNode* left;
        trieNode* right;
    };

    trieNode* root=new trieNode();

    void insert(trieNode* root,int& num){
        trieNode* pcrawl=root;
        for(int i=31;i>=0;i--){
            if(((num>>i)&1)!=0){
                if(pcrawl->right==NULL){
                    pcrawl->right=new trieNode();
                }
                pcrawl=pcrawl->right;
            }else{
                if(pcrawl->left==NULL){
                    pcrawl->left=new trieNode();
                }
                pcrawl=pcrawl->left;
            }
        }
    }

    int findMaxXOR(trieNode* root,int& num){
        int ithbit;
        int res=0;
        trieNode* pcrawl=root;
        for(int i=31;i>=0;i--){
            ithbit=((num>>i)&1);
            if(ithbit==0){ //0^1=1
                if(pcrawl->right!=NULL){
                    res+=pow(2,i);
                    pcrawl=pcrawl->right;
                }else{
                    pcrawl=pcrawl->left;
                }
            }else{
                if(pcrawl->left!=NULL){
                    res+=pow(2,i);
                    pcrawl=pcrawl->left;
                }else{
                    pcrawl=pcrawl->right;
                }
            }
        }

        return res;
    }

   int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();

        int maxXor=0;
        for(int i=0;i<n;i++){
            insert(root,nums[i]);
        }

        for(int i=0;i<n;i++){
            int temp=findMaxXOR(root,nums[i]);
            maxXor=max(maxXor,temp);
        }

        return maxXor;

    }
};
