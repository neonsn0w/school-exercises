def fibonacci(t):
    n = 0
    np = 1
    npp = 0
    i = 2
    if (t <= 1):
        print("numero non valido")
    else:
        print("0")
        print("1")
        while (i < t):
            n = np + npp
            npp = np
            np = n
            print(n)
            i += 1

fibonacci(5)
