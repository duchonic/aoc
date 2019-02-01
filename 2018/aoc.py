import urllib
import json

def getData(day):
    return open('data/day'+day+'.data', 'r').read().split('\n')

