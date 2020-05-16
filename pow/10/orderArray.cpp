class orderArray
{
    int capacity, size = 0;
    int *a;

    void expand();

public:
    /**
     * @param n: size of orderArray
     */
    orderArray(int n) : capacity(n), a(new int [n]) {}

    ~orderArray() { delete []a; }

    /**
     * Add a number to the array.
     */
    void add(int x);

    /**
     * Return the ith smallest element.
     */
    int findnum(int i) { return a[i]; }

    /**
     * Print all elements in ascending order.
     */
    void show();
};

void orderArray::expand()
{
    int *temp = new int [capacity *= 2];
    for (int i = 0; i < size; ++i)
        temp[i] = a[i];
    delete []a;
    a = temp;
}

void orderArray::add(int x)
{
    if (size == capacity)
        expand();

    int i;
    for (i = size; i > 0 && a[i - 1] > x; --i)
        a[i] = a[i - 1];
    a[i] = x;
    ++size;
}

void orderArray::show()
{
    for (int i = 0; i < size - 1; ++i)
        cout << a[i] << ' ';
    cout << a[size - 1] << '\n';
}
