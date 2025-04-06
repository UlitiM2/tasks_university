using System;
public class TemperatureSensor
{
    public double GetTemperatureInFahrenheit()
    {
        Random rnd = new Random();
        double val = rnd.Next(0,100);
        return val; 
    }
}
// Интерфейс адаптера
public interface ITemperatureAdapter
{
    double GetTemperatureInCelsius();
}

// Адаптер для преобразования температуры из Фаренгейта в Цельсия
public class FahrenheitToCelsiusAdapter : ITemperatureAdapter
{
    private readonly TemperatureSensor _sensor;

    public FahrenheitToCelsiusAdapter(TemperatureSensor sensor)
    {
        _sensor = sensor;
    }

    public double GetTemperatureInCelsius()
    {
        double fahrenheit = _sensor.GetTemperatureInFahrenheit();
        Console.WriteLine("Температура в Фаренгейтах: {0} F", fahrenheit);
        return (fahrenheit - 32) * 5 / 9;
    }
}

// Класс климат-контроля
public class ClimateControlSystem
{
    private readonly ITemperatureAdapter _temperatureAdapter;
    public ClimateControlSystem(ITemperatureAdapter temperatureAdapter)
    {
        _temperatureAdapter = temperatureAdapter;
    }
    public void MonitorTemperature()
    {
        double temperatureInCelsius = _temperatureAdapter.GetTemperatureInCelsius();
        System.Console.WriteLine($"Текущая температура в Цельсиях: {temperatureInCelsius:F2} °C");
    }
}
public class Program
{
    public static void Main(string[] args)
    {
        TemperatureSensor sensor = new TemperatureSensor();
        ITemperatureAdapter adapter = new FahrenheitToCelsiusAdapter(sensor);
        ClimateControlSystem climateControlSystem = new ClimateControlSystem(adapter);
        climateControlSystem.MonitorTemperature();
    }
}