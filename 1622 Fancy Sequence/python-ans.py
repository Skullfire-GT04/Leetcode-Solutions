# This is the first problem I solved on the new account, so kind of special I guess


class Fancy:

    def __init__(self):
        self.sequence = list()
        self.mul = 1
        self.add = 0
        self.MOD = 10 ** 9 + 7

    def append(self, val : int) -> None:
        inv = pow(self.mul, -1, self.MOD)
        normal = (val - self.add) * inv
        self.sequence.append(normal % self.MOD)

    def addAll(self, inc : int) -> None:
        self.add = (self.add + inc) % self.MOD

    def multAll(self, m : int) -> None:
        self.mul = (self.mul * m) % self.MOD
        self.add = (self.add * m) % self.MOD

    def getIndex(self, idx : int) -> int:
        return -1 if idx < 0 or idx >= len(self.sequence) else (self.self.sequence[idx] * self.mul + self.add) % self.MOD
                                                                