#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& sequence) {
    stack<char> brackets;

    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            brackets.push(bracket);
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (brackets.empty()) {
                return false;
            }

            char top = brackets.top();
            brackets.pop();

            if ((bracket == ')' && top != '(') ||
                (bracket == ']' && top != '[') ||
                (bracket == '}' && top != '{')) {
                return false;
            }
        }
    }

    return brackets.empty();
}

int main() {
    string sequence;
    cin >> sequence;

    if (isBalanced(sequence)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}