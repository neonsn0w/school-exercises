x = 0
xp = 0

for x in range(10):
    print("Current number: " + str(x) + " Previous number: " + str(xp) + " Sum: " + str(x + xp))
    xp = x
    x += 1
