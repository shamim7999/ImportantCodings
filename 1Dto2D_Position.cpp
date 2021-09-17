//// given (r x c matrix) and position in array.. find appropriate index ( X x Y)..

int ff(int x, int y)
{
    x = (x/y)+(x%y!=0);
    return x;
}

pair < int, int > func(int pos)
{
    int Row = ff(pos, c);
    int st = (Row-1)*c+1;
    return {Row, pos-st+1};
}
