from collections import defaultdict


class Solution:

  def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
    groups = defaultdict(list)

    for s in strs:
      # Sort characters and use the resulting string/tuple as key
      key = "".join(sorted(s))
      groups[key].append(s)

    return list(groups.values())