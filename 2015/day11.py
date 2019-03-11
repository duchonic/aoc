def nextPassword(currentPassword):

    def incPassword(password):
        assert len(password) != 0
        assert password[0] != 'z'

        currentPasswordArray = [ord(c) for c in password]
        currentPasswordArray[-1] += 1

        for index in range(1, len(currentPasswordArray)+1):
            if currentPasswordArray[-index] > ord('z'):
                currentPasswordArray[-index] = ord('a')
                currentPasswordArray[-index-1] += 1
        return ''.join(chr(i) for i in currentPasswordArray)

    def checkPassword(password):
        '''
        a e i o u ist not allowed
        at least one abc, xyz
        at least two not overlapping pairs like aa, bb or zz
        '''
        assert len(password) != 0

        if 'o' in password:
            return False
        if 'i' in password:
            return False
        if 'l' in password:
            return False

        passwordArray = [ord(c) for c in password]
        #print('check:', password, passwordArray)
        for index in range(len(passwordArray)):
            try:
                if passwordArray[index] == passwordArray[index+1]-1:
                    if passwordArray[index] == passwordArray[index+2]-2:
                        # check if aa, bb or zz
                        doppelLetter = 0
                        lastFoundDoppelLetter = 0
                        for position in range(len(passwordArray)):
                            try:
                                if passwordArray[position] == passwordArray[position+1]:
                                    doppelLetter += 1

                                if passwordArray[position] == passwordArray[position+1] == passwordArray[position+2]:
                                    doppelLetter -= 1
                            except IndexError:
                                pass

                        if doppelLetter >= 2:
                            return True
                        else:
                            return False

            except IndexError:
                pass
        return False

    nextPassword = currentPassword

    while checkPassword(nextPassword) == False:
        nextPassword = incPassword(nextPassword)
        print(nextPassword)
    print(nextPassword)
    return nextPassword


assert nextPassword('abcdefgh') == 'abcdffaa'
assert nextPassword('ghijklmn') == 'ghjaabcc'

print('result part1:', nextPassword('hxbxwxba'))
