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
    void set_Time_Customer(){
        Time_Customer = Waiting_Time + Service_Time;
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
    cout << "Enter the number of customer: ";
    cin >> Customer;
    vector<Cstmr>cst(Customer);
    for(int i = 0; i < Customer; i++){
        cout << "Enter a Inter-arrival Time & Service Time: ";
        cin >> IAT;
        cst[i].set_Inter_arrival_Time(IAT);
        AT += cst[i].get_Inter_arrival_Time();
        cst[i].set_arrival_Time(AT);
        cin >> ST;
        cst[i].set_Service_Time(ST);
        if(STE >= cst[i].get_arrival_Time())
            STB = STE;
        else
            STB = AT;
        cst[i].set_Service_Time_Begins(STB);
        STE = STB + ST;
        cst[i].set_Service_Time_Ends(STE);
        cst[i].set_Waiting_Time();
        cst[i].set_Time_Customer();
        IT = cst[i].get_Service_Time_Begins() - cst[i-1].get_Service_Time_Ends();
        cst[i].set_Idle_Time(IT);
    }

    cout << "\nCustomer\tInter-arrival Time\tArrival Time\tService Time\tService Time Begins\tService Time Ends\tWaiting Time\tTime Customer\tIdle Time\n";
    for(int i = 0; i < Customer; i++){
        cout << i+1 << "\t\t";
        cst[i].Print();

    }
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
*/