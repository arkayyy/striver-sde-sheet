long long int sumSquares(vector<int> A)
{
    long long int sum = 0;
    for (auto i : A)
    {
        sum += (i * i);
    }
    return sum;
}

long long int sumarr(vector<int> A)
{
    long long int sum = 0;
    for (auto i : A)
    {
        sum += (i);
    }
    return sum;
}

vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    // METHOD OF TWO EQUATIONS (causes integer overflow):-

    int n = A.size();
    // int sumn=((n*(n+1))>>1);
    //  int sumsq = ((n*(n+1)*((2*n)+1))/6);

    // long long int mMinusR = sumn - sumarr(A);
    // long long int mPlusRmMinusR = sumsq - sumSquares(A);
    // long long int mPlusR = (mPlusRmMinusR/mMinusR);
    // long long int m = (mPlusR+mMinusR)>>1;
    // long long int r = (mPlusR - mMinusR)>>1;
    // int mo = (int)m;
    // int ro = (int)r;

    // return {r,m};

    // XOR method:---

    int xor1 = A[0];
    int missing = 0, repeating = 0;

    for (int i = 1; i < n; i++)
    {
        xor1 = xor1 ^ A[i];
    }

    for (int i = 1; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }

    int last_set_bit = xor1 & ~(xor1 - 1);

    for (int i = 0; i < n; i++)
    {
        if (A[i] & last_set_bit)
            missing = missing ^ A[i];
        else
            repeating = repeating ^ A[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & last_set_bit)
            missing = missing ^ i;
        else
            repeating = repeating ^ i;
    }

    int rc = 0, mc = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == missing)
            mc++;
        if (A[i] == repeating)
            rc++;
    }
    if (rc)
        return {repeating, missing};
    if (mc)
        return {missing, repeating};
}
