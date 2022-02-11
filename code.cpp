#include<iostream>
#include<fstream>
using namespace std;
struct Cars {
    string mark [10] = {"Hyundai","BMW","Mercedes","Audi","Tesla","Skoda","Volkswagun","Toyota","Ford"};
    string model [10]= {"2016MD","2018AS","2018DS","2017LA","2018OW","2005Ps","2008PW","2010QW","2016SA"};
    string color [10]={"Red","black","yellow","Blue","Red","Brown","Silver","Black","grey"};
    string maxs_peed [10]={"100 Km/h ","150 Km/h","150 Km/h","170 Km/h","130 Km/h","140 Km/h","130 Km/h","120 Km/h","150 Km/h"};
    int price [ 10 ] ={1000,2000,3000,5000,2000,2500,4000,6000,9000} ;
    int date [10] = {2010,2012,2013,2017,2018,2005,2008,2010,2014};
   }car;

class carsrent{
    string Name;
   string Natio_ID;
   int payment_acc;
   int days;
   string pno;
   string date;
   string time;
   string car1,price1,model1;
   int totalamount;
  public:
  carsrent();
  void Minu ()
 {
     
   int num=1;
 for(int i=0 ;i<9;++i)
 {
 	cout<<"\t";
    cout<<"Enter " <<num<<"\t- To Select  "<<car.mark[i]<<endl;
    num++ ;
 }
 
 }
 void display();
// end of cars list
void menu();
void user_input(int);
void check (int j )
  {system("CLS");
      if(payment_acc  >= 0.1 * totalamount){
        
           cout<<"\n\n\tPayment linked has been shared to your phone number\n" <<endl;
           display();
           cout<<"\n\n\tYour car has been booked!! have a great time.. \n\n" <<endl;
      }
           else
              cout<<"\n\n\n\t\t\tSorry! process failed " <<endl;

  }
  void Details (int theChoice)
  {
   	 system("CLS");
  	 cout<<"\n\n\t-----------------------------\n";
     cout<<"\tYou Have Selected - "<<car.mark[theChoice-1]<<endl;
     car1=car.mark[theChoice-1];
     cout<<"\t-----------------------------\n\n\n";
     cout<<"\tModel : "<<car.model[theChoice-1]<<endl;
     model1=car.model[theChoice-1];
     cout<<"\tColor : "<<car.color[theChoice-1]<<endl;
     cout<<"\tMaximum Speed : "<<car.maxs_peed[theChoice-1]<<endl;
     cout<<"\tPrice per day: "<<car.price[theChoice-1]<<endl;
     price1=car.price[theChoice-1];
     user_input(theChoice);


  }
 void repeat(){
     char a;
     cout<<"\n\n\tdo you want to book another car(y/n): ";
     cin>>a;
     if(a=='y'){
        menu();
     }
     else{
         exit(0);
     }

 }
};
 carsrent::carsrent(){
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\t  Simple Car Rental System Login";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
  
   cin>>pass;
   if(pass == "pass"){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");
      system("CLS");

   }else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      carsrent();
   }
}
void carsrent::menu(){
    system("CLS");
       string decide ="y" ;
     cout<<"\n\t----------------------------------------------\n";
     cout<<"\t\tSIMPLE CAR RENTAL SYSTEM \n";
     cout<<"\tWelcome to Our Company ,Choose from the menu : "<<endl;
     cout<<"\t----------------------------------------------\n";
    
         Minu();
     cout<<"\n\n\n\t\t\tYour Choice: ";
     int theChoice ;
     cin>>theChoice ;
     if(theChoice<=9)
     Details(theChoice);
     else{
         system("CLS");
         cout<<"\nsorry booking failed...";
     }

     
// system("CLS");
     
   
    



}
void carsrent::user_input(int theChoice){
    int j=theChoice-1 ;
       cout<<"\t----------------------------------------\n";
       cout<<"\tPlease Provide Your Personal Details  : \n";
       cout<<"\t----------------------------------------\n\n";
       cout<<"\n\tNOTE: PROVIDE FIRST NAME ONLY, DONOT ENTER SPACE WHILE PROVIDING NAME\n\n\n\n";
       cout<<"\tEnter Your Name : ";
       cin>>Name;
       cout<<"\tEnter Your National ID : ";
       cin>>Natio_ID;
       cout<<"\tEnter Your your phone number: ";
       cin>>pno ;
       cout<<"\tEnter date(dd/mm/yy): ";
       cin>>date ;
       cout<<"\tEnter time(hh:mm): ";
       cin>>time ;
       cout<<"\tEnter no of days: ";
       cin>>days;

        totalamount=car.price[theChoice-1]*days;
        cout<<"\n\tthe total amount will be: "<<totalamount<<endl;

       cout<<"\n\tNote:\n\t**Your advance amount should be atleast 10% of price per day**"<<endl;
       cout<<"\n\n\t minimum advance amount: "<<totalamount*0.1<<endl;
       cout<<"\tAdvance Amount: " ;
       cin>>payment_acc ;


     check( j ) ;
   
}
void carsrent::display(){
    cout<<"\n\n\n\t\t Booking details\n"
    <<"\n\tName: "<<Name
    <<"\n\tContact no: "<<pno
    <<"\n\tCar: "<<car1
    <<"\n\tPrice: "<<totalamount
    <<"\n\tmodel: "<<model1
    <<"\n\tBooked on date: "<<date
    <<"\n\ttime: "<<time
    <<"\n\n\t***Car will be delivered 15mins before the scheduled time***";
    fstream f;
    f.open("carsdetails.txt",ios::app);
    f<<"\n\n\n\t\t Booking details\n"
    <<"\n\tName: "<<Name
    <<"\n\tContact no: "<<pno
    <<"\n\tCar: "<<car1
    <<"\n\tPrice: "<<totalamount
    <<"\n\tmodel: "<<model1
    <<"\n\tBooked on date: "<<date
    <<"\n\ttime: "<<time;
    f.close();
    repeat();


}

int main(){
    carsrent a;
    
    a.menu();
    
    return 0;
}
