
#include"energy.h"
using namespace std;
double energycalc::Ecalculator(const vector<signal>&waveform1)
{
    double energy = 0;
    int size = waveform1.size();
    for (int i = 0; i < size; i++)
    {
        energy += waveform1.at(i).current * waveform1.at(i).voltage * waveform1.at(i).time;
    }
    return  energy;
}

