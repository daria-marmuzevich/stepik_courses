'''
Напишите программу, которая принимает на стандартный вход список игр футбольных команд с результатом
матча и выводит на стандартный вывод сводную таблицу результатов всех матчей.
За победу команде начисляется 3 очка, за поражение — 0, за ничью — 1.
'''

n = int(input())
football = {}
s = []
for i in range(n):
    s += [input().split(';')]
    if s[i][0] not in football:
        football.setdefault(s[i][0], []).append(1)
        if int(s[i][1]) > int(s[i][3]):
            football.setdefault(s[i][0], []).append(1)
            football.setdefault(s[i][0], []).append(0)
            football.setdefault(s[i][0], []).append(0)
            football.setdefault(s[i][0], []).append(3)
        elif s[i][1] == s[i][3]:
            football.setdefault(s[i][0], []).append(0)
            football.setdefault(s[i][0], []).append(1)
            football.setdefault(s[i][0], []).append(0)
            football.setdefault(s[i][0], []).append(1)
        else:
            football.setdefault(s[i][0], []).append(0)
            football.setdefault(s[i][0], []).append(0)
            football.setdefault(s[i][0], []).append(1)
            football.setdefault(s[i][0], []).append(0)
    elif s[i][0] in football:
        football[s[i][0]][0] += 1
        if int(s[i][1]) > int(s[i][3]):
            football[s[i][0]][1] += 1
            football[s[i][0]][4] += 3
        elif s[i][1] == s[i][3]:
            football[s[i][0]][2] += 1
            football[s[i][0]][4] += 1
        else:
            football[s[i][0]][3] += 1
    if s[i][2] not in football:
        football.setdefault(s[i][2], []).append(1)
        if int(s[i][3]) > int(s[i][1]):
            football.setdefault(s[i][2], []).append(1)
            football.setdefault(s[i][2], []).append(0)
            football.setdefault(s[i][2], []).append(0)
            football.setdefault(s[i][2], []).append(3)
        elif s[i][1] == s[i][3]:
            football.setdefault(s[i][2], []).append(0)
            football.setdefault(s[i][2], []).append(1)
            football.setdefault(s[i][2], []).append(0)
            football.setdefault(s[i][2], []).append(1)
        else:
            football.setdefault(s[i][2], []).append(0)
            football.setdefault(s[i][2], []).append(0)
            football.setdefault(s[i][2], []).append(1)
            football.setdefault(s[i][2], []).append(0)
    elif s[i][2] in football:
        football[s[i][2]][0] += 1
        if int(s[i][3]) > int(s[i][1]):
            football[s[i][2]][1] += 1
            football[s[i][2]][4] += 3
        elif s[i][1] == s[i][3]:
            football[s[i][2]][2] += 1
            football[s[i][2]][4] += 1
        else:
            football[s[i][2]][3] += 1
for i in football:
    print(i+ ':', end=' ')
    for j in range(5):
        print(football[i][j], end=' ')
    print()

