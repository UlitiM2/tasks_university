abstract class StrategySort
{
    public string Title { get; set; }
    public abstract void Sort(int[] array);
}
class InsertionSort : StrategySort
{
    public InsertionSort()
    {
        Title = "Сортировка вставками";
    }
    public override string ToString()
    {
        return Title;
    }
    public override void Sort(int[] array)
    {
        for (int i = 1; i < array.Length; i++)
        {
            int j = 0;
            int buffer = array[i];
            for (j = i - 1; j >= 0; j--)
            {
                if (array[j] < buffer)
                    break;
                array[j + 1] = array[j];
            }
            array[j + 1] = buffer;
        }
    }
}
class SelectionSort : StrategySort

{
    public SelectionSort()
    {
        Title = "Сортировка выбором";
    }
    public override string ToString()
    {
        return Title;
    }
    public override void Sort(int[] array)
    {
        for (int i = 0; i < array.Length - 1; i++)
        {
            int k = i;
            for (int j = i + 1; j < array.Length; j++)
                if (array[k] > array[j])
                    k = j;
            if (k != i)
            {
                int temp = array[k];
                array[k] = array[i];
                array[i] = temp;
            }
        }
    }
}



class BubbleSort : StrategySort
{
    public BubbleSort()
    {
        Title = "Сортировка пузырковая";
    }
    public override string ToString()
    {
        return Title;
    }
    static void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    public override void Sort(int[] array)
    {
        int n = array.Length;
        bool swapped;

        // Проходим по всему массиву
        for (int i = 0; i < n - 1; i++)
        {
            swapped = false;

            // Последние i элементов уже на своем месте
            for (int j = 0; j < n - i - 1; j++)
            {
                // Сравниваем соседние элементы
                if (array[j] > array[j + 1])
                {
                    // Меняем местами, если первый больше второго
                    Swap(ref array[j], ref array[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }



    class Context
    {
        StrategySort strategy;
        int[] array;
        public Context(StrategySort strategy, int[] array)
        {
            this.strategy = strategy;
            this.array = array;
        }
        public void Sort()
        {
            strategy.Sort(array);
        }
        public void PrintArray()
        {
            Console.WriteLine(strategy.ToString());
            for (int i = 0; i < array.Length; i++)
                Console.Write(array[i] + " ");
            Console.WriteLine();
        }
    }
    class Program
    {
        static void Main()
        {
            int[] arr1 = { 31, 15, 10, 2, 4, 2, 14, 23, 12, 66 };
            StrategySort sort = new SelectionSort();
            Context context = new Context(sort, arr1);
            context.Sort();
            context.PrintArray();
            int[] arr2 = { 1, 5, 10, 2, 4, 12, 14, 23, 12, 66 };
            sort = new InsertionSort();
            context = new Context(sort, arr2);
            context.Sort();
            context.PrintArray();
            int[] arr3 = { 1, 5, 10, 2, 4, 12, 14, 23, 12, 66 };
            sort = new BubbleSort();
            context = new Context(sort, arr3);
            context.Sort();
            context.PrintArray();
        }
    }
}  