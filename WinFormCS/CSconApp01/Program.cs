using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSconApp01
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("int type의 크기" + sizeof(int) + "(byte) 범위 " + int.MinValue + " ~ " + int.MaxValue); // static Library
            Console.WriteLine("long type의 크기" + sizeof(long) + "(byte) 범위 " + long.MinValue + " ~ " + long.MaxValue); // static Library
            Console.WriteLine("float type의 크기" + sizeof(float) + "(byte) 범위 " + float.MinValue + " ~ " + float.MaxValue); // static Library
            Console.WriteLine("double type의 크기" + sizeof(double) + "(byte) 범위 " + double.MinValue + " ~ " + double.MaxValue); // static Library
            Console.WriteLine("char type의 크기" + sizeof(char) + "(byte) 범위 " + char.MinValue + " ~ " + char.MaxValue); // static Library

            Char a = 'A';
            Console.WriteLine("Char a = " + a);
            Console.WriteLine("Char a+1 = " + (a+1));
            Console.WriteLine("Char a+2 = " + (a+2));

            Console.ReadKey();
        }
    }
}
