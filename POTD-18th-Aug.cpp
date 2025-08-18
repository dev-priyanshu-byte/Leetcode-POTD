class Solution {
public:
    vector<vector<double>> sub;
    vector<vector<char>> operations;
    double perform(double a,double b, char operation){
        if(operation=='+')
        return a+b;
        else if(operation=='-')
        return a-b;
        else if(operation=='*')
        return a*b;
        else
        return a/b;
    }
    bool func(vector<double>& cards,vector<char>& operation){ //(a?b)?(c?d)
    double r1 = perform(perform(perform(cards[0], cards[1], operation[0]), cards[2], operation[1]), cards[3], operation[2]); // ((ab)c)d
    double r2 = perform(perform(cards[0], perform(cards[1], cards[2], operation[1]), operation[0]), cards[3], operation[2]); // (a(bc))d
    double r3 = perform(cards[0], perform(perform(cards[1], cards[2], operation[1]), cards[3], operation[2]), operation[0]); // a((bc)d)
    double r4 = perform(cards[0], perform(cards[1], perform(cards[2], cards[3], operation[2]), operation[1]), operation[0]); // a(b(cd))
    double r5 = perform(perform(cards[0], cards[1], operation[0]), perform(cards[2], cards[3], operation[2]), operation[1]); // (ab)(cd)
    double r6 = perform(perform(cards[0], perform(cards[1], cards[2], operation[1]), operation[0]), cards[3], operation[2]); // a(bc)d
    double r7 = perform(perform(cards[0], cards[1], operation[0]), perform(cards[2], cards[3], operation[2]), operation[1]); // (ab)cd
    double r8 = perform(cards[0], perform(cards[1], perform(cards[2], cards[3], operation[2]), operation[1]), operation[0]); // ab(cd)
        r1=round(r1 * 1e5)/ 1e5;
        r2=round(r2 * 1e5)/ 1e5;
        r3=round(r3 * 1e5)/ 1e5;
        r4=round(r4 * 1e5)/ 1e5;
        r5=round(r5 * 1e5)/ 1e5;
        r6=round(r6 * 1e5)/ 1e5;
        r7=round(r7 * 1e5)/ 1e5;
        r8=round(r8 * 1e5)/ 1e5;
        
        if(r1==24||r2==24||r3==24||r4==24||r5==24||r6==24||r7==24||r8==24)
        return true;
        return false;
    }

    void permutations(vector<int>&cards,vector<int>& visited,vector<double>& temp){
        if(temp.size()==cards.size())
        sub.push_back(temp);
        for(int j=0;j<cards.size();j++)
        {
            if(visited[j]==0)
            {
                visited[j]=1;
                temp.push_back(cards[j]);
                permutations(cards,visited,temp);
                temp.pop_back();
                visited[j]=0;
            }
        }
    }
    void operate(vector<char>&operators,vector<char>& temp){
        if(temp.size()==3)
        {
            operations.push_back(temp);
            return;
        }
        for(int j=0;j<operators.size();j++)
        {
            temp.push_back(operators[j]);
            operate(operators,temp);
            temp.pop_back();
        }
    }
    bool judgePoint24(vector<int>& cards) {
      
        vector<double> temp;
        vector<int> visited(4,0);
        permutations(cards,visited,temp);
        vector<char> tempp;
        vector<char> operators;
        operators={'+','-','*','/'};
        operate(operators,tempp);
       // cout<<operations.size();
        bool ans=false;
        for(int i=0;i<sub.size();i++)
        {
            for(int j=0;j<operations.size();j++)
            {
                ans=ans||func(sub[i],operations[j]);
            }
        }
        return ans;
    }
};