# coding: utf-8
def calcMemory(nr):
    '''
    37                31
       17 16 15 14 13 30          2 1 0 1 2
       18  5  4  3 12 29          1       1
       19  6  1  2 11 28          0       0
       20  7  8  9 10 27          1       1
       21 22 23 24 25 26          2 1 0 1 2
    43                49
    
    1, 9, 25, ... -> 1*1, 3*3, 5*5, 7*7, ...
    
    circle 1 radius 1 seite 1 umfang 1
    circle 2 radius 2 seite 3 umfang 8                distance 0:2,4,6,8      1:3,5,7,8
    circle 3 radius 3 seite 5 umfang 16 (seite-1 x 4) distance 0:11,15,19,23  1:10,12,14,16,18,20,22,24 2:13,17,21,25
    circle 4 radius 4 seite 7 umfang 36 (seite-1 x 4) distance 0:28,34,40,46  1:27,29
  
    '''
    
    manhattenToCenter = -1
    for circle in range(1,1001,2):
        manhattenToCenter += 1
        if circle**2 >= nr:
            outerSide = circle**2
            sideLength = circle
            innerSide = (outerSide-2)**2
            break    
        
    diff = outerSide - nr    

    if nr == outerSide \
      or nr == outerSide-(sideLength-1) \
        or nr == outerSide-2*(sideLength-1) \
          or nr == outerSide-3*(sideLength-1):
        
              print('corner')
    elif nr < outerSide - 3*(sideLength-1):
        print('right')
    elif nr < outerSide - 2*(sideLength-1):
        print('up')
        left = outerSide - 2*(sideLength-1)
        right = outerSide - 3*(sideLength-1)
        middle = int( left - (sideLength-1)/2 )
        distanceToMiddle = abs(middle-nr)
        print(middle-nr)        
        print(left, middle, right)
    elif nr < outerSide - 1*(sideLength-1):
        print('left')
    else:
        print('down')

    return nr, outerSide, diff, manhattenToCenter+distanceToMiddle

print(calcMemory(4))
print(calcMemory(14))
print(calcMemory(36))
print(calcMemory(1024))
print(calcMemory(347991))
