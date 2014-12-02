#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<conio.h>


using namespace std;

int main()
{
    fstream dfile("ids.txt");
    fstream pfile("pass.txt");
    vector<string> data;


    cout<<" \tWhat is the name of the movie you watched recently\n";
    string ans;
    cin>>ans;
    string password;
    if(pfile.is_open())
    {
        while(pfile.good())
        getline(pfile,password);
    }
        pfile.close();
    if(ans!=password)return 0;

    if(dfile.is_open())
    {
        string t;
        while(dfile.good())
        {
            getline(dfile,t);
            data.push_back(t);
        }
    }

    dfile.close();

    cout<<"\n\n\tWelcome to Rss password Database :P !  choose your option-\n\n";

    string cont="yes";
    while(cont=="yes"){
    cout<<"\n1.Add an account.\n";
    cout<<"2.Remove an account.\n";
    cout<<"3.View account details.\n";
    cout<<"4.Change Rss-PDB access password.\n\n";
    int op; cin>>op;
    if(op==3)
    {
        int j=0;
        for(int i=0;i!=data.size();i+=3)
        {
            j++;
            cout<<j<<"."<<data[i]<<"\n";
        }
        int te;
        cout<<"\nPlease enter your choice!\n";
        cin>>te;
//        clrscr();
        cout<<"   ***********************************************************\n\n";
        cout<<"Website name- \t"<<data[(te-1)*3]<<"\n\n";
        cout<<"User-ID || Handle - \t"<<data[(te-1)*3 +1]<<"\n\n";
        cout<<"Password -\t"<<data[(te-1)*3 +2]<<"\n\n";
        cout<<"   ***********************************************************\n\n";
    }
    else if(op==2)
    {
        int j=0;
        for(int i=0;i!=data.size();i+=3)
        {
            j++;
            cout<<j<<"."<<data[i]<<"\n";
        }
        int te; cin>>te;
        data.erase(data.begin()+ (te-1)*3);data.erase(data.begin()+(te-1)*3+1);data.erase(data.begin()+(te-1)*3+2);
        cout<<"Entry number "<<te<<" successfully removed!\n\n";
    }
    else if(op==1)
    {
        string s1,s2,s3;
        cout<<"Account name ? \n"; cin>>s1; data.push_back(s1);
        cout<<"User ID ?\n"; cin>>s2; data.push_back(s2);
        cout<<"password ?\n";  cin>>s3; data.push_back(s3);
        cout<<"New account successfully added.\n";
    }
    else if(op==4)
    {
        string passF ,passS;
        do{
        cout<<"Enter new password: "; cin>>passF;
        cout<<"Confirm new password: "; cin>>passS;
        if(passF!=passS) cout<<"password doesn't match!\n";
        }
        while(passF!=passS);
       ofstream pfile2("pass.txt",ofstream::trunc); pfile2<<passF; pfile2.close();
    }
    else {cout<<"Invalid choice dumbAss! \n"; }

    cout<<"you want to try again?\n"; cin>>cont;

    }
    fstream dfile2("ids.txt");

    for(int i=0;i!=data.size()-1;i++) dfile2<<data[i]<<"\n";
    dfile2<<data[data.size()-1];


    dfile2.close();
    return 0;
}
