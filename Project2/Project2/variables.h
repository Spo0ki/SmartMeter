#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>




struct signal {     // structure for any waveform 
	double time;
	double voltage;
	double current;

};

struct rms   //extern double periodT;
{
	double vrms;
	double irms;
};

struct properties { // a structure that maybe will be used only once for the home appliance class  
	std::string name;
	double max_cap_volt;
	double max_cap_current;
	bool status;
};

class home_appliance
{
private:

	properties property;

public:

	//Setters:
	void setName(std::string nam);
	void setMaxVolt(double max_volt);
	void setMaxCurrent(double max_current);
	void setStatus(bool stat);

	//Getters :
	properties getProperty();                    //getter for ( name or max cap volt or max cap current ) 
	// when you use it put after it .name or .max_cap_volt or .max_cap_current to get what u want 
	//example : refrigerator.getProperty().max_cap_volt 

	std::string getStatus();
};


