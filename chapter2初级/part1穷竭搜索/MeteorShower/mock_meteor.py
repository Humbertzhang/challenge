import random
with open("data", "w") as f:
    m = random.randint(1,100)
    f.write(str(m) + "\n")
    for j in range(m-1):
        xp = random.randint(1, 21)
        yp = random.randint(1, 21)
        time = random.randint(0, 5)
        f.write(str(xp) + " " + str(yp) + " " + str(time) + "\n")
    zerot = random.randint(2, 4)
    f.write("0 0 " + str(zerot) + "\n")
