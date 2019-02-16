# aoc 2015 day07.py


class Assembly:
    def __init__(self):
        print('init')
        self.regs = dict()
        self.cmds = dict()

    def reg(self, regs, data=None):
        self.regs.update({regs: int(data)})

    def cmd(self, regs, command):
        self.cmds.update({regs: command})

    def process(self):
        keyRun = list()
        for key, value in self.cmds.items():
            comandArray = value.split()

            if comandArray[1] == '->':
                try:
                    if comandArray[0].isdigit():
                        self.regs.update({key: int(comandArray[0])})
                        print(value, key)
                        keyRun.append(key)
                    else:
                        self.regs.update({key: self.regs[comandArray[0]]})
                        print(value, key)
                        keyRun.append(key)
                except KeyError:
                    pass
            elif 'AND' in value:
                if comandArray[2].isdigit():
                    assert 0
                if comandArray[0].isdigit():
                    try:
                        self.regs.update({key: int(comandArray[0]) &
                                          self.regs[comandArray[2]]})
                        print('********', value, key)
                        self.cmds[key] = '0'
                        keyRun.append(key)
                    except TypeError:
                        pass
                    except KeyError:
                        pass
                else:
                    try:
                        self.regs.update({key: self.regs[comandArray[0]] &
                                          self.regs[comandArray[2]]})
                        print(value, key)
                        self.cmds[key] = '0'
                        keyRun.append(key)
                    except KeyError:
                        pass
            elif 'OR' in value:
                if comandArray[0].isdigit() or comandArray[2].isdigit():
                    assert 0
                try:
                    self.regs.update({key: self.regs[comandArray[0]] |
                                      self.regs[comandArray[2]]})
                    print(value, key)
                    self.cmds[key] = '0'
                    keyRun.append(key)
                except KeyError:
                    pass
            elif 'LSHIFT' in value:
                try:
                    self.regs.update({key: self.regs[comandArray[0]] <<
                                      int(comandArray[2])})
                    print(value, key)
                    self.cmds[key] = '0'
                    keyRun.append(key)
                except KeyError:
                    pass
            elif 'RSHIFT' in value:
                try:
                    self.regs.update({key: self.regs[comandArray[0]] >>
                                      int(comandArray[2])})
                    print(value, key)
                    self.cmds[key] = '0'
                    keyRun.append(key)
                except KeyError:
                    pass
            elif 'NOT' in value:
                try:
                    self.regs.update({key: ~self.regs[comandArray[1]]})
                    print(value, key)
                    self.cmds[key] = '0'
                    keyRun.append(key)
                except KeyError:
                    pass
            else:
                print(key, value)
                assert 0

        for delKey in keyRun:
            self.cmds.pop(delKey)

    def __repr__(self):
        return str(self.regs['a'] ) + "\n" + str(self.cmds)


a = Assembly()

with open('day07.data') as file:
    data = file.read()
    for nr, line in enumerate(data.split('\n')):
        try:
            comandArray = line.split()

            if len(comandArray) == 3:
                a.cmd(comandArray[-1], "{} {}".
                      format(comandArray[0], comandArray[1]))
            elif len(comandArray) == 4:
                a.cmd(comandArray[-1], "{} {}".
                      format(comandArray[0], comandArray[1]))
            elif len(comandArray) == 5:
                a.cmd(comandArray[-1], "{} {} {}".
                      format(comandArray[0], comandArray[1], comandArray[2]))

        except ValueError:
            print(nr, line)
            pass

for _ in range(200):
    a.process()
    print(len(a.cmds))
print(a)
