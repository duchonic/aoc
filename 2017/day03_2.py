# coding: utf-8
class Moving:
    x = 10
    y = 10
    
    #dir r=0, u=1, l=2, d=3
    dir_ = 0 
    count = 1
    grid = 0
    
    def __init__(self):
        print('init')
        self.grid = list()
        for i in range(20):
            self.grid.append([0]*20)
        self.grid[self.y][self.x] = 1
        self.x += 1
        self.dir_ += 1
        
    def move(self, moves):
        
        def calcValue(grid, y, x):
            
            value =  grid[y-1][x+1]
            value += grid[y][x+1]
            value += grid[y+1][x+1]
            value += grid[y-1][x]
            value += grid[y+1][x]
            value += grid[y-1][x-1]
            value += grid[y][x-1]
            value += grid[y+1][x-1]
            
            if value > 347991:
                print('value:', value)    
                
            return value
        
        print(self.dir_)
        if self.dir_ == 0:
            for m in range(moves):
                self.grid[self.y][self.x] = calcValue(self.grid, self.y, self.x)
                self.x += 1
        elif self.dir_ == 1:
            for m in range(moves):
                self.grid[self.y][self.x] = calcValue(self.grid, self.y, self.x)
                self.y -= 1
        elif self.dir_ == 2:
            for m in range(moves):
                self.grid[self.y][self.x] = calcValue(self.grid, self.y, self.x)
                self.x -= 1
        elif self.dir_ == 3:
            for m in range(moves):
                self.grid[self.y][self.x] = calcValue(self.grid, self.y, self.x)
                self.y += 1
        else:
            assert 0
            
        if self.dir_ == 3:
            self.dir_ = 0
        else:   
            self.dir_ += 1
            
    def pos(self):
        return self.x, self.y
    def fullGrid(self):
        return self.grid
    
test = Moving()
grid = list()
for i in range(20):
    grid.append([0]*20)
corner = 1

moves = list()
for i in range(1,9):
    moves.append(i)
    moves.append(i)

moves.pop(0)
for move in moves:
    test.move(move)
    pos = test.pos()
    grid[pos[1]][pos[0]] = corner
    corner += 1
    print(pos)
    
res = test.fullGrid()
for line in res:
    print(line)
