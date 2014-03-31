void main()
{
    initialize();
    print("\nHello World!!!\n");

    int a = 0, b = 1;
    int i = 0;
    for(i = 0; i < 20; i++)
    {
        print("%d ", b);
        int tmp = b;
        b += a;
        a = tmp;
    }
    return;
}
