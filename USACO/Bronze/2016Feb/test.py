import math
f = open("balancing.in",'r')

info = f.readline().split()
numCows = int(info[0])
maxPos = int(info[1])
horzList = []
vertList = []
horzCoords = []
vertCoords = []

def isPastLine(val, line):
    if val > line:
        return True
    else:
        return False

def findBestLine(list1):
    best = 1000000
    line = 0
    priev = 0
    after = sum(list1)
    for i in range(len(list1)):
        priev += list1[i]
        after -= list1[i]
        if abs(priev - after) < best:
            best = abs(priev - after)
            line = i*2+2
    return line

for i in range(math.ceil(maxPos/2)):
    horzList.append(0)
    vertList.append(0)

for i in range(numCows):
    info2 = f.readline().split()
    x = int(info2[0])
    y = int(info2[1])
    horzList[math.ceil(x/2) - 1] += 1
    vertList[math.ceil(y/2) - 1] += 1
    horzCoords.append(x)
    vertCoords.append(y)

line1 = findBestLine(horzList)
line2 = findBestLine(vertList)
quad1 = 0
quad2 = 0
quad3 = 0
quad4 = 0

for i in range(numCows):
    if isPastLine(horzCoords[i],line1) == True:
        if isPastLine(vertCoords[i],line2) == True:
            #Quadrant 2
            quad2 += 1
        else:
            #Quadrant 4
            quad4 += 1
    else:
        if isPastLine(vertCoords[i],line2) == True:
            #Quadrant 1
            quad1 += 1
        else:
            #Quadrant 3
            quad3 += 1

with open('balancing.out', 'w') as fout:
    fout.write(str(max(quad1,quad2,quad3,quad4)))