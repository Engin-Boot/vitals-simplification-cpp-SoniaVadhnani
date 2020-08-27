#include <assert.h>

bool vitalIsOk(float value, int lower, int upper)
{
    return (value > lower && value < upper);
}


int main() {

    assert(vitalIsOk(4,3,7) == true);
    assert(vitalIsOk(70, 10, 20) == false);
    assert(vitalIsOk(5, 10, 20) == false);
    
    return 0;
}

