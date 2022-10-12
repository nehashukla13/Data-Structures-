class Solution(object): # best 24 ms
    def crackSafe(self, n, k):
        # n: length of password
        # k: kinds of digits (0,1,2....)
        
        if n == 1: return "".join(str(i) for i in range(k))
        if k == 1: return "0" * n

        suffixMap = {}
        allCombination = "0" * (n-1)

        for _ in range(k**n):
            # get suffix
            suffix = allCombination[1-n:]
            # create suffix map, value is k - 1 or update previous value - 1
            suffixMap[suffix] = suffixMap.get(suffix, k) - 1
            # add new suffix
            allCombination += str(suffixMap[suffix])

        return allCombination
