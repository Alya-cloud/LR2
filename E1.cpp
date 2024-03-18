#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> operands;

    stringstream ss(expression);
    string token;
    while (ss >> token) {
        if (token == "+") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(operand1 + operand2);
        }
        else if (token == "-") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(operand1 - operand2);
        }
        else if (token == "*") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(operand1 * operand2);
        }
        else {
            int operand;
            stringstream(token) >> operand;
            operands.push(operand);
        }
    }

    return operands.top();
}

int main() {
    string expression;
    getline(cin, expression);

    int result = evaluatePostfix(expression);
    cout << result << endl;

    return 0;
}