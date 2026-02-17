class Solution:
    def toggleLightBulbs(self, bulbs: list[int]) -> list[int]:
        turn_on = set()
        for bulb in bulbs:
            if bulb not in turn_on:
                turn_on.add(bulb)
            else:
                turn_on.remove(bulb)
        return sorted(list(turn_on))