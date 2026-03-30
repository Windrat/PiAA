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

def KMP(A, B):
    if len(A) != len(B):
        return -1
    T = B + B
    P = A
    k = 0
    pref = prefix_func(P)
    for i in range(len(T)):
        while k > 0 and T[i] != P[k]:
            k = pref[k - 1]
        if T[i] == P[k]:
            k = k + 1
        if k == len(P):
            return i - len(P) + 1
    return -1

P = input()
T = input()
print(KMP(T, P))