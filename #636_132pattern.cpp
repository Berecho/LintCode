class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        int o1,o2,i=0;
        stack<int> number;
        while(i<tokens.size()){
        if(tokens[i].compare("+")==0||tokens[i].compare("-")==0||tokens[i].compare("*")==0||tokens[i].compare("/")==0){
            o1=number.top();
            number.pop();
            o2=number.top();
            number.pop();
            if(tokens[i].compare("+")==0)
                number.push(o1+o2);
            else if(tokens[i].compare("-")==0)
                number.push(o2-o1);
            else if(tokens[i].compare("*")==0)
                number.push(o1*o2);
            else if(tokens[i].compare("/")==0)
                number.push(o2/o1);
        }
        else
            number.push(atoi(tokens[i].c_str()));
        i++;
        }
        return number.top();
        
    }
};
