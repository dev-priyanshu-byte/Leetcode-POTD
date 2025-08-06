class Solution {
public:
    struct Node{
        int val;
        int low;
        int high;
        Node* left;
        Node* right;
        Node(int x, int low, int high, Node *left, Node *right) : val(x), low(low), high(high), left(left), right(right) {}
    };
    Node* createTree(int low,int high){
        if(low==high)
        {
            Node* leaf=new Node(0,low,high,NULL,NULL);
            return leaf;
        }
        int mid=(low+high)/2;
        Node* temp=new Node(0,low,high,createTree(low,mid),createTree(mid+1,high));
        return temp;
    }
    int feed(Node* head,vector<int>&baskets){
        if(head->low==head->high)
        {
            return head->val=baskets[head->low];
        }
        int left=feed(head->left,baskets);
        int right=feed(head->right,baskets);
        return head->val=max(left,right);
    }
    int find(int key,Node* head)
    {
        if(head->low==head->high) return head->low;
        if(head->left!=NULL&&head->left->val>=key) return find(key,head->left);
        else return find(key,head->right);
    }
    int update(int index,Node *head ){
        if(head->low==head->high) return head->val=0;
        int mid=(head->low+head->high)/2;
        if(index<=mid) return head->val=max(head->right->val,update(index,head->left));
        else return head->val=max(head->left->val,update(index,head->right));
    }
    void traverse(Node* head){
        if(head==NULL)
        return;
        cout<<head->val<<" "<<head->low<<"-"<<head->high<<endl;
        traverse(head->left);
        traverse(head->right);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int low=0,high=baskets.size()-1;
        Node* head=createTree(low,high);
        int mx=feed(head,baskets),count=0;
        for(int i=0;i<fruits.size();i++)
        {
            if(head->val<fruits[i])
            {
                count++;
                continue;
            }
            int index=find(fruits[i],head);
            mx=update(index,head);
        }
        return count;

    }
};                                                  