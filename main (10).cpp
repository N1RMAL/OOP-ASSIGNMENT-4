#include <iostream>
#include <string.h>
using namespace std;

int i, players, num, all, minibo, minibat, min1, min2, bat[100], bowl[100], sortbowl[100], sortbat[100], sortbowl2[100], sortbat2[100];
string name[100], region[100],  allround[100], sortbowlname[100], sortbatname[100];

int displayList()
{
    cout << "The list of players who have good enough batting and bowling average are:";
    for(i=0;i<=all;i++)
    {
         cout << allround[i];
    }
    cout << "The bowling average sorted is:\n";
    for(i=0;i<=all;i++)
    {
        cout << sortbowlname[i] << " : " << sortbowl2[i];
    }
    cout << "The batting average sorted is:\n";
    for(i=0;i<=all;i++)
    {
        cout << sortbatname[i] << " : " << sortbat2[i];
    }
}

int sortList()
{
    while(num<=all)
    {
        minibo=1000;
        minibat=1000;
        
        for(num;num<=all;num++)
        {
            if(min1>sortbowl[num])
            {
                minibo=num;
                min1=sortbowl[num];
            }
        }
        sortbowl2[num]=sortbowl[minibo];
        sortbowlname[num]=allround[minibo];
        
        for(num;num<=all;num++)
        {
            if(min2>sortbat[num])
            {
                minibat=num;
                min2=sortbat[num];
            }
        }
        sortbat2[num]=sortbat[minibat];
        sortbatname[num]=allround[minibat];
        min1=0;
        min2=0;
        num++;
    }
}

int generateList()
{
    num = 0;
    for(i=0;i<players;i++)
    {
        if(bat[i]>30 && bowl[i]<25)
        {
            allround[num]=name[i];
            sortbowl[num]=bowl[i];
            sortbat[num]=bat[i];
            num=num+1;
        }
        else
        {
            continue;
        }
    }
    all = num;
    num = 0;
}

int readData()
{
    
    cout << "Enter the player's name:  ";
    cin.ignore();
    getline(cin, name[i]);
        
    cout << "Enter the player's region:  ";
    cin.ignore();
    getline(cin, region[i]);
    
    cout << "Enter the batting average of the player:  ";
    cin >> bat[i];
        
    cout << "Enter the bowling average of the player:  ";
    cin >> bowl[i];
    
    return 0;
}

int main()
{
    cout << "Enter number of players:";
    cin >> players;
    
    for(i=0;i<players;++i)
    {
        readData();
    }
    generateList(); 
    sortList();
    sortList();
}