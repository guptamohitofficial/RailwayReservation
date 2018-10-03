#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <ctime>
using namespace std;
void main_1();
class Passanger
{
    short int age,amount=0;
    char name[25];
public :
    void pass_info_in(int i)
    {
        cout<<"Enter the name of the Passanger "<<i<<" : ";
        fflush(stdin);
        gets(name);
        cout<<"Enter the age of the Passanger "<<i<<" : ";
        cin>>age;
        if(age<1||age>100)
        {cout<<"Sorry Passanger "<<i<<" can not travell in train"<<endl;
         system("pause");
         main_1();}
    }
    string age_check()
    {
        if(age<6)
            return ("Child");
        else if(age>60)
            return ("SeniorCitizen");
        else
            return ("Adult");
    }
    short int amoun(short int amt)
    {
        amount=amt;
        return amount;
    }
    short int amoun()
        {return amount;}
    string nam()
        {return strupr(name);}
    short int ag()
        {return age;}
};

short int distanc(short int,short int);
string station(short int);
short int strln(string);
void space(short int);
void space2(short int);
void space3(short int);
void chc_sta(short int &,short int &);
short int cal_amo(short int,string);
string cal_amo();
short int reuse(short int);

static short int remained_seats=10;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
int main()
{main_1();}
void main_1()
{
    system("cls");
    cout<<"########!!!!########   ****  NOTE  ****  ########!!!!########"<<"\n"<<"## THIS APPLICATION IS  'CASE SENSITIVE'  ENTER PROPERLY ##"<<"\n"<<"\n";
    short int *pass_num,start=0,stop=0,dis,amo=0,add=50,z,l,&sto=stop,&star=start;
    pass_num=new short int;
    char date[10];
    string str;
    _strdate(date);

    cout<<"Enter the number of Passangers : ";
    cin>>*pass_num;

    if(*pass_num<=0||*pass_num>remained_seats)
    {
        cout<<"!!!! SORRY WE CAN NOT CREATE TICKETS FOR THIS NUMBER OF PASSENGERS !!!!"<<endl;
        cout<<remained_seats<<" seats are avaliable only"<<endl;
        system("pause");
        main_1();
    }
    Passanger p[*pass_num];
    for(int i=0;i<*pass_num;i++)
        p[i].pass_info_in(i+1);

    chc_sta(start,stop);

    dis=distanc(start,stop);
        for(int y=0;y<dis;y=y+100)
        {   amo=amo+add;
            add=add-10;
            if(add<25)
            add=25;
        }
    l=dis%100;
    amo=amo+(l*0.35);
    str=cal_amo();
    amo=cal_amo(amo,str);

    for(int i=0;i<*pass_num;i++)
    {   p[i].amoun(amo);
        if(p[i].age_check()=="Child"||p[i].age_check()=="SeniorCitizen")
                p[i].amoun((amo*0.5));
                z=p[i].amoun()%10;
                if(z==1||z==2)
                p[i].amoun(p[i].amoun()-z);
                if(z==3||z==4)
                p[i].amoun(p[i].amoun()+(5-z));
                if(z==6||z==7)
                p[i].amoun(p[i].amoun()-(z-5));
                if(z==8||z==9)
                p[i].amoun(p[i].amoun()+(10-z));
    }
    system("cls");
     for(int i=0;i<*pass_num;i++)
    {
    cout<<endl<<"     ****************************************************************"<<endl;
    cout<<"     * !!!! ********** !!!! RESERVATION TICKET !!!! ********** !!!! *"<<endl;
    cout<<"     *                                                              *"<<endl;
    cout<<"     *  "<<p[i].nam();
    space(strln(p[i].nam()));
    cout<<"    DATE : ";
    cout<<date<<"    *"<<endl;
    cout<<"     *  Age : "<<p[i].ag()<<"                   ";
    space2(strln(patch::to_string(p[i].ag())));
    cout<<"  Seat No. : "<<11-remained_seats;
    space3(strln(patch::to_string(remained_seats-1)));
    cout<<" *"<<endl;
    remained_seats--;
    cout<<"     *      FROM     "<<station(start);
    space2(strln(station(start))+4);
    cout<<"TO";
    space2(strln(station(stop))+3);
    cout<<station(stop);
    space2(-7);
    cout<<"  *";
    cout<<endl;
    cout<<"     *  "<<p[i].age_check()<<" : 1";
    space(strln(p[i].age_check()));
    cout<<"                   *"<<endl;
    cout<<"     *  Amount : "<<p[i].amoun();
    space3(strln(patch::to_string(p[i].amoun())));
    cout<<"                       ";
    cout<<"  DISTANCE : "<<dis;
    space3(strln(patch::to_string(dis))+1);
    cout<<"  *"<<endl;
    cout<<"     *  Class : "<<str;
    space(strln(str));
    cout<<"               *"<<endl;
    cout<<"     *                                                              *"<<endl;
    cout<<"     ****************************************************************"<<endl;
    cout<<endl;
    }
    reuse(remained_seats);
}

short int reuse(short int r)
{
        char reus[6];
        cout<<"\n\n Reamining seats : "<<r<<endl;
        cout<<"\nEnter 'exit' to EXIT from application or 'again' to book more tickets"<<"\n";
        cin>>reus;
        if (strcmp(reus,"exit")==0)
            return 0;
        else if(strcmp(reus,"again")==0)
                main();
        else
            {cout<<"!!!!!!!******!!!!!!!ENTRY IS NOT CORRECT!!!!!!!*******!!!!!!!"<<"\n"<<"!!!!!!!******!!!!!!!    ENTER AGAIN    !!!!!!!*******!!!!!!!";
             system("pause");
             system("clear");
             reuse(r);
            }
}
    void chc_sta(short int &star,short int &sto)
{
    system("cls");
    cout<<"########!!!!########   ****  NOTE  ****  ########!!!!########"<<"\n"<<"## THIS APPLICATION IS  'CASE SENSITIVE'  ENTER PROPERLY ##"<<"\n"<<"\n";
    cout<<"Enter the code for choosing stations :"<<endl;
    cout<<"Indore      ----    1    ||   Vidisha     ----    6"<<endl;
    cout<<"Devas       ----    2    ||   Bina        ----    7"<<endl;
    cout<<"ujjain      ----    3    ||   Lalitpur    ----    8"<<endl;
    cout<<"Sehore      ----    4    ||   Jhansi      ----    9"<<endl;
    cout<<"Bhopal      ----    5    ||   Gwalior     ----    10"<<endl;

    cout<<"Enter the station code from where you have to start Traveling : ";
    cin>>star;

    if(star<1||star>10)
    {
        cout<<"!!!! Entered wrong Departure station code !!!! "<<endl;
        system("pause");
        chc_sta(star,sto);
    }

    cout<<"Enter the station code to where you have to Traveling : ";
    cin>>sto;

    if(sto<1||sto>10)
    {
        cout<<"!!!! Entered wrong Landing station code !!!! "<<endl;
        system("pause");
        chc_sta(star,sto);
    }
}
    short int cal_amo(short int am,string check_clas)
{
    if(check_clas=="GENERAL")
        am=am;
    else if(check_clas=="SLEEPER")
        am=am*1.9;
    else
        am=am*3.0;
    return am;
}
string cal_amo()
{
    system("cls");
    string check_class;
    cout<<"########!!!!########   ****  NOTE  ****  ########!!!!########"<<"\n"<<"## THIS APPLICATION IS  'CASE SENSITIVE'  ENTER PROPERLY ##"<<"\n"<<"\n";
    cout<<"\n!!!!CODES FOR CHOOSING CLASS!!!!\nGeneral            ----     g\nSleeper            ----     s\nAirConditioner     ----     a\nPlease Enter the class code in which you want to travel : ";
    cin>>check_class;

    if(check_class=="g")
        check_class="GENERAL";
    else if(check_class=="s")
        check_class="SLEEPER";
    else if(check_class=="a")
        check_class="AirConditioner";
    else
        {cout<<"Entered WRONG Class"<<endl;
        system("pause");
        cal_amo();
        }
    return check_class;
}
string station(short int i)
{
    string stat[10]={"Indore","Devas","Ujjain","Sehore","Bhopal","Vidisha","Bina","Lalitpur","Jhansi","Gwalior"};

       return (stat[i-1]);
}
void space(short int j)
{
short int i;
for(i=0;i<(38-j);i++)
cout<<" ";
}

void space2(short int j)
{
short int i;
for(i=0;i<(15-j);i++)
cout<<" ";
}

void space3(short int j)
{
short int i;
for(i=0;i<(8-j);i++)
cout<<" ";
}
short int strln(string s)
{
short int i;
for(i=0;s[i]!='\0';i++);
return (i+1);
}
short int distanc(short int start,short int stop)
{
    short int dis[10]={0,38,41,145,38,54,85,63,90,98};
    short int sum=0;
          if(start>stop)
        {
            for(int i=stop;i<start;i++)
            sum=sum+dis[i];
        }
        else
        {
            for(int i=start;i<stop;i++)
            sum=sum+dis[i];
        }
    return sum;
}
