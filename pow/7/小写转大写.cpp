#include <iostream>
#include <cstring>
using namespace std;

char *&funA(char **&p);
const char *funB(char b[], char **p);

int main() {
    char a[100], b[100];
    for(int i = 0; i < 3; ++i) {
        char **p;
        cin >> a;
        funA(p) = a;
        cout << funB(b, p);
    }
    return 0;
}

char *&funA(char **&p)
{
    p = new char *;
    return *p;
}

const char *funB(char b[], char **p)
{
    // Since no memory leaks are allowed, we must copy a to b, instead of
    // directly returning *p.
    char *bp = b;
    while (**p) {
        *bp = **p >= 'a' && **p <= 'z' ? **p - 'a' + 'A' : **p;
        ++*p;
        ++bp;
    }
    *bp++ = '\n';
    *bp = '\0';
    delete p;
    return b;
}
