/*Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES*/

---------------------****-------------------------------

int Solution::braces(string a) {
   
    // stack which contains the
    // operators and braces
    stack<char> st;
    int i = 0; // index
    
    // iterating through all the chars
    while(i<a.length()){
       char c = a[i];
            // pushing these characters into stack
            if(c == '(' || c =='+' || c == '*' || c == '/' || c =='-'){
               st.push(c); 
            }
            // if we encounter 
            // closed braces
            else if(c == ')'){
                // if on top we have
                // open brace, redundant
                if(st.top() == '('){
                   return 1; 
                }
                // else, pop till we have
                // open brace or empty stack
                while(!st.empty() && st.top()!= '('){
                    st.pop();
                }
                // if now on top we have
                // open, pop it and continue
                if(st.top()=='('){
                    st.pop();
                }
            }
       i++; // index increment
    }
    // if no redundancy i.e, we have atleast 
    // one operator between braces
    return 0; 
}


