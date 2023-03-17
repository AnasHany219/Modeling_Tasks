#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Demand;
    cout << "Enter Number of Demands: ";
    cin >> Demand;

    int Frequency[Demand];
    double Sum_Freq = 0;

    cout << "Enter the Frequency:\n";
    for(int i = 0; i < Demand; i++){
        cout << "Demand " << i << " = ";
        cin >> Frequency[i];
        Sum_Freq += Frequency[i];
    }

    double Probability, Cumulative = 0;

    vector<pair<int, pair<int , int>>>vp(Demand);
    vp[0].first = 1;

    cout <<"\nDemand\tFrequency\tProbability\tCumulative\tIntervals\n";
    for(int i = 0; i < Demand; i++){
        Probability = Frequency[i]/Sum_Freq;
        Cumulative += Probability;
        vp[i].second.second = i;
        vp[i].second.first = Cumulative*100;
        cout << i << '\t'
             << Frequency[i] << "\t\t"
             << fixed << showpoint << setprecision(2) << Probability << "\t\t"
             << Cumulative << "\t\t"
             << setw(3) << setfill ('0') << vp[i].first << " - "
             << setw(3) << setfill ('0') << vp[i].second.first << '\n';
        vp[i+1].first = vp[i].second.first + 1;
    }
    cout << "Total:\t" << Sum_Freq;

    int Rand_N;
    cout << "\n\nEnter an integer random number from 1 to 100: ";
    cin >> Rand_N;
    for(int i = 0; i < Demand; i++){
        if(Rand_N >= vp[i].first && Rand_N <= vp[i].second.first){
            cout << "The Number " << Rand_N
                 << " is in interval: "
                 << setw(3) << setfill ('0') << vp[i].first << " - "
                 << setw(3) << setfill ('0') << vp[i].second.first
                 << ", and in demand: " << vp[i].second.second << '\n';
            break;
        }
    }
    return 0;
}
/*
Enter Number of Demands: 6
Enter the Frequency:
Demand 0 = 10
Demand 1 = 20
Demand 2 = 40
Demand 3 = 60
Demand 4 = 40
Demand 5 = 30

Demand  Frequency       Probability     Cumulative      Intervals
0       10              0.05            0.05            001 - 005
1       20              0.10            0.15            006 - 015
2       40              0.20            0.35            016 - 035
3       60              0.30            0.65            036 - 065
4       40              0.20            0.85            066 - 085
5       30              0.15            1.00            086 - 100
Total:  200.00

Enter an integer random number from 1 to 100: 55
The Number 55 is in interval: 036 - 065, and in demand: 3
*/
