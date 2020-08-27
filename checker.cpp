#include <assert.h>

const int bpmLimits[] = { 70,150 };
const int respRateLimits[] = { 30,95 };
const int spo2Limit = 90;

bool bpmIsOk(float bpm)
{
    return (bpm > bpmLimits[0] && bpm < bpmLimits[1]);
}

bool spo2IsOk(float spo2)
{
    return spo2 > spo2Limit;
}

bool respRateIsOk(float respRate)
{
    return (respRate > respRateLimits[0] && respRate < respRateLimits[1]);
}

int main() {
    assert(bpmIsOk(60) == false);
    assert(bpmIsOk(90) == true);
    assert(bpmIsOk(160) == false);

    assert(spo2IsOk(100) == true);
    assert(spo2IsOk(80) == false);

    assert(respRateIsOk(20) == false);
    assert(respRateIsOk(60) == true);
    assert(respRateIsOk(160) == false);
}
