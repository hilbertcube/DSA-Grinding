#include "headers.hpp"

int calculate(string s) {
  // remove all spaces
  auto end_pos = std::remove(s.begin(), s.end(), ' ');
  s.erase(end_pos, s.end());

  vector<string> process = tokenize(s);

  stack<int> stk;
  stk.push(stoi(process[0]));

  for (int i = 1; i < process.size(); i += 2) {
    string op = process[i];
    int num = stoi(process[i + 1]);

    if (op == "+") {
      stk.push(num);
    } else if (op == "-") {
      stk.push(-num);
    } else if (op == "*") {
      int left = stk.top(); stk.pop();
      stk.push(left * num);
    } else if (op == "/") {
      if (num == 0) {
        throw runtime_error("division by zero");
      }
      int left = stk.top(); stk.pop();
      stk.push(left / num);
    }
  }

  // sum all elemnents in stack
  int result = 0;
  while(!stk.empty()) {
      int top = stk.top(); stk.pop();
      result += top;
  }
  return result;
}

vector<string> tokenize(string& s) {
  if(s.empty()) return {};

  string accum;
  vector<string> output;

  auto is_operator = [](char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
  };

  for(auto& c : s) {
    if(isdigit(c)) {
      accum += c;
    } else {
      // push previously accumulated value, then clear
      if(!accum.empty()) {
        output.push_back(accum);
        accum.clear();
      }

      if (is_operator(c)) {
        output.push_back(string(1, c));
      }
    }
  }

  // handle final case
  if (!accum.empty()) output.push_back(accum);
  
  return output;
}

// non-tokenize
int calculate2(const string& s) {
  long result = 0;
  long last = 0;
  long curr = 0;
  char op = '+';

  for (int i = 0; i <= s.size(); ++i) {
    char c = (i < s.size()) ? s[i] : '+';

    if (isdigit(c)) {
      curr = curr * 10 + (c - '0');
    } else if (c != ' ') {
      if (op == '+') {
        result += last;
        last = curr;
      } else if (op == '-') {
        result += last;
        last = -curr;
      } else if (op == '*') {
        last *= curr;
      } else if (op == '/') {
        last /= curr;
      }

      op = c;
      curr = 0;
    }
  }

  return result + last;
}


int main () {


  return 0;
}