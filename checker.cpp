#include <assert.h>

const int bpmLimits[] = { 70,150 };
const int respRateLimits[] = { 30,95 };
const int spo2Limit[] = { 90,101 };

bool vitalIsOk(float value, int lower, int upper)
{
    return (value > lower && value < upper);
}


bool bpmIsOk(float bpm)
{
    return (bpm > bpmLimits[0] && bpm < bpmLimits[1]);
}

bool spo2IsOk(float spo2)
{
    return spo2 > spo2Limit[0] && spo2 < spo2Limit[1];
}

bool respRateIsOk(float respRate)
{
    return (respRate > respRateLimits[0] && respRate < respRateLimits[1]);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {

    return (vitalIsOk(bpm, bpmLimits[0], bpmLimits[1]) && vitalIsOk(spo2, spo2Limit[0], spo2Limit[1]) && vitalIsOk(respRate, respRateLimits[0], respRateLimits[1]));

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

    assert(vitalIsOk(4, 3, 7) == true);
    assert(vitalIsOk(70, 10, 20) == false);
    assert(vitalIsOk(5, 10, 20) == false);

    return 0;
}
