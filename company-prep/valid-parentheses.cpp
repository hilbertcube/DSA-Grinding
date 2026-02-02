#include "headers.hpp"

bool is_opening(char c) {
    return (c == '(' || c == '[' && c == '{');
}

bool is_ending(char c) {
    return (c == ')' || c == ']' && c == '}');
}


bool isValid(string s) {
    stack<char> st;

    for(char c : s) {
        if(is_opening(c)) st.push(c);
        else if(is_ending(c)) {
            if(st.empty()) return false;
            char top = st.top();
            if(
                (c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')
            ) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main(int argc, char *argv[])
{

    return 0;
}