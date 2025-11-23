bool f(int n);
int g(int n);

void rec(int n) {
    int res = n;
    while(not f(res)) {
        res = g(res);
    }
}