#include <iostream>

int n = 102;
int bit[102] = {1,2,3,4,5,6,7,8,9,10};

void update(int i, int delta) {
    for (; i <= n; i += i & -i)
        bit[i] += delta;
}


int query(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

int main() 
{
    std::cout << "Hello, World!" << std::endl;

    update(11, 5);
    std::cout << query(11) << std::endl;

    return 0;
}