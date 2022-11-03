// All the functions in C are global defaultly. Unless you use static key word.
// Any file can call it, after declared it.
int g_sum(int a, int b)
{
    return a+b;
}

// No other file can call it because it is a static function.
static int s_sum(int a, int b)
{
    return a+b;
}
















