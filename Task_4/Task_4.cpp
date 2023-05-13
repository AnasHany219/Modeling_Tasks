#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;
class Customer{
private:
    int Arrival_Time;
    int Servise_Time;
    int Servise_Start_Time;
    int Time_Wait = 0;
    int Servise_End_Time;
    int Time_Spend_InSystem = 0;
    int Idle_Time;
public:
    void setArrival_Time(int ATime = 0){
        Arrival_Time = ATime;
    }
    int getArrival_Time(){
        return Arrival_Time;
    }
    void setServise_Time(int Stime = 0){
        Servise_Time = Stime;
    }
    int getServise_Time(){
        return Servise_Time;
    }
    void setServise_Start_Time(int SStime = 0){
        Servise_Start_Time = SStime;
    }
    int getServise_Start_Time(){
        return Servise_Start_Time;
    }
    void setTime_Wait(){
        Time_Wait = Servise_Start_Time - Arrival_Time;
    }
    int getTime_Wait(){
        return Time_Wait;
    }
    void setServise_End_Time(int SEtime = 0){
        Servise_End_Time = SEtime;
    }
    int getServise_End_Time(){
        return Servise_End_Time;
    }
    void setTime_Spend_InSystem(){
        Time_Spend_InSystem = Time_Wait + Servise_Time;
    }
    int getTime_Spend_InSystem(){
        return Time_Spend_InSystem;
    }
    void setIdle_Time(int IT = 0){
        Idle_Time = IT;
    }
    int getIdle_Time(){
        return Idle_Time;
    }
};

int main(){
    cout << "The number of \"times between arrivals\": ";
    int Ntba;   cin >> Ntba;

    vector<int>Inter_arrival_Time(Ntba+1, 0);
    vector<double>Probability(Ntba+1, 0);
    vector<double>Comulative_Probability(Ntba+1, 0);
    vector<pair<pair<double, double>, double>>vpp(Ntba+1);

    srand( (unsigned)time( NULL ) );

    for(int i = 0; i < Ntba; i++){
        cout << "Enter the Inter-arrival Time & Probability: ";
        cin >> Inter_arrival_Time[i] >> Probability[i];
        Inter_arrival_Time[i] *= 60;
    }
    for(int i = 1; i <= Ntba; i++){
        Comulative_Probability[i] = Comulative_Probability[i-1] + Probability[i-1];
        vpp[i-1].first.first = Comulative_Probability[i-1];
        vpp[i-1].first.second = Comulative_Probability[i];
        vpp[i-1].second = Inter_arrival_Time[i-1];

    }

    cout << "\nEnter mean(minutes) & Standard deviation (minutes): ";
    int mean, standard; cin >> mean >> standard;
    int maxi = mean + standard, mini = mean - standard;

    cout << "\nEnter the number of customers: ";
    int cust; cin >> cust;

    cout << "\nDo you prefer to write the duration of services? [Y/N]: ";
    char c;
    cin >> c;
    if(c == 'Y' || c == 'y')
        cout << "I'm just joking with you :) I will choose them randomly ^^";
    else
        cout << "Ok! I will choose them randomly ^^";

    vector<Customer>customer(cust + 3);
    cout << "\n\nJob\tArrival Rand\tIn Arrival\tArrival Time\tService Time\tStart Time\tTime Wait\tEnd Time\tTime Spent\tIdle Time\n";

    customer[0].setServise_Time(25);
    customer[0].setTime_Wait();
    customer[0].setServise_End_Time(customer[0].getServise_Time() + customer[0].getServise_Start_Time());
    customer[0].setTime_Spend_InSystem();
    cout << 'A' << "\tGiven" << "\t\tUnknown" << "\t\t" << customer[0].getArrival_Time() << "\t\t" << customer[0].getServise_Time() << "\t\t" << customer[0].getServise_Start_Time() << "\t\t" << customer[0].getTime_Wait() << "\t\t" << customer[0].getServise_End_Time() << "\t\t" << customer[0].getTime_Spend_InSystem() << "\t\t" << customer[0].getIdle_Time() << '\n';

    customer[1].setServise_Time(50);
    customer[1].setServise_Start_Time(customer[0].getServise_End_Time());
    customer[1].setTime_Wait();
    customer[1].setServise_End_Time(customer[1].getServise_Time() + customer[1].getServise_Start_Time());
    customer[1].setTime_Spend_InSystem();
    customer[1].setIdle_Time(customer[1].getServise_Start_Time() - customer[0].getServise_End_Time());
    cout << 'B' << "\tGiven" << "\t\tUnknown" << "\t\t" << customer[1].getArrival_Time() << "\t\t" << customer[1].getServise_Time() << "\t\t" << customer[1].getServise_Start_Time() << "\t\t" << customer[1].getTime_Wait() << "\t\t" << customer[1].getServise_End_Time() << "\t\t" << customer[1].getTime_Spend_InSystem() << "\t\t" << customer[1].getIdle_Time() << '\n';

    int Total_IAT = 0;
    int Total_WT = 0;
    int Total_ST = 0;
    int Max_time = 0;
    for(int i = 2; i < cust + 3; i++){
        double Arrival_rand = (float) rand()/RAND_MAX;
        int interArrival = 0;
        for(int i = 0; i < Ntba; i++){
            if(Arrival_rand >= vpp[i].first.first && Arrival_rand < vpp[i].first.second)
                interArrival = vpp[i].second;
        }
        customer[i].setArrival_Time(customer[i-1].getArrival_Time() + interArrival);
        customer[i].setServise_Time(rand()%((maxi - mini) + 1) + maxi);
        if(customer[i-1].getServise_End_Time() >= customer[i].getArrival_Time())
            customer[i].setServise_Start_Time(customer[i-1].getServise_End_Time());
        else
            customer[i].setServise_Start_Time(customer[i].getArrival_Time());
        customer[i].setTime_Wait();
        customer[i].setServise_End_Time(customer[i].getServise_Time() + customer[i].getServise_Start_Time());
        customer[i].setTime_Spend_InSystem();
        customer[i].setIdle_Time(customer[i].getServise_Start_Time() - customer[i - 1].getServise_End_Time());

        cout << i - 2 << '\t'
             << fixed << setprecision(6) << Arrival_rand << "\t"
             << interArrival << "\t\t"
             << customer[i].getArrival_Time() << "\t\t"
             << customer[i].getServise_Time() << "\t\t"
             << customer[i].getServise_Start_Time() << "\t\t"
             << customer[i].getTime_Wait() << "\t\t"
             << customer[i].getServise_End_Time() << "\t\t"
             << customer[i].getTime_Spend_InSystem() << "\t\t"
             << customer[i].getIdle_Time() << '\n';

        Total_WT += customer[i].getTime_Wait();
        Total_ST += customer[i].getServise_Time();
        Max_time = max(Max_time, customer[i].getTime_Spend_InSystem());

    }
    cout << "\nAverage service time: " << (double)Total_ST/(cust+3) << '\n'
         << "Average Wait Time: " << (double)Total_WT/(cust+3) << '\n'
         << "The maximum time in the system: " << Max_time << '\n';
    return 0;
}
/*
6
0 0.23
1 0.22
2 0.18
3 0.12
4 0.1
5 0.15
50 10
20

*/
