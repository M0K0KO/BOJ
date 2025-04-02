#include <bits/stdc++.h>

const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

using namespace std;

void insert(int addr, int num) {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

int main() {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    string str;
    cin >> str;
    int it = 0;
    for (auto c : str) {
        insert(it, c);
        it++;
    }
    int M;
    cin >> M;
    while (M--) {
        char op;
        cin >> op;

        if (op == 'P') {
            char add;
            cin >> add;
            insert(it, add);
            it = nxt[it];
        }
        else if (op == 'L') {
            if (pre[it] != -1) it = pre[it];
        }
        else if (op == 'D') {
            if (nxt[it] != -1) it = nxt[it];
        }
        else {
            if (it != 0) {
                erase(it);
                it = pre[it];
            }
        }
    }
    traverse();
}