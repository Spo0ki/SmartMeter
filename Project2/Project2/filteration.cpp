#include "filteration.h"

void filteration(std::vector <signal> waveform, std::vector <signal>& filtered_sig, double cutoff_freq)
{
    double Tsamp = waveform.at(1).time - waveform.at(0).time;
    filtered_sig.at(0) = waveform.at(0);
    double C = cutoff_freq * Tsamp, C2 = 1 / (1 + C);

    signal temp;

    for (int i = 0; i < (waveform.size() - 1); i++)
    {
        // filteration equation
        temp.time = waveform.at(i + 1).time;

        temp.voltage = (filtered_sig.at(i).voltage + waveform.at(i + 1).voltage * C) * C2;

        temp.current = (filtered_sig.at(i).current + waveform.at(i + 1).current * C) * C2;

        filtered_sig.at(i + 1) = temp;
    }
}