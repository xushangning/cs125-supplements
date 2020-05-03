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
