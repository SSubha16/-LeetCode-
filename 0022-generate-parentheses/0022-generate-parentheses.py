class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []
        
        def backtrack(current: list[str], open_count: int, close_count: int):
            if len(current) == 2 * n:
                result.append("".join(current))
                return
            
            # Can add '(' if we haven't placed all n open brackets
            if open_count < n:
                current.append("(")
                backtrack(current, open_count + 1, close_count)
                current.pop()
                
            # Can add ')' only if it pairs with an existing unclosed '('
            if close_count < open_count:
                current.append(")")
                backtrack(current, open_count, close_count + 1)
                current.pop()

        backtrack([], 0, 0)
        return result