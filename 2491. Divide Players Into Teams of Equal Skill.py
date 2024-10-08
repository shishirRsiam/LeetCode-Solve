class Solution:
    def dividePlayers(self, skill: List[int]) -> int:

        skill.sort()
        ans, i, j = 0, 0, len(skill) - 1
        target = skill[0] + skill[-1]

        while i < j:
            if skill[i] + skill[j] != target:
                return -1

            ans += (skill[i] * skill[j])
            i += 1
            j -= 1

        return ans