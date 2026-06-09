#include "WeatherLibrary.h"

int main()
{
    WeatherRecord records[100];
    int count=0;

    int choice;

    do
    {
        cout<<"\n\n====== WEATHER STATION ======\n";
        cout<<"1. Add Weather Record\n";
        cout<<"2. View Current Records\n";
        cout<<"3. Save Records To File\n";
        cout<<"4. Load Records From File\n";
        cout<<"5. Demonstrate Polymorphism\n";
        cout<<"6. Calculate Average Temperature\n";
        cout<<"0. Exit\n";

        cout<<"\nEnter Choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
        {
            string date;
            float temp,hum,wind;

            cout<<"Enter Date: ";
            cin>>date;

            cout<<"Enter Temperature: ";
            cin>>temp;

            cout<<"Enter Humidity: ";
            cin>>hum;

            cout<<"Enter Wind Speed: ";
            cin>>wind;

            records[count]=WeatherRecord(
                date,temp,hum,wind);

            count++;

            cout<<"\nRecord Added Successfully!\n";
            break;
        }

        case 2:
        {
            for(int i=0;i<count;i++)
            {
                records[i].displayData();
            }
            break;
        }

        case 3:
            FileManager::saveToFile(records,count);
            break;

        case 4:
            FileManager::loadFromFile();
            break;

        case 5:
        {
            WeatherDevice* ptr;

            AdvancedWeatherRecord adv(
                "10-06-2026",
                35,
                70,
                15,
                20);

            ptr=&adv;

            ptr->displayData();

            break;
        }

        case 6:
        {
            WeatherCalculator calc;

            cout<<"\nAverage of 30 and 40 = "
                <<calc.average(30,40);

            cout<<"\nAverage of 30,40,50 = "
                <<calc.average(30,40,50);

            break;
        }
        }

    }while(choice!=0);

    return 0;
}