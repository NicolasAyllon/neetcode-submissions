class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // In RPN, the two arguments come before the operator
        // (arg1, arg2, op)
        std::stack<int> args;
        // While there are still more tokens, we'll read two
        for (const string& token : tokens) {
            printStack(args);
            // If the token is an operator, 
            // take two values off the arg stack, evaluate, 
            // and push the result back on the stack
            if (is_operator(token)) {
                std::cout << "Processing token " << token << '\n';
                int arg2 = args.top(); args.pop();
                int arg1 = args.top(); args.pop();
                std::cout << "\t arg1 = " << arg1 << ", arg2 = " << arg2 << '\n';

                int res = 0;
                char op = token[0];
                switch(op) {
                    case '+':
                        res = arg1 + arg2;
                        break;
                    case '-':
                        res = arg1 - arg2;
                        break;
                    case '*':
                        res = arg1 * arg2;
                        break;
                    case '/':
                        res = arg1 / arg2;
                        break;
                    default:
                        throw std::invalid_argument("Expected operator to be one of {+, - , *, /} but got " + op);
                }
                // Push result on stack
                args.push(res);
            }
            // Try to process as a number.
            else {
                int num = std::stoi(token);
                args.push(num);
            }
        }
        // All tokens processed and there must be only 1 argument on the stack, which is the result
        if (args.size() == 1)
            return args.top();
        else
            throw std::invalid_argument("RPN expression couldn't be evaluated completely. Please check the expression.");
        
    }
private:
    bool is_operator(const string& s) {
        return s.size() == 1 && 
               (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/');
    }

    // Pass stack by value so we can empty it without modifying original
    void printStack(std::stack<int> s) {
        std::cout << "top-> ";
        for (; !s.empty(); s.pop()) {
            std::cout << s.top() << " ";
        }
        std::cout << '\n';
    }
};
