#include "WeatherLibrary.h"

// WeatherRecord Constructors

WeatherRecord::WeatherRecord()
{
    date = "";
    temperature = 0;
    humidity = 0;
    windSpeed = 0;
}

WeatherRecord::WeatherRecord(string d, float t, float h, float w)
{
    date = d;
    temperature = t;
    humidity = h;
    windSpeed = w;
}

// Setters

void WeatherRecord::setDate(string d)
{
    date = d;
}

void WeatherRecord::setTemperature(float t)
{
    temperature = t;
}

void WeatherRecord::setHumidity(float h)
{
    humidity = h;
}

void WeatherRecord::setWindSpeed(float w)
{
    windSpeed = w;
}

// Getters

string WeatherRecord::getDate()
{
    return date;
}

float WeatherRecord::getTemperature()
{
    return temperature;
}

float WeatherRecord::getHumidity()
{
    return humidity;
}

float WeatherRecord::getWindSpeed()
{
    return windSpeed;
}

// Dynamic Polymorphism

void WeatherRecord::displayData()
{
    cout << "\nDate: " << date;
    cout << "\nTemperature: " << temperature << " C";
    cout << "\nHumidity: " << humidity << "%";
    cout << "\nWind Speed: " << windSpeed << " km/h\n";
}

// Inheritance

AdvancedWeatherRecord::AdvancedWeatherRecord(
    string d,
    float t,
    float h,
    float w,
    float r)
        : WeatherRecord(d, t, h, w)
{
    rainfall = r;
}

void AdvancedWeatherRecord::displayData()
{
    WeatherRecord::displayData();
    cout << "Rainfall: " << rainfall << " mm\n";
}

// Static Polymorphism

float WeatherCalculator::average(float a, float b)
{
    return (a + b) / 2;
}

float WeatherCalculator::average(float a, float b, float c)
{
    return (a + b + c) / 3;
}

// File Handling

void FileManager::saveToFile(
    WeatherRecord records[],
    int count)
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

void FileManager::loadFromFile()
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