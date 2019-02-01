# coding: utf-8
def calcRibbon(data):
    ribbon = list()
    ribbon.append(int(data.split('x')[0]))
    ribbon.append(int(data.split('x')[1]))
    ribbon.append(int(data.split('x')[2]))
    return 2*(sum(ribbon)-max(ribbon)) + reduce( (lambda x, y: x * y), ribbon)
def calcPaper(data):
    surface = list()
    l = int(data.split('x')[0])
    w = int(data.split('x')[1])
    h = int(data.split('x')[2])
    surface.append(l*w)
    surface.append(w*h)
    surface.append(h*l)
 
    return 2*sum(surface)+min(surface)
from functools import reduce
total = 0
for line in data:
    total += calcRibbon(line)
    
total = 0
for line in data:
    total += calcPaper(line)
    
