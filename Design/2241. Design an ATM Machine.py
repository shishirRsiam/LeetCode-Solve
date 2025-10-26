class ATM:
    def __init__(self):
        self.notes = [0] * 5

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(5):
            self.notes[i] += banknotesCount[i]

    def withdraw(self, amount: int) -> List[int]:
        index = 4
        ans = [0] * 5
        note = [20, 50, 100, 200, 500]

        while index >= 0:
            maximum_note_count = min(self.notes[index], int(amount / note[index]))

            ans[index] += maximum_note_count
            self.notes[index] -= maximum_note_count
            amount -= note[index] * maximum_note_count
            index -= 1

        if amount:
            for i in range(5):
                self.notes[i] += ans[i]
            return [-1]
        return ans