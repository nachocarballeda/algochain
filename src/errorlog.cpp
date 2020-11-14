#include "../include/errorlog.h"

using namespace std;

void showError(string err)
{
    cerr << "ERROR: " << err << endl;
}
void showError(string err, string detail)
{
    cerr << "ERROR: " << err << " (" << detail << ")" << endl;
}

void showWarning(string err)
{
    cerr << "WARNING: " << err << endl;
}
