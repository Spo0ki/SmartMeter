#include "powerc.h"
using namespace std;


double powercalculator::CalcPowerAverage(const vector<signal>& waveform1)
{
    double SumPower = 0;
    int size = waveform1.size();
    for (int i = 0; i < size; i++)
    {
        SumPower += waveform1.at(i).current * waveform1.at(i).voltage;
    }
    return  SumPower / size;
}

