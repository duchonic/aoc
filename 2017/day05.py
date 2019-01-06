# coding: utf-8
# %load day05.py
# %load day05.py
def trampoline(data):
    maze = list()
    
    for line in data.split('\n'):
        maze.append(line)
    
    start = 0
    steps = 0
    jump = 0
    while 1:
        try:
            jump = maze[start]
            if int(jump) < 3:
                maze[start] = int(maze[start]) + 1
            else:    
                maze[start] = int(maze[start]) - 1
                            
            start += int(jump)   
            steps += 1
        except:
            break

    print(maze)
    return steps
