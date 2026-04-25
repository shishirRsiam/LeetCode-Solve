class Solution:
    def trafficSignal(self, timer: int) -> str:
        if not timer:
            return "Green"
        if timer == 30:
            return "Orange"
        if 30 < timer <= 90:
            return "Red"
        return "Invalid"