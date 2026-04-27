class Solution:
    def isValid(self, s: str) -> bool:
        opens = []
        for c in s:
            # Open paren
            if c == '(' or c == '{' or c == '[':
                opens.append(c)
                continue
            # Close paren
            if opens:
                if c == ')' and opens[-1] == '(' or \
                   c == '}' and opens[-1] == '{' or \
                   c == ']' and opens[-1] == '[':
                   opens.pop()
                   continue
            # We enountered a close paren and there is either no open parens
            # or the wrong open paren.
            return False

        # We checked every character in the string and never found any mismatched close parens
        # The string is valid if every open paren was matched (and popped) from the 'opens' stack
        return not opens # whether the opens stack is empty