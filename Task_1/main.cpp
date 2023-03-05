#include <bits/stdc++.h>
using namespace std;

int main()
{
    // The Inputs form user
    double Principal;
    int Term, YYYY, MM, DD, Month = 0;
    double Annual_rate;
    char c;

    cout << "Enter The Principal: ";                cin >> Principal;
    cout << "Enter Term: ";                         cin >> Term;
    cout << "Enter Annual rate: ";                  cin >> Annual_rate;
    cout << "Enter Initial Date \"YYYY-MM-DD\": ";  cin >> YYYY >> c >> MM >> c >> DD;

    // Outputs


    int Number_of_Payments = Term * 12;

    double Monthly_Rate = Annual_rate / (12 * 100);

    double Beginning_Balance = Principal;

    double Mortgage_Payment = Principal * ((Monthly_Rate * pow((1+Monthly_Rate), Number_of_Payments)) /
                                          (pow((1+Monthly_Rate), Number_of_Payments)-1));

    double Interest = Beginning_Balance * Monthly_Rate;

    Principal = Mortgage_Payment - Interest;

    double Ending_Balance = Beginning_Balance - Principal;

    cout << "\nMonths\tDate\t\tBeginning Balance\tPayment\t\tInterest\tPrincipal\tEnding Balance\n";
    while(Month++ < Number_of_Payments){
        cout << setw(3) << setfill ('0')<< Month << '\t'
             << YYYY << '-'
             << setw(2) << setfill ('0') << MM++ << '-'
             << setw(2) << setfill ('0') << DD << "\t"
             << '$' << fixed << setprecision(2) << Beginning_Balance << "\t\t"
             << '$' << fixed << setprecision(2) << Mortgage_Payment << "\t"
             << '$' << fixed << setprecision(2) << Interest << "\t\t"
             << '$' << fixed << setprecision(2) << Principal << "\t\t"
             << '$' << fixed << setprecision(2) << Ending_Balance << '\n';
        if(MM > 12) MM = 1, YYYY++;
        Beginning_Balance = Ending_Balance;
        Interest = Beginning_Balance * Monthly_Rate;
        Principal = Mortgage_Payment - Interest;
        Ending_Balance = Beginning_Balance - Principal;
    }

    return 0;
}
/*
240000
30
4.25
2023-01-01
*/
