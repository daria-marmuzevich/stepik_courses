'''
ƒл€ каждого запроса выведите в отдельной строке слово "Yes", если класс 1 €вл€етс€ предком класса 2,
и "No", если не €вл€етс€.
'''

n = int(input())
child_parent = {}
glob = 0
def check(parent, predok):
    child = parent
    global glob
    for value in child_parent[child]:
       # print(child, value, predok)
        if value == predok:
            glob = 100
        elif value == 'obj':
            break
        else:
            check(value, predok)


for i in range(n):
    s = input().split()
    child_parent[s[0]] = set()
    if len(s)>1:
        for j in range(2, len(s)):
            child_parent[s[0]].add(s[j])
            if s[j] not in child_parent:
                child_parent[s[j]] = set()
                child_parent[s[j]].add('obj')
    else:
        child_parent[s[0]].add('obj')

q = int(input())
for i in range(q):
    s = input().split()
    predok = s[0]
    child = s[1]
    m = 0
    glob = 0
    if s[0] == s[1]:
        print('Yes')
    else:
        for value in child_parent[s[1]]:
            #print(value, temp)

            size = len(child_parent[s[1]])
            m += 1

            if value == predok:
                glob = 100
                break

            elif value == 'obj':
                break
            else:
                temp = check(value, predok)


        if glob == 100:
            print('Yes')
        else:
            print('No')
