import json

with open('day12.data') as readfile:
    data = json.load(readfile)


def checkType(data):
    if type(data) == list:
        print('list', data)
    elif type(data) == dict:
        print('dict', data)
    elif type(data) == str:
        print('string', data)
    else:
        print('unknown', type(data))


for key, value in data.items():

    if type(value) == list:
        print(key,  type(value), value)
    if type(value) == dict:
        print(key,  type(value), value)
        for key, value in value.items():
            print(key, value)
'''
--- Part Two ---

Uh oh - the Accounting-Elves have realized that they double-counted everything
red.

Ignore any object (and all of its children) which has any property with the
value "red".
Do this only for objects ({...}), not arrays ([...]).

[1,2,3] still has a sum of 6.
[1,{"c":"red","b":2},3] now has a sum of 4, because the middle object is
ignored.

{"d":"red","e":[1,2,3,4],"f":5} now has a sum of 0, because the entire
structure is ignored.
[1,"red",5] has a sum of 6, because "red" in an array has no effect.
'''
