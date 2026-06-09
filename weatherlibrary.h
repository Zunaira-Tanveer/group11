
#ifndef OOPPROJECT_WEATHERLIBRARY_H
#define OOPPROJECT_WEATHERLIBRARY_H
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
    WeatherRecord();
    WeatherRecord(string d, float t, float h, float w);

    void setDate(string d);
    void setTemperature(float t);
    void setHumidity(float h);
    void setWindSpeed(float w);

    string getDate();
    float getTemperature();
    float getHumidity();
    float getWindSpeed();

    void displayData() override;
};

class AdvancedWeatherRecord : public WeatherRecord
{
private:
    float rainfall;

public:
    AdvancedWeatherRecord(string d,float t,float h,float w,float r);

    void displayData() override;
};

class WeatherCalculator
{
public:
    float average(float a,float b);
    float average(float a,float b,float c);
};

class FileManager
{
public:
    static void saveToFile(WeatherRecord records[], int count);
    static void loadFromFile();
};

#endif //OOPPROJECT_WEATHERLIBRARY_H