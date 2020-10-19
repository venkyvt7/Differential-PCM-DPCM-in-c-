#include <bits/stdc++.h>

using namespace std;

// defining weights  by using double data type;
double weights[] = {1, -0.5, 0.5, 0.3, 0.21, -1, -0.32, -0.25, 0.21, 0.111, 0.1, -0.01, 0.64, 0.59, -0.32};
int size = 15;

//function for quantizing;
double quantizer(double dk)
{

    dk = dk / 0.5;
    dk = floor(dk);
    double dqk = (2 * dk + 1) / 2;
    dqk = dqk * 0.5;
    return dqk;
}

int main()
{
    int t;

    t = 1;
    while (t--)
    {

        double mqk = 0;

        //defining modulated,demodulated,time,amplitude signal;
        vector<double> mod_v, demod_v, time, amplitude;

        double i1 = 0;

        // time interval of 0.05 start from 0 and end to 10;
        while (i1 < 10)
        {
            time.push_back(i1);

            i1 = i1 + 0.05;
        }

        int i;

        // for every time interval sin wave discrte signal;
        for (i = 0; i < time.size(); i++)
        {
            amplitude.push_back(2.5 * (sin(2 * 3.147 * time[i])) + 2.5);
        }

        deque<double> prev;
        for (i = 0; i < size; i++)
            prev.push_back(0);

        //modulated signal
        for (i = 0; i < amplitude.size(); i++)
        {
            if (1)
            {

                vector<double> temp;
                deque<double> prev1 = prev;
                for (int i = 0; i < size; i++)
                {

                    double prev11 = prev1.front();
                    prev1.pop_front();

                    temp.push_back(prev11 * weights[i]);
                }
                double mqck = 0;

                for (int i = 0; i < temp.size(); i++)
                    mqck = mqck + temp[i];

                prev.pop_back();

                prev.push_front(mqk);

                double dk = amplitude[i] - mqck;
                double dqk = quantizer(dk);
                mod_v.push_back(dqk);

                mqk = dqk + mqck;
            }
        }

        prev.clear();

        for (i = 0; i < size; i++)
            prev.push_back(0);

        mqk = 0;

        //demoulated signal
        for (i = 0; i < mod_v.size(); i++)
        {

            if (1)
            {

                vector<double> temp;
                deque<double> prev1 = prev;
                for (int i = 0; i < size; i++)
                {

                    double prev11 = prev1.front();
                    prev1.pop_front();

                    temp.push_back(prev11 * weights[i]);
                }
                double mqck = 0;

                for (int i = 0; i < temp.size(); i++)
                    mqck = mqck + temp[i];

                prev.pop_back();

                prev.push_front(mqk);

                mqk = mod_v[i] + mqck;

                demod_v.push_back(mqk);
            }
        }

        //printing message signal
        cout << "MESSAGE SIGNAL ->  \n";

        cout << "{";

        for (i = 0; i < amplitude.size(); i++)
            cout << amplitude
                        [i]
                 << " ";

        cout << "} \n";

        //printing modulated signal
        
        cout << " MODULATED SIGNAL ->  \n";

        cout << "{";

        for (i = 0; i < mod_v.size(); i++)
            cout << mod_v[i] << " ";

        cout << "} \n";

        //printing modulated signal
        cout << "DEMODULATED SIGNAL ->  \n";

        cout << "{";

        for (i = 0; i < demod_v.size(); i++)
            cout << demod_v[i] << " ";

        cout << "} \n";
    }
}
