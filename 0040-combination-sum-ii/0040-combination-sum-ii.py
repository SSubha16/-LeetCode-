class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        candidates.sort()
        results = []

        def backtrack(start: int, remain: int, current_path: list[int]):
            if remain == 0:
                results.append(list(current_path))
                return

            for i in range(start, len(candidates)):
                # If current candidate exceeds remaining sum, no subsequent candidate can fit
                if candidates[i] > remain:
                    break

                # Skip duplicates at the same recursion depth
                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                current_path.append(candidates[i])
                # Recurse with i + 1 because each element may only be used once
                backtrack(i + 1, remain - candidates[i], current_path)
                current_path.pop()

        backtrack(0, target, [])
        return results