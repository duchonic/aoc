# coding: utf-8
def santaRun(data):
    visitedHouses = {(0,0)}
    X = 0
    Y = 1
    actualCoordinate = [0,0]
    for item in data:
        if item == '<':
            actualCoordinate[X] -= 1
        elif item == '>':
            actualCoordinate[X] += 1
        elif item == '^':
            actualCoordinate[Y] += 1
        elif item == 'v':
            actualCoordinate[Y] -= 1
        else:
            assert 0
        visitedHouses.add((actualCoordinate[X],actualCoordinate[Y]))
    return (len(visitedHouses))


def santaRunAndRobo(data):
    visitedHouses = {(0,0)}
    X = 0
    Y = 1
    SANTA = 0
    ROBOT = 1
    actualCoordinate = [[0,0],[0,0]]
    for nr, item in enumerate(data):

        if nr%2 == 0:
            roboSanta = SANTA
        elif nr%2 == 1:
            roboSanta = ROBOT

        if item == '<':
            actualCoordinate[roboSanta][X] -= 1
        elif item == '>':
            actualCoordinate[roboSanta][X] += 1
        elif item == '^':
            actualCoordinate[roboSanta][Y] += 1
        elif item == 'v':
            actualCoordinate[roboSanta][Y] -= 1
        else:
            assert 0
        visitedHouses.add((actualCoordinate[roboSanta][X],actualCoordinate[roboSanta][Y]))
    return (len(visitedHouses))
