class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands;
        for (string token : tokens) {
            // Operation
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                processOperation(operands, token[0]);
            }
            // Operand
            else {
                operands.push(std::atoi(token.c_str()));
            }
        }
        // After processing all tokens, there should be exactly one value in the operands stack, 
        // which is the overal result of the RPN expression
        if (operands.size() > 1)
            throw std::invalid_argument("Evaluation of RPN expression incomplete. More than 1 operand remaining on stack");
        
        return operands.top();
    }

private:
    void processOperation(std::stack<int>& operands, char op) {
        // Pop two operands off the stack and push the result
        int second = operands.top();
        operands.pop();
        int first = operands.top();
        operands.pop();
        // Compute the result
        int result = 0;
        switch (op) {
            case '+':
                result = first + second;
                break;
            case '-':
                result = first - second;
                break;
            case '*':
                result = first * second;
                break;
            case '/':
                result = first / second;
                break;
        };
        // Push the result onto the stack
        operands.push(result);
    }
};
