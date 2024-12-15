#include "Read_CSV.h"
using namespace std;

//This function reads the csv file to start operating

void read_csv(string path, vector <signal>& waveform)
{
    string time, magnitude, magnitude1;
    ifstream myfile;
    myfile.open(path);
    signal temp;
    bool i = true;
    int j = 0;
    while (i)
    {
        getline(myfile, time, ',');
        if (time == "\0")
            i = false;

        else
        {
            getline(myfile, magnitude, ',');
            getline(myfile, magnitude1, '\n');

            temp.time = stod(time); temp.voltage = stod(magnitude); temp.current = stod(magnitude1);

            waveform.push_back(temp);
        }
    }


}