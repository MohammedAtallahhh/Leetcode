/* 
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    - Open brackets must be closed by the same type of brackets.
    - Open brackets must be closed in the correct order.
    - Every close bracket has a corresponding open bracket of the same type.
*/

#include <iostream>
#include <stack>

using namespace std;

bool ArePair(char open, char close) {
    if (open == '(' && close == ')') 
        return true;
    else if (open == '{' && close == '}') 
        return true;
    else if (open == '[' && close == ']')
        return true;
    return false;
}

bool isValid(string s) {
    stack<char>  S;
    int length = s.length();
    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            S.push(s[i]);
        
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (S.empty() || !ArePair(S.top(), s[i]))
                return false;
        
            else
                S.pop();
        }
    }
    return S.empty() ? true : false;
}

int main() {
    string s = "()[]{})";

    cout << isValid(s) << endl;
}