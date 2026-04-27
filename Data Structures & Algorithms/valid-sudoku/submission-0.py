class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Validate rows
        for r in range(0, 9):
            if not isValidSelection(board, r, r + 1, 0, 9):
                return False
        
        # Validate cols
        for c in range(0, 9):
            if not isValidSelection(board, 0, 9, c, c + 1):
                return False

        # Validate 3x3 squares:
        for r in range(0, 9, 3):
            for c in range(0, 9, 3):
                if not isValidSelection(board, r, r + 3, c, c + 3):
                    return False

        # All selections were valid
        return True
        
# Returns whether the rectangular selection:
# row_start <= r < row_end AND col_start <= c < col_end
def isValidSelection(board: List[List[str]], row_start, row_end, col_start, col_end) -> bool:
    count = [0 for _ in range(10)]
    for r in range(row_start, row_end):
        for c in range(col_start, col_end):
            if board[r][c] == '.':
                continue
            # By constraint, board[r][c] is a digit 1-9
            num = int(board[r][c])
            count[num] += 1

    for num in range(1, 10):
        if count[num] > 1:
            return False

    return True
