# coding: utf-8
def checkPassPhrase(data):
    passphrasecounter = 0
    for line in data.split('\n'):
        passphrase = list()
        found = 1
        for item in line.split():
            
            test = list()
            for letter in item:
                test.append(letter)
            test.sort()
            word = ""
            for item in test:
                word += item
            
            if passphrase.count(word) == 0:
                passphrase.append(word)
            else:
                found = 0
                break
        if found:
            passphrasecounter += 1
            print(passphrase)
    return passphrasecounter


            
            
