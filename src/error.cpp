#include "../include/error.h"
using namespace std;

void showError(string err, string det)
{
    if (det != "")
        cerr << "ERROR: " << err << " (" << det << ")" << endl;
    else
        cerr << "ERROR: " << err << endl;
}

void showWarning(string err)
{
    cerr << "WARNING: " << err << endl;
}
