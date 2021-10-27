//Performance Task 2
//Description: Conversion Console App using functions [Dollar to Peso & Peso to Dollar]
//This is also a debugging activity
//Name: Isaiah Miguel M. Flandez

#include<iostream>

using namespace std;

struct group_facet: public numpunct<char>{
    protected:
        string do_grouping() const{return"\003";}
};
void promptAndWait();
void dollarsToPeso(float rate, unsigned dollar);
void PesosTodollar(float rate, unsigned peso);

int main(){
    float DPconversionRate = 50.83;//$1 = 50.83 Pesos 
    float PDconversionRate = 0.02;//Php 1 = 0.20 Dollars 
    unsigned dollarsIn, pesosIn;
    int ch, ans=0;

    do{
        system("cls");
        cout<<endl;
        cout<<"Dollar to Peso Conversion App"<<endl<<endl;
        cout<<"[1] Dollar to Peso"<<endl;
        cout<<"[2] Peso to Dollar"<<endl;
        cout<<"[0] Exit the Conversion App"<<endl<<endl;
        cout<<"Select Conversion : ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"\n<<Convert Dollar to Peso>>"<<endl;
                dollarsToPeso(DPconversionRate, 1);
                cout<<"\nEnter a US dollar amount :";
                cin>>dollarsIn;
                dollarsToPeso(DPconversionRate, dollarsIn);
                promptAndWait();
                break;
    
            case 2:
                cout<<"\n<<Convert Peso to Dollar>>"<<endl;
                PesosTodollar(PDconversionRate, 1);
                cout<<"\nEnter a Peso amount :";
                cin>>pesosIn;
                PesosTodollar(PDconversionRate, pesosIn);
                promptAndWait();
                break;
        
            case 0:
                promptAndWait();
                cout<<"Conversion App Terminated \nThank you for using the app!";
                return 0;

            default:
                cout<<"Invalid Input!";
                promptAndWait();
        }
    }while(ans == 0);
}
void promptAndWait(){
    cin.ignore(100, '\n');
    cout<<"\nPress Enter or Return to continue...";
    cin.get();
}
void dollarsToPeso(float rate, unsigned dollar){
    cout.setf(ios::fixed);
    cout.precision(2);

    cout.imbue(locale(cout.getloc(), new group_facet));
    cout<<"\n$"<<dollar<<" US = Php "<<(rate*dollar)<<endl;
}
void PesosTodollar(float rate, unsigned peso){
    cout.setf(ios::fixed);
    cout.precision(2);

    cout.imbue(locale(cout.getloc(), new group_facet));
    cout<<"\nPhp "<<peso<<" = $"<<(rate*peso)<<endl;
}
