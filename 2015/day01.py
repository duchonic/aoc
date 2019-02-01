# coding: utf-8
data.count('(')-data.count(')')
basement = 0
for nr, char in enumerate(data):
    if char == '(':
        basement += 1
    elif char == ')':
        basement -= 1
    
basement = 0
for nr, char in enumerate(data):
    if char == '(':
        basement += 1
    elif char == ')':
        basement -= 1
    if basement == -1:
        print(nr)
        break
    
