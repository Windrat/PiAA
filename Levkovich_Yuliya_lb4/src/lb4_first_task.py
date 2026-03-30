def prefix_func(P):
    pref = [0] * len(P)
    for i in range(1, len(P)):
        k = pref[i - 1]
        while k > 0 and P[k] != P[i]:
            k = pref[k - 1]
        if P[k] == P[i]:
            k += 1
        pref[i] = k
    return pref

def KMP(T, P):
    k = 0
    A = []
    pref = prefix_func(P)
    for i in range(len(T)):
        while k > 0 and T[i] != P[k]:
            k = pref[k - 1]
        if T[i] == P[k]:
            k = k + 1
        if k == len(P):
            A.append(i - len(P) + 1)
            k = pref[k - 1]
    return A

P = input()
T = input()
res = KMP(T, P)
if res != []:
    res = list(map(str, res))
    print(",".join(res))
else:
    print(-1)