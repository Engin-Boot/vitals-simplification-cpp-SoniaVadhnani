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

bool vitalsAreOk(float bpm, float spo2, float respRate) {

  return (bpmIsOk(bpm) && spo2IsOk(spo2) && respRateIsOk(respRate));

}



int main() {

  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);

}
