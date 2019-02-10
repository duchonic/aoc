# aoc day06.py
#
#        0 1 2 3 4 . -> x
#
#   0    0 1 2 3 4
#   1    5 6 7 8 9
#   2    0 1 2 3 4
#
#   |
#   v
#
#   y
#
#        x,y
#   pos (1,2) to (2,3)  -> 1+(2*5) to 2+(3*5)
#
import numpy as np


class Lights:
    def __init__(self):
        self.result = np.zeros([1000, 1000])

    def getPos(self, data):
        return [int(data.split(',')[0]), int(data.split(',')[1])]

    def turnOn(self, start, stop):
        mStart = self.getPos(start)
        mStop = self.getPos(stop)
        for y in range(mStart[0], mStop[0]+1):
            for x in range(mStart[1], mStop[1]+1):
                self.result[y, x] += 1

    def turnOff(self, start, stop):
        mStart = self.getPos(start)
        mStop = self.getPos(stop)
        for y in range(mStart[0], mStop[0]+1):
            for x in range(mStart[1], mStop[1]+1):
                if self.result[y, x] > 0:
                    self.result[y, x] -= 1

    def toggle(self, start, stop):
        mStart = self.getPos(start)
        mStop = self.getPos(stop)
        print(mStart, mStop)
        for y in range(mStart[0], mStop[0]+1):
            for x in range(mStart[1], mStop[1]+1):
                self.result[y, x] += 2

    def getlights(self):
        print(self.result.sum())
        print(self.result)


mlights = Lights()

with open('2015/day06.data') as file:
    data = file.read()
    for line in data.split('\n'):
        print(line)
        if "turn off" in line:
            mlights.turnOff(line.split()[2], line.split()[4])
        elif "turn on" in line:
            mlights.turnOn(line.split()[2], line.split()[4])
        elif "toggle" in line:
            mlights.toggle(line.split()[1], line.split()[3])


print(mlights.getlights())
print('358530 is too low')
print('400410 is correct')
