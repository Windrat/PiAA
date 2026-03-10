#include <iostream>
#include <vector>

struct Square{
    int x, y, square_size;
};

int new_n;
int best_count;
std::vector<std::vector<int>> table;
std::vector<Square> current_comb;
std::vector<Square> best_comb;

int get_min(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

bool find_new_place(int &x, int &y){
    for (int i = 0; i < new_n; i++){
        for (int j = 0; j < new_n; j++){
            if (table[i][j] == 0){
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}

bool its_empty(int x, int y, int square_size){
    if (x + square_size > new_n || y + square_size > new_n){
        return false;
    }
    for (int i = x; i < x + square_size; i++){
        for (int j = y; j < y + square_size; j++){
            if (table[i][j] != 0) return false;
        }
    }
    return true;
}

void place(int x, int y, int square_size, int val = 1){
    for (int i = x; i < x + square_size; i++){
        for (int j = y; j < y + square_size; j++){
            table[i][j] = val;
        }
    }
}

void backtrack(int count){
    if (count >= best_count){
        return;
    }

    int x, y;
    if (!find_new_place(x, y)){
        best_count = count;
        best_comb = current_comb;
        return;
    }

    int max_square_size = get_min(new_n - x, new_n - y);
    for (int square_size = max_square_size; square_size > 0; square_size--){
        if (its_empty(x, y, square_size)){
            place(x, y, square_size);
            current_comb.push_back({x + 1, y + 1, square_size});
            backtrack(count + 1);

            current_comb.pop_back();
            place(x, y, square_size, 0);
        }
    }
}

int main(){
    int N;
    std::cin >> N;

    if (N % 2 == 0) {
        int h = N / 2;
        std::cout << 4 << std::endl;
        std::cout << "1 1 " << h << std::endl;
        std::cout << "1 " << h + 1 << " " << h << std::endl;
        std::cout << h + 1 << " 1 " << h << std::endl;
        std::cout << h + 1 << " " << h + 1 << " " << h << std::endl;
        return 0;
    }

    new_n = N;
    int parametr = 1;
    for (int i = 2; i <= 10; i++){
        if (N % i == 0) {
            new_n = i;
            parametr = N / new_n;
            break;
        }
    }          

    table.assign(new_n, std::vector<int>(new_n, 0));
    best_count = new_n + 4;

    int square_size = (new_n + 1) / 2;
    place(0, 0, square_size);
    current_comb.push_back({1, 1, square_size});
    place(0, square_size, square_size - 1);
    current_comb.push_back({1, square_size + 1, square_size - 1});
    place(square_size, 0, square_size - 1);
    current_comb.push_back({square_size + 1, 1, square_size - 1});

    backtrack(3);

    std::cout << best_count << std::endl;
    for (int i = 0; i < best_comb.size(); ++i){
        std::cout << (best_comb[i].x - 1) * parametr + 1 << " " << (best_comb[i].y - 1) * parametr + 1 << " " << best_comb[i].square_size * parametr << std::endl;
    }
    return 0;
}