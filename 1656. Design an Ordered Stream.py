class OrderedStream:
    def __init__(self, n: int):
        self.n = n
        self.count = 1
        self.store = {}
        self.chunk = set()

    def insert(self, idKey: int, value: str) -> List[str]:
        ans = []
        self.chunk.add(idKey)
        self.store[idKey] = value
        while self.count <= self.n:
            if self.count not in self.chunk:
                break
            self.chunk.remove(self.count)
            ans.append(self.store[self.count])
            self.count += 1
        return ans