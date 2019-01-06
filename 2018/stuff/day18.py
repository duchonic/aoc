#!/usr/bin/env python
# coding: utf-8

# ```
# An open acre will become filled with trees if three or more adjacent acres contained trees.
# Otherwise, nothing happens.
#
# An acre filled with trees will become a lumberyard if three or more adjacent acres were lumberyards.
# Otherwise, nothing happens.
#
# An acre containing a lumberyard will remain a lumberyard if it was adjacent to at least
# one other lumberyard and at least one acre containing trees. Otherwise, it becomes open.
# ```

# In[1]:


import matplotlib.pyplot as plt

data = open('data/day18.data','r').read().split('\n')


# In[2]:


GROUND = '.'
TREE  = '|'
LUMBERYARD = '#'

print('ground: ', GROUND)
print('trees:  ', TREE)
print('lumbery:', LUMBERYARD)


# In[3]:


TREE_FILTER =  [ [' ', TREE, ' ' ] , [TREE,' ',TREE] , [' ',TREE,' '] ]
LUMBER_FILTER = [ [' ', LUMBERYARD, ' '] , [LUMBERYARD,' ',LUMBERYARD] , [' ', LUMBERYARD, ' ']]


# In[4]:


print('if ground and three trees around:', GROUND, '->', TREE)
for line in TREE_FILTER:
    print(line)


# In[5]:


print('if tree and three lubers around:', TREE, '-> ', LUMBERYARD)
for line in LUMBER_FILTER:
    print(line)


# In[6]:


print('a lumberyard remains a lumberyard if there is at least one lumberyard and at least one tree adjacent', LUMBERYARD, '->', GROUND)


# In[7]:


print(len(data))
for line in data:
    print(line, len(line))


# In[8]:


def checkAdjacent(data, sort):
    ret = []
    ret.clear()
    for y in range(52):
        ret.append([])
    for y in range(52):
        ret[y] = []
        for x in range(52):
            sortFound = 0
            try:
                if data[y-1][x] == sort:
                    sortFound += 1
                if data[y+1][x] == sort:
                    sortFound += 1
                if data[y][x-1] == sort:
                    sortFound += 1
                if data[y][x+1] == sort:
                    sortFound += 1
                if data[y-1][x-1] == sort:
                    sortFound += 1
                if data[y+1][x+1] == sort:
                    sortFound += 1
                if data[y+1][x-1] == sort:
                    sortFound += 1
                if data[y-1][x+1] == sort:
                    sortFound += 1
            except:
                pass
            if sortFound >= 3:
                ret[y].append(sort)
            else:
                ret[y].append('.')
    return ret


# In[9]:


def checkLumberYard(data):
    ret = []
    ret.clear()
    for y in range(52):
        ret.append([])

    for y in range(52):
        ret[y] = []
        for x in range(52):
            treesfound = 0
            lumberfound = 0
            try:
                if data[y-1][x] == TREE:
                    treesfound += 1
                if data[y+1][x] == TREE:
                    treesfound += 1
                if data[y][x-1] == TREE:
                    treesfound += 1
                if data[y][x+1] == TREE:
                    treesfound += 1
                if data[y-1][x-1] == TREE:
                    treesfound += 1
                if data[y+1][x+1] == TREE:
                    treesfound += 1
                if data[y+1][x-1] == TREE:
                    treesfound += 1
                if data[y-1][x+1] == TREE:
                    treesfound += 1

                if data[y-1][x] == LUMBERYARD:
                    lumberfound += 1
                if data[y+1][x] == LUMBERYARD:
                    lumberfound += 1
                if data[y][x-1] == LUMBERYARD:
                    lumberfound += 1
                if data[y][x+1] == LUMBERYARD:
                    lumberfound += 1
                if data[y-1][x-1] == LUMBERYARD:
                    lumberfound += 1
                if data[y+1][x+1] == LUMBERYARD:
                    lumberfound += 1
                if data[y+1][x-1] == LUMBERYARD:
                    lumberfound += 1
                if data[y-1][x+1] == LUMBERYARD:
                    lumberfound += 1
            except:
                pass
            if treesfound >= 1 and lumberfound >= 1:
                ret[y].append('#')
            else:
                ret[y].append('.')
    return ret


# In[10]:


def replace(data, sort):
    new_list = data.copy()
    for y in range(52):
        for x in range(52):
            try:
                if data[y][x] >= 3:
                    new_list[y][x] = sort
                else:
                    new_list[y][x] = '.'
            except:
                pass
    return new_list


# In[11]:


def printBoard(data):
    wooded = 0
    lumbered = 0
    for line in data:
        wooded += line.count(TREE)
        lumbered += line.count(LUMBERYARD)
        print("".join(str(x) for x in line) )


# In[12]:


def calcResource(data):
    wooded = 0
    lumbered = 0
    for line in data:
        wooded += line.count(TREE)
        lumbered += line.count(LUMBERYARD)
        #print("".join(str(x) for x in line) )
    return wooded * lumbered


# In[13]:

plotDataX = list()
plotDataY = list()

for i in range(10):
    trees = checkAdjacent(data, TREE)
    stayLumber = checkLumberYard(data)
    lumber = checkAdjacent(data, LUMBERYARD)

    total  = []
    #print('after',i,'minutes')
    for y in range(52):
        total.append([])
    for y in range(52):
        total[y] = []
        for x in range(52):
            if lumber[y][x] != GROUND and data[y][x] == TREE:
                total[y].append(LUMBERYARD)
                #data[y][x] = LUMBERYARD
            elif trees[y][x] != GROUND and data[y][x] == GROUND:
                total[y].append(TREE)
                #data[y][x] = TREE
            else:

                if data[y][x] == LUMBERYARD and stayLumber[y][x] != LUMBERYARD:
                    total[y].append(GROUND)
                else:
                    total[y].append(data[y][x])

    data = list(total)
    #printBoard(data)
    #print(calcResource(data))
    plotDataX.append(i)
    plotDataY.append(calcResource(data))

plt.plot(plotDataX, plotDataY)

# In[ ]:
