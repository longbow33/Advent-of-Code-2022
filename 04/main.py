with open("input.txt","r") as f:
    lines = f.read().split("\n")

part1 = 0
part2 = 0

for line in lines:
    if line == "":
        continue
    intervals = []
    a,b = line.split(",")
    [intervals.append(int(x)) for x in a.split("-")]
    [intervals.append(int(x)) for x in b.split("-")]
    if intervals[0]<=intervals[2] and intervals[1]>= intervals[3]:
        part1+=1
    elif intervals[0]>= intervals[2] and intervals[1] <= intervals[3]:
        part1+=1

    if intervals[1]>=intervals[2] and intervals[3] >= intervals[0]:
        part2+=1

print(part1,part2)
