#include <iostream>
#include "NiceDFSM.h"
#include "sandboxdfsm.h"

using namespace std;

int main()
{
    int (*f)(int) = [](int x){return 2*x;};
    cout << f(2) << endl;


	return 0;
}
