using System;

abstract class DataProcessor()
{
    public void ProcessData()
    {
        LoadData();
        TransformData();
        AnalyzeData();
        SaveResults();
    }

    protected virtual void LoadData()
    {
        Console.WriteLine("Загрузка данных");
    }

    protected abstract void TransformData();

    protected abstract void AnalyzeData();

    protected virtual void SaveResults()
    {
        Console.WriteLine("Сохранение результатов");
    }
}

class NumericDataProcessor : DataProcessor
{
    protected override void TransformData()
    {
        Console.WriteLine("Преобразование числовых данных");
    }

    protected override void AnalyzeData()
    {
        Console.WriteLine("Анализ числовых данных");
    }
}

class TextDataProcessor : DataProcessor
{
    protected override void TransformData()
    {
        Console.WriteLine("Преобразование текстовых данных");
    }

    protected override void AnalyzeData()
    {
        Console.WriteLine("Анализ текстовых данных");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Использование числовой обработки данных
        DataProcessor numericProcessor = new NumericDataProcessor();
        numericProcessor.ProcessData();

        Console.WriteLine("\n\n");

        // Использование текстовой обработки данных
        DataProcessor textProcessor = new TextDataProcessor();
        textProcessor.ProcessData();
    }
}
