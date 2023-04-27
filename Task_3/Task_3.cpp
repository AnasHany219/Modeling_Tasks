#include <bits/stdc++.h>

using namespace std;
class Cstmr
{
private:
    int Inter_arrival_Time;
    int arrival_Time = 0;
    int Service_Time;
    int Service_Time_Begins = 0;
    int Service_Time_Ends = 0;
    int Waiting_Time;
    int Time_Customer;
    int Idle_Time;
public:
    void set_Inter_arrival_Time(int IAT){
        Inter_arrival_Time = IAT;
    }
    int get_Inter_arrival_Time(){
        return Inter_arrival_Time;
    }
    void set_arrival_Time(int AT){
        arrival_Time = AT;
    }
    int get_arrival_Time(){
        return arrival_Time;
    }
    void set_Service_Time(int ST){
        Service_Time = ST;
    }
    void set_Service_Time_Begins(int STB){
        Service_Time_Begins = STB;
    }
    void set_Service_Time_Ends(int STE){
        Service_Time_Ends = STE;
    }
    void set_Waiting_Time(){
        Waiting_Time = Service_Time_Begins - arrival_Time;
    }
    int get_Waiting_Time(){
        return Waiting_Time;
    }
    void set_Time_Customer(){
        Time_Customer = Waiting_Time + Service_Time;
    }
    int get_Time_Customer(){
        return Time_Customer;
    }
    void set_Idle_Time(int IT){
        Idle_Time = IT;
    }
    int get_Service_Time_Begins(){
        return Service_Time_Begins;
    }
    int get_Service_Time_Ends(){
        return Service_Time_Ends;
    }

    void Print(){
        cout << Inter_arrival_Time << "\t\t\t"
             << arrival_Time << "\t\t"
             << Service_Time << "\t\t"
             << Service_Time_Begins << "\t\t\t"
             << Service_Time_Ends << "\t\t\t"
             << Waiting_Time << "\t\t"
             << Time_Customer << "\t\t"
             << Idle_Time << '\n';
    }
};
int main()
{
    int Customer, IAT, AT = 0, ST, STB = 0, STE = 0, IT;
    int Total_IAT = 0, Total_ST = 0, Total_WT = 0, Total_TC = 0, Total_IT = 0;
    cout << "Enter the number of customer: ";
    cin >> Customer;
    vector<Cstmr>cst(Customer);
    for(int i = 0; i < Customer; i++){
        cout << "Enter a Inter-arrival Time & Service Time: ";
        cin >> IAT;
        Total_IAT += IAT;
        cst[i].set_Inter_arrival_Time(IAT);
        AT += cst[i].get_Inter_arrival_Time();
        cst[i].set_arrival_Time(AT);
        cin >> ST;
        Total_ST += ST;
        cst[i].set_Service_Time(ST);
        if(STE >= cst[i].get_arrival_Time())
            STB = STE;
        else
            STB = AT;
        cst[i].set_Service_Time_Begins(STB);
        STE = STB + ST;
        cst[i].set_Service_Time_Ends(STE);
        cst[i].set_Waiting_Time();
        Total_WT += cst[i].get_Waiting_Time();
        cst[i].set_Time_Customer();
        Total_TC += cst[i].get_Time_Customer();
        IT = cst[i].get_Service_Time_Begins() - cst[i-1].get_Service_Time_Ends();
        Total_IT += IT;
        cst[i].set_Idle_Time(IT);
    }
    /*
    Average service time
    Average wait
    Average time
    */
    cout << "\nCustomer\tInter-arrival Time\tArrival Time\tService Time\tService Time Begins\tService Time Ends\tWaiting Time\tTime Customer\tIdle Time\n";
    for(int i = 0; i < Customer; i++){
        cout << i+1 << "\t\t";
        cst[i].Print();

    }
    cout << "Total\t\t"
         << Total_IAT << "\t\t\t\t\t"
         << Total_ST << "\t\t\t\t\t\t\t\t"
         << Total_WT << "\t\t"
         << Total_TC << "\t\t"
         << Total_IT << '\n'
         << "\nAverage service time: " << (double)Total_ST/Customer << '\n'
         << "Average Wait Time: " << (double)Total_WT/Customer << '\n'
         << "Average Time Customer: " << (double)Total_TC/Customer << '\n';

    return 0;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cout << "Enter a number of customers: ";
    cin >> n;
    vector<int>InterArrivalTime(n+1);
    double Total_InterArrivalTime = 0;

    vector<int>ArrivalTime(n+1);

    vector<int>ServiceTime(n+1);
    double Total_ServiceTime = 0;

    vector<int>TimeServiceBegins(n+1, 0);

    vector<int>TimeServiceEnds(n+1, 0);

    vector<int>WaitingTime(n+1);
    double Total_WaitingTime = 0;

    vector<int>TimeCustomer(n+1);
    double Total_TimeCustomer = 0;

    vector<int>IdleTime(n+1);
    double Total_IdleTime = 0;

    for(int i = 1; i <= n; i++){
        cout << "Inter-arrival Time and Service Time: ";
        cin >> InterArrivalTime[i];
        Total_InterArrivalTime += InterArrivalTime[i];

        ArrivalTime[i] = Total_InterArrivalTime;

        cin >> ServiceTime[i];
        Total_ServiceTime += ServiceTime[i];

        if(TimeServiceEnds[i-1] >= ArrivalTime[i])
            TimeServiceBegins[i] = TimeServiceEnds[i-1];
        else
            TimeServiceBegins[i] = ArrivalTime[i];

        TimeServiceEnds[i] = TimeServiceBegins[i] + ServiceTime[i];

        WaitingTime[i] = TimeServiceBegins[i] - ArrivalTime[i];
        Total_WaitingTime += WaitingTime[i];

        TimeCustomer[i] = WaitingTime[i] + ServiceTime[i];
        Total_TimeCustomer += TimeCustomer[i];

        IdleTime[i] = TimeServiceBegins[i] - TimeServiceEnds[i-1];
        Total_IdleTime += IdleTime[i];
    }
    cout << "\nCustomer\tInter-arrival Time\tArrival Time\tService Time\t"
         << "Service Time Begins\tService Time Ends\tWaiting Time\tTime Customer\tIdle Time\n";

    for(int i = 1; i <= n; i++){
        cout << i << "\t\t" << InterArrivalTime[i] << "\t\t\t" << ArrivalTime[i] << "\t\t" << ServiceTime[i] << "\t\t";
        cout << TimeServiceBegins[i] << "\t\t\t" << TimeServiceEnds[i] << "\t\t\t" << WaitingTime[i] << "\t\t" << TimeCustomer[i] << "\t\t" << IdleTime[i] << endl;
    }
    cout << "Total\t\t" << Total_InterArrivalTime << "\t\t\t\t\t" << Total_ServiceTime << "\t\t\t\t\t\t\t\t";
    cout << Total_WaitingTime << "\t\t" << Total_TimeCustomer << "\t\t" << Total_IdleTime << endl << endl;

    cout << "Average service time: " << Total_ServiceTime/n << endl;
    cout << "Average Wait Time: " << Total_WaitingTime/n << endl;
    cout << "Average Time Customer: " << Total_TimeCustomer/n << endl;
    return 0;
}
/*
Enter the number of customer: 6
Enter a Inter-arrival Time & Service Time: 0 4
Enter a Inter-arrival Time & Service Time: 1 2
Enter a Inter-arrival Time & Service Time: 1 5
Enter a Inter-arrival Time & Service Time: 6 4
Enter a Inter-arrival Time & Service Time: 3 1
Enter a Inter-arrival Time & Service Time: 7 5

Customer        Inter-arrival Time      Arrival Time    Service Time    Service Time Begins     Service Time Ends       Waiting Time    Time Customer   Idle Time
1               0                       0               4               0                       4                       0               4               0
2               1                       1               2               4                       6                       3               5               0
3               1                       2               5               6                       11                      4               9               0
4               6                       8               4               11                      15                      3               7               0
5               3                       11              1               15                      16                      4               5               0
6               7                       18              5               18                      23                      0               5               2
Total           18                                      21                                                              14              35              2

Average service time: 3.5
Average Wait Time: 2.33333
Average Time Customer: 5.83333
*/

/*
6
0 4
1 2
1 5
6 4
3 1
7 5
-----------------------------
50
0 4
1 2
3 1
2 3
4 5
7 2
5 4
9 6
6 3
8 1
1 7
3 2
4 5
2 8
7 4
5 6
6 3
1 2
8 9
9 1
3 4
2 7
4 5
5 2
6 0
7 6
8 1
1 9
3 4
2 7
5 8
7 2
6 1
4 9
9 6
1 5
8 3
5 4
2 2
6 1
8 6
7 5
3 2
1 8
2 7
5 9
4 3
6 2
2 1
3 1
*/
