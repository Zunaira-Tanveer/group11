#include <iostream>
#include <fstream>
using namespace std;


// ABSTRACT CLASS

class WeatherDevice
{
public:
    virtual void displayData() = 0;
};
// ENCAPSULATION

class WeatherRecord : public WeatherDevice
{
private:
    string date;
    float temperature;
    float humidity;
    float windSpeed;

public:
    WeatherRecord()
    {
        date = "";
        temperature = 0;
        humidity = 0;
        windSpeed = 0;
    }

    WeatherRecord(string d, float t, float h, float w)
    {
        date = d;
        temperature = t;
        humidity = h;
        windSpeed = w;
    }

    // Setters
    void setDate(string d)
    {
        date = d;
    }

    void setTemperature(float t)
    {
        temperature = t;
    }

    void setHumidity(float h)
    {
        humidity = h;
    }

    void setWindSpeed(float w)
    {
        windSpeed = w;
    }

    // Getters
    string getDate()
    {
        return date;
    }

    float getTemperature()
    {
        return temperature;
    }

    float getHumidity()
    {
        return humidity;
    }

    float getWindSpeed()
    {
        return windSpeed;
    }

    // Dynamic Polymorphism
    void displayData() override
    {
        cout << "\nDate: " << date;
        cout << "\nTemperature: " << temperature << " C";
        cout << "\nHumidity: " << humidity << "%";
        cout << "\nWind Speed: " << windSpeed << " km/h\n";
    }
};


// INHERITANCE=
class AdvancedWeatherRecord : public WeatherRecord
{
private:
    float rainfall;

public:
    AdvancedWeatherRecord(string d, float t,
                          float h, float w,
                          float r)
        : WeatherRecord(d, t, h, w)
    {
        rainfall = r;
    }

    void displayData() override
    {
        WeatherRecord::displayData();
        cout << "Rainfall: " << rainfall << " mm\n";
    }
};
// STATIC POLYMORPHISM
// Function Overloading

class WeatherCalculator
{
public:
    float average(float a, float b)
    {
        return (a + b) / 2;
    }

    float average(float a, float b, float c)
    {
        return (a + b + c) / 3;
    }
};
// FILE HANDLING

class FileManager
{
public:
    static void saveToFile(WeatherRecord records[], int count)
    {
        ofstream file("weather.txt");

        if (!file)
        {
            cout << "File Error!\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            file << records[i].getDate() << " "
                 << records[i].getTemperature() << " "
                 << records[i].getHumidity() << " "
                 << records[i].getWindSpeed() << endl;
        }

        file.close();

        cout << "\nData Saved Successfully!\n";
    }

    static void loadFromFile()
    {
        ifstream file("weather.txt");

        if (!file)
        {
            cout << "File Not Found!\n";
            return;
        }

        string date;
        float temp, hum, wind;

        cout << "\n===== STORED RECORDS =====\n";

        while (file >> date >> temp >> hum >> wind)
        {
            cout << "\nDate: " << date;
            cout << "\nTemperature: " << temp << " C";
            cout << "\nHumidity: " << hum << "%";
            cout << "\nWind Speed: " << wind << " km/h\n";
        }

        file.close();
    }
};

// MAIN FUNCTION

int main()
{
    WeatherRecord records[100];
    int count = 0;

    int choice;

    do
    {
        cout << "\n\n====== WEATHER STATION ======\n";
        cout << "1. Add Weather Record\n";
        cout << "2. View Current Records\n";
        cout << "3. Save Records To File\n";
        cout << "4. Load Records From File\n";
        cout << "5. Demonstrate Polymorphism\n";
        cout << "6. Calculate Average Temperature\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            if(count >= 100)
            {
                cout << "\nStorage Full!\n";
                break;
            }

            string date;
            float temp, hum, wind;

            cout << "Enter Date: ";
            cin >> date;

            cout << "Enter Temperature: ";
            cin >> temp;

            cout << "Enter Humidity: ";
            cin >> hum;

            cout << "Enter Wind Speed: ";
            cin >> wind;

            records[count] = WeatherRecord(date, temp, hum, wind);
            count++;

            cout << "\nRecord Added Successfully!\n";
            break;
        }

        case 2:
        {
            if(count == 0)
            {
                cout << "\nNo Records Available!\n";
            }
            else
            {
                for(int i = 0; i < count; i++)
                {
                    records[i].displayData();
                }
            }
            break;
        }

        case 3:
        {
            FileManager::saveToFile(records, count);
            break;
        }

        case 4:
        {
            FileManager::loadFromFile();
            break;
        }

        case 5:
        {
            WeatherDevice* ptr;

            AdvancedWeatherRecord adv(
                "10-06-2026",
                35,
                70,
                15,
                20
            );

            ptr = &adv;

            cout << "\nDynamic Polymorphism Output:\n";
            ptr->displayData();

            break;
        }

        case 6:
        {
            WeatherCalculator calc;

            cout << "\nAverage of 30 and 40 = "
                 << calc.average(30, 40);

            cout << "\nAverage of 30, 40 and 50 = "
                 << calc.average(30, 40, 50);

            cout << endl;

            break;
        }

        case 0:
        {
            cout << "\nProgram Ended.\n";
            break;
        }

        default:
        {
            cout << "\nInvalid Choice!\n";
        }
        }

    } while(choice != 0);

    return 0;
}