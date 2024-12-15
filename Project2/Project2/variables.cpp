#include "variables.h"
using namespace std;

void home_appliance::setName(string nam)
{
	property.name = nam;
}

void home_appliance::setMaxVolt(double max_volt)
{
	property.max_cap_volt = max_volt;

}

void home_appliance::setMaxCurrent(double max_current)
{
	property.max_cap_current = max_current;
}

void home_appliance::setStatus(bool stat)
{
	property.status = stat;
}

properties home_appliance::getProperty()
{
	return property;
}

string home_appliance::getStatus() {
	return (property.status ? "ON" : "OFF");
}