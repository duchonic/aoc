# packet scanners
firewall = dict()

data = """0: 4
1: 2
2: 3
4: 4
6: 8
8: 5
10: 8
12: 6
14: 6
16: 8
18: 6
20: 6
22: 12
24: 12
26: 10
28: 8
30: 12
32: 8
34: 12
36: 9
38: 12
40: 8
42: 12
44: 17
46: 14
48: 12
50: 10
52: 20
54: 12
56: 14
58: 14
60: 14
62: 12
64: 14
66: 14
68: 14
70: 14
72: 12
74: 14
76: 14
80: 14
84: 18
88: 14""".split('\n')


for line in data:
    arr = line.replace(':', '').split()

    firewall.update({int(arr[0]):int(arr[1])})

#print(firewall)
def calculate_severity(delay, firewalls):
    '''
    Calculate how severe the alarm is if you start at the given tick.
    '''

    total_severity = 0

    for depth in firewalls:
        range = firewalls[depth]

        cycle_length = (range - 1) * 2
        position = (delay + depth) % cycle_length

        if position > range:
            position = 2 * range - position

        if position == 0:
            severity = depth * firewalls[depth]
            total_severity += severity
            return False


    return True

#tick = lib.param('tick')$
severity = False
delay = 0
while severity == False:
    delay += 1
    severity = calculate_severity(delay, firewall)

print(f'{delay} severity {severity}')
