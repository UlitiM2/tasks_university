using System.Drawing;

public abstract class AutoBase
{
    public string Name { get; set; }
    public string Description { get; set; }
    public double CostBase { get; set; }
    public abstract double GetCost();
    public override string ToString()
    {
        string s = String.Format("Ваш автомобиль: \n{0} \nОписание: {1} \nСтоимость {2}\n",
        Name, Description, GetCost());
        return s;
    }
}
class Renault : AutoBase
{
    public Renault(string name, string info, double costbase)
    {
        Name = name;
        Description = info;
        CostBase = costbase;
    }
    public override double GetCost()
    {
        return CostBase * 1.18;
    }
}
class DecoratorOptions : AutoBase
{
    public AutoBase AutoProperty { protected get; set; }
    public string Title { get; set; }
    public string Color { get; set; }
    public string S { get; set; }
    public DecoratorOptions(AutoBase au, string tit, string c, string s)
    {
        AutoProperty = au;
        Title = tit;
        Color = c;
        S = s;
    }
    public override double GetCost()
    {
        return 0;
    }
}
class MediaNAV : DecoratorOptions
{
    public MediaNAV(AutoBase p, string t, string c, string s) : base(p, t, c, s)
    {
        AutoProperty = p;
        Name = p.Name + ". Современный";
        Description = p.Description + ". " + this.Title + ". Обновленная мультимедийная навигационная система";
    }
    public override double GetCost()
    {
        return AutoProperty.GetCost() + 15.99;
    }
}
class SystemSecurity : DecoratorOptions
{
    public SystemSecurity(AutoBase p, string t, string c, string s) : base(p, t, c, s)
    {
        AutoProperty = p;
        Name = p.Name + ". Повышенной безопасности";
        Description = p.Description + ". " + this.Title + ". Передние боковые подушки безопасности, ESP -система динамической стабилизации автомобиля";
    }
    public override double GetCost()
    {
        return AutoProperty.GetCost() + 20.99;
    }
}

class NewClass : DecoratorOptions
{
    public NewClass(AutoBase p, string t, string c, string s) : base(p, t, c, s)
    {
        AutoProperty = p;
        Name = p.Name + ". Повышенной безопасности";
        Description = p.Description + ". " + this.Title + ". Цвет - " + this.Color;
    }
    public override double GetCost()
    {
        return AutoProperty.GetCost() + 25.99;
    }
}
class Program
{
    static void Main(string[] args)
    {
        Renault reno = new Renault("Рено", "Renault LOGAN Active", 499.0);
        Print(reno);
        AutoBase myreno = new MediaNAV(reno, "Навигация", "Черный", "200");
        Print(myreno);
        AutoBase newmyReno = new SystemSecurity(new MediaNAV(reno, "Навигация", "Черный", "220"), "Безопасность", "Черный", "220");
        Print(newmyReno);

        AutoBase myreno1 = new MediaNAV(reno, "Навигация", "Черный", "200");
        Print(myreno1);
    }
    private static void Print(AutoBase av)
    {
        Console.WriteLine(av.ToString());
    }
}