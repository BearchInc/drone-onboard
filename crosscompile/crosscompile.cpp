#include "crosscompile.h"

int main()
{
    cout << greetings("Diego") << endl;
    return 0;
}

string greetings(string name)
{
    return "Well hello " + name;
}
