#pragma once
#include "variables.h"
class powercalculator {
public: 
	
	double CalcPowerAverage(const std::vector<signal>& waveform1); 
	double CalcPowerEnergy(const std::vector<signal>& waveform1);
};