#include <iostream>
//#include<gtk/gtk.h>
#include<fstream>
#include<bits/stdc++.h>
#include<dos.h>
#include<stdio.h>
#include<windows.h>
#include<unistd.h>

using namespace std;


void new_coupon(string coupon)
{
    ofstream file;
    file.open("newcoupon.txt",ios::app);
    file<<coupon<<"\n";
    file.close();

}
void view_coupons()
{
    string line;
    ifstream rfile("newcoupon.txt");
    while(getline(rfile,line))
    {
        cout<<line<<endl;
    }
    cout<<endl;
    rfile.close();
}
void searchcoupon(string coupon)
{
    string line;
    ifstream rfile("newcoupon.txt");
    ofstream wfile;
    wfile.open("tempfile.txt",ios::trunc);
    while(getline(rfile,line))
    {
        if(coupon.compare(line)!=0)
        {
            wfile<<line<<"\n";
        }
        else
        {
            cout<<"The coupon is found"<<endl;
            cout<<"....Deleting...."<<endl;
        }
    }
    rfile.close();
    wfile.close();
  int z= remove("newcoupon.txt");
   int p=rename("tempfile.txt","newcoupon.txt");

}

int main()
{

    system("Color E4");
    int choice;
    string coupon;
    string searchd;
    while(1)
    {
        cout<<"1.Enter new Coupon Nuumber"<<endl;
        cout<<"2.View Existing Coupons"<<endl;
        cout<<"3.Search and delete the Coupon"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                cout<<"Enter the coupon number"<<endl;
                cin>>coupon;
                new_coupon(coupon);
                break;
            }
        case 2:
            {
                view_coupons();
                break;
            }
        case 3:
            {
                cout<<"Enter the coupon to be searched"<<endl;
                cin>>searchd;
                searchcoupon(searchd);
                break;
            }
        case 4:
            {
                exit(0);
                break;
            }
        }
    }
    return 0;
}
