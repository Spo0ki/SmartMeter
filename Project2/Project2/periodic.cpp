#include "periodic.h"
using namespace std;

double Periodictime::getperiodictime(const vector<signal>& waveform1)
{
    double primo = waveform1.at(0).current;  
     int i;
    for (i = 1; i < waveform1.size(); i++) {
        if (waveform1.at(i).current == primo) {
            break;
        }
    }
    return i;
}


