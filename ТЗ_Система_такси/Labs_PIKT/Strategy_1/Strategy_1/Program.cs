
public interface IRouteStrategy
{
    void CalculateRoute(string startPoint, string endPoint);
}

public class CarRouteStrategy : IRouteStrategy
{
    public void CalculateRoute(string startPoint, string endPoint)
    {
        // Логика прокладки маршрута по автодорогам
        Console.WriteLine($"Прокладываю маршрут на автомобиле от {startPoint} до {endPoint}.");
    }
}

public class WalkingRouteStrategy : IRouteStrategy
{
    public void CalculateRoute(string startPoint, string endPoint)
    {
        // Логика прокладки пешего маршрута
        Console.WriteLine($"Прокладываю пеший маршрут от {startPoint} до {endPoint}.");
    }
}

public class BikingRouteStrategy : IRouteStrategy
{
    public void CalculateRoute(string startPoint, string endPoint)
    {
        // Логика прокладки маршрута по велодорожкам
        Console.WriteLine($"Прокладываю маршрут на велосипеде от {startPoint} до {endPoint}.");
    }
}

public class PublicTransportRouteStrategy : IRouteStrategy
{
    public void CalculateRoute(string startPoint, string endPoint)
    {
        // Логика прокладки маршрута на общественном транспорте
        Console.WriteLine($"Прокладываю маршрут на общественном транспорте от {startPoint} до {endPoint}.");
    }
}

public class SightseeingRouteStrategy : IRouteStrategy
{
    public void CalculateRoute(string startPoint, string endPoint)
    {
        // Логика прокладки маршрута по достопримечательностям
        Console.WriteLine($"Прокладываю маршрут для посещения достопримечательностей от {startPoint} до {endPoint}.");
    }
}

public class NavigationContext
{
    private IRouteStrategy _routeStrategy;

    public void SetRouteStrategy(IRouteStrategy routeStrategy)
    {
        _routeStrategy = routeStrategy;
    }

    public void ShowRoute(string startPoint, string endPoint)
    {
        _routeStrategy.CalculateRoute(startPoint, endPoint);
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        NavigationContext navigationContext = new NavigationContext();

        navigationContext.SetRouteStrategy(new CarRouteStrategy());
        navigationContext.ShowRoute("Начальная точка", "Конечная точка");

        navigationContext.SetRouteStrategy(new WalkingRouteStrategy());
        navigationContext.ShowRoute("Начальная точка", "Конечная точка");

        navigationContext.SetRouteStrategy(new BikingRouteStrategy());
        navigationContext.ShowRoute("Начальная точка", "Конечная точка");

        navigationContext.SetRouteStrategy(new PublicTransportRouteStrategy());
        navigationContext.ShowRoute("Начальная точка", "Конечная точка");

        navigationContext.SetRouteStrategy(new SightseeingRouteStrategy());
        navigationContext.ShowRoute("Начальная точка", "Конечная точка");
    }
}