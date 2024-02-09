#include <iostream>
using namespace std;

void gender ()
{
    int gendeR;
    cout<<endl<<endl<<"Are you male or female:"<<endl;
    cout<<"1. for male:"<<endl;
    cout<<"2. for female: ";
    cin>>gendeR;
    if(gendeR == 1)
    {
        cout<<endl<<endl<<"Go on right side";
    }
    else if (gendeR == 2)
    {
        cout<<endl<<endl<<"Go on left side";
    }
    else
    {
        gender();
    }
}

void priceCheck (int token_price)
{
    int price;
    cout<<"Enter price for token: ";
    cin>>price;
    if (token_price == price)
    {
        gender();
    }
    else if(price > token_price)
    {
        cout<<endl<<endl<<"Your amount is greater:"<<endl<<"please take this amount: ";
        price = price - token_price;
        cout<<price;
        gender();
    }
    else if (price < token_price)
    {
        cout<<endl<<endl<<"Your amount is lower:"<<endl<<"please again enter\n";
        priceCheck(token_price);
    }
}

int tickets (int token)
{
            if(token <=4)
    		{
    			token = 20;
    		}
    		else if (token >4 && token <= 8)
    		{
    			token = 25;
    		}
    		else if (token >8 && token <= 12)
    		{
    			token = 30;
    		}
    		else if (token >12 && token <= 16)
    		{
    			token = 35;
    		}
    		else if (token >16 )
    		{
    			token = 40;
    		}
    		cout<<endl<<endl;
    	cout<<"You are ticket price is "<<token<<endl;
        return token;
}

int destination (int current_location,string station[],int size)
{
    int station_count=0,destination_station, token_price=0,tokens;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"where you want to go? Enter station number: "<<endl<<endl<<endl;
    for (int i =0; i <size;i++)
    {
        if (i==current_location-1)
        {
            cout << station[current_location-1] << " (You are here now)*"<< endl;
        }
        else{
        cout<<station[i]<<endl;
        }
    }
    cout<<endl;
     cin>>destination_station;
     if (destination_station == current_location)
     {
     	cout<<endl<<endl;
     	cout<<"You enter same station number for destination and current station"<<endl;
     	destination(current_location,station,26);
     }
     else if (destination_station <27 && destination_station > 0)
     {
    if (destination_station>current_location)
    {
    	for (int i=current_location-1;i<destination_station-1;i++)
    	{
    		station_count++;
    	}
    }
    	else if (destination_station<current_location)
    {
    	for (int i=current_location-1;i >destination_station;i--)
    	{
    		station_count++;
    	}
    }
        token_price = tickets(station_count);
    	cout<<"How many token do you want: "<<endl;
    	cin>>tokens;
        token_price = token_price *tokens;
        cout<<endl<<endl<<"Ticket price for "<<tokens<<" is "<<token_price<<endl;
        priceCheck(token_price);
     }
     else
     {
     	cout<<endl<<endl;
     	cout <<"Invalid choice"<<endl;
    	destination(current_location,station,26);
     }
     return station_count;
}

int manu ()
{
    int current_location,station_count;
    string station[26]={"Station  1: DERA GUJJRAN","Station  2: ISLAM PARK","Station  3: SALAMAT PURA","Station  4: MEHMOOD BOOTI","Station  5: PAKISTAN MINT","Station  6: SHALAMAR GARDEN","Station  7: BAGHBANPURA","Station  8: UET","Station  9: SULTANPURA","Station 10: RAILWAY STATION","Station 11: LAKSHMI","Station 12: G.P.O.","Station 13: ANARKALI","Station 14: CHAUBURJI","Station 15: GULSHAN-E-RAVI","Station 16: SAMANABAD","Station 17: BAND ROAD","Station 18: SALAHUDIN ROAD","Station 19: KHATAM-E-NABUWAT","Station 20: SABZAZAR","Station 21: AWAN TOWN","Station 22: WAHDAT ROAD","Station 23: HANJARWAL","Station 24: CANAL VIEW","Station 25: THOKAR NIAZBAIG","Station 26: ALI TOWN",};
    cout<<"Enter your current station number: "<<endl<<endl<<endl;
    for (int i = 0;i<26;i++)
    {
        cout<<station[i]<<endl;
    }
    cout<<endl;
    cin>>current_location;
    if (current_location <27 && current_location > 0)
    {
       station_count =  destination(current_location,station,26);
    }
    else 
    {
    	cout<<endl<<endl;
    	cout <<"Invalid choice"<<endl;
        manu();
    }
    return station_count;
}

int token_place ()
{
    int station_count;
    char token;
cout<<"Do you want to get token from machine or by cabin? "<<endl;
    cout<<"Enter 'm' for Machine  & 't' for Ticket Cabin: ";
    cin>>token;
    cout<<endl<<endl;
    if(token == 'm' || token == 'M')
    {
      station_count = manu();
    }
    else if (token == 't' || token == 'T')
    {
      station_count = manu();
    }
    else
    {
        cout<<endl<<endl<<endl<<"\t\tinvalid choice"<<endl;
        token_place();
    }
    return station_count;
}

int main ()
{
    int time, minutes,station_count;
    cout<<"\t\tWELCOME TO ORANGE LINE TRAIN"<<endl;
    station_count = token_place();
    cout<<endl<<endl<<"Now time"<<endl;
    cout<<__TIME__<<endl;
    minutes = atoi(&__TIME__[3]);
    time = 5- minutes % 5 ;
    if (time == 5)
    {
        cout<<endl<<endl<<"Train is arrived"<<endl;
    }
    else if (time != 5)
    {
       cout<<endl<<endl<<time<<" Minutes are left:"<<endl;
    }
    station_count *= 2;
    cout<<endl<<endl<<"Time required for destination: "<<station_count<<" Minutes"<<endl;
    cout<<endl<<endl<<"THANK YOU FOR USING OUR SERVICE"<<endl;
}