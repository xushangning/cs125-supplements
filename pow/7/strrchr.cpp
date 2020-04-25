const char* strrchr(const char* str, int ch) {
    const char *result = nullptr;
    for (; *str; ++str)
        if (*str == char(ch))
            result = str;
    return result;
}
