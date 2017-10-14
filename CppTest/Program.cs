using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CppTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Calculate calc = new Calculate();

            Console.WriteLine(calc.Add(10, 20));
            Console.WriteLine(calc.Sub(10, 20));
            Console.WriteLine(calc.Mul(10, 20));
            Console.WriteLine(calc.Div(10, 20));

            calc.RegisterCallback(new Calculate.Callback(Callback));

            calc.Dispose();
            calc.Dispose();

            Console.ReadKey();
        }

        static void Callback(int a, int b, int c, int d)
        {
            Console.WriteLine($"{a} {b} {c} {d}");
        }
    }
}
