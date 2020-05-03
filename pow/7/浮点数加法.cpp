#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int getdot(char* a) {
    int ret = 0;
    int lena = strlen(a);
    while (ret < lena && a[ret] != '.') ++ret;
    return ret;
}

void add_float(char* a, char* b, char* res) {
    int ta[260], tb[260], tc[260];
    int lena = strlen(a), lenb = strlen(b);
    int dota = getdot(a), dotb = getdot(b);
    memset(ta, 0, sizeof(ta));
    memset(tb, 0, sizeof(tb));
    // 0-128 is int part
    for (int i = 128, p = dota-1; p >= 0; --p)
        ta[i--] = a[p]-'0';
    for (int i = 128, p = dotb-1; p >= 0; --p)
        tb[i--] = b[p]-'0';
    // 129-256 is float part
    for (int i = 129, p = dota+1; p < lena; ++p)
        ta[i++] = a[p]-'0';
    for (int i = 129, p = dotb+1; p < lenb; ++p)
        tb[i++] = b[p]-'0';
    int carry = 0;
    for (int i = 256; i >= 0; --i) {
        tc[i] = (carry+ta[i]+tb[i])%10;
        carry = (carry+ta[i]+tb[i])/10;
    }
    int lft = 0, rgt = 256;
    // strip left 0
    while (tc[lft] == 0 && lft <= 128) ++lft;
    // strip right 0
    while (tc[rgt] == 0 && rgt >= 129) --rgt;
    int lenr = 0;
    // copy int part
    for (int i = lft; i <=128; ++i) 
        res[lenr++] = char(tc[i]+'0');
    res[lenr++] = '.';
    // copy float part
    for (int i = 129; i <= rgt; ++i)
        res[lenr++] = char(tc[i]+'0');
    res[lenr] = '\0';
}

int main(int argc, char** argv)
{
#ifndef ONLINE_JUDGE
	freopen(argv[1], "r", stdin);
	freopen(argv[2], "w", stdout);
#endif // ONLINE_JUDGE
    char num1[128], num2[128], res[128];
    cin >> num1;
    cin >> num2;
    add_float(num1, num2, res);
    cout << res << endl;
    return 0;
}