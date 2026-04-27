class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operands = []
        operations = "+-*/"

        for token in tokens:
            # Operation
            if token in operations:
                # Get operands, keeping in mind that the first one popped is the right operand
                right = operands.pop()
                left = operands.pop()
                print(f"operands {left}, {right}")
                # Compute result
                result = 0
                match token[0]:
                    case '+':
                        result = left + right
                        print(f"result = {left} + {right} = {result}")
                    case '-':
                        result = left - right
                        print(f"result = {left} - {right} = {result}")
                    case '*':
                        result = left * right
                        print(f"result = {left} * {right} = {result}")
                    case '/':
                        if right == 0:
                            raise ZeroDivisionError
                        result = int(left / right)
                        # Floor division (//) rounds towards -infinity, and only achieves rounding toward zero for positive numbers
                        # Instead, use pure division / and cast to int to round toward 0
                        print(f"result = {left} / {right} = {result}")
                # Push the result back onto the operand stack
                operands.append(result)
            # Operand
            else:
                operands.append(int(token))
        
        # After all tokens are processed, we should have only one operand on the stack, which is the final result
        if len(operands) > 1:
            raise ValueError("RPN evaluation incomplete. More than 1 operand remaining on stack")

        return operands[0]


        