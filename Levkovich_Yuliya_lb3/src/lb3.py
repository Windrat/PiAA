def vagner_fisher_alg(str1, str2, replace_cost, insert_cost, delete_cost, rep_sym, rep_cost_new, del_sym, del_cost_new):
    N = len(str1)
    M = len(str2)
    table = [[0] * (M + 1) for _ in range(N + 1)]

    def get_replace_cost(char1, char2):
        if char1 == char2:
            return 0
        elif char2 == rep_sym:
            return rep_cost_new
        return replace_cost

    def get_del_cost(char1):
        if char1 == del_sym:
            return del_cost_new
        return delete_cost

    for i in range(1, N + 1):
        table[i][0] = table[i - 1][0] + get_del_cost(str1[i - 1])
    for j in range(1, M + 1):
        table[0][j] = table[0][j - 1] + insert_cost
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            table[i][j] = min(table[i - 1][j] + get_del_cost(str1[i - 1]), table[i][j - 1] + insert_cost, table[i - 1][j - 1] + get_replace_cost(str1[i - 1], str2[j - 1]))
    for q in table:
        print(q)
    return table[N][M]

rep_cost, ins_cost, del_cost = list(map(int, input().split(' ')))
str1 = input()
str2 = input()
rep_sym,  del_sym = list(input().split(' '))
rep_cost_new, del_cost_new = list(map(int, input().split(' ')))
print(vagner_fisher_alg(str1, str2, rep_cost, ins_cost, del_cost, rep_sym, rep_cost_new, del_sym, del_cost_new))
