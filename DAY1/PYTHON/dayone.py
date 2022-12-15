import functools
import itertools

f = open("DAY1/input.txt", "r")
Lines = f.readlines()
elves = []
count = 0

for line in Lines:
    if line.strip()=="":
        elves.append(count)
        count=0
    else:
        count=count+int(line.strip())
print(max(elves))

elvescp = elves
topthree = []

count = 0
for elf in elvescp:
    if elf == max(elvescp):
        elvescp.remove(elf)
        topthree.append(elf)
        count = count+1
    if count >= 3:
        break

print(topthree)
print(sum(topthree))



