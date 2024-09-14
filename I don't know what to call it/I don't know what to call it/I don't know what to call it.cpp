#include <iostream>
#include <complex>
using namespace std;

namespace Math
{
    // Класс Дробь
    class Fraction
    {
    public:
        int numerator;
        int denominator;

        Fraction(int numerator = 0, int denominator = 1)
        {
            if (denominator == 0)
            {
                throw invalid_argument("Знаменатель дроби не может быть равен нулю.");
            }
            this->numerator = numerator;
            this->denominator = denominator;
        }

        // Метод для вывода дроби
        void print() const
        {
            cout << numerator << "/" << denominator << endl;
        }
    };

    // Класс Комплексное число
    class Complex : public complex<double>
    {
    public:
        Complex(double real = 0, double imag = 0) : complex<double>(real, imag) {}

        // Переопределение оператора вывода для комплексного числа
        friend ostream& operator<<(ostream& os, const Complex& c)
        {
            os << c.real() << (c.imag() >= 0 ? "+" : "") << c.imag() << "i";
            return os;
        }
    };

    // Класс Точка в двумерном пространстве
    class Point2D
    {
    public:
        double x;
        double y;

        Point2D(double x = 0, double y = 0) : x(x), y(y) {}

        void print() const
        {
            cout << "Точка в двумерном пространстве:" << "(" << x << ", " << y << ")" << std::endl;
        }
    };

    // Класс Точка в трехмерном пространстве
    class Point3D
    {
    public:
        double x;
        double y;
        double z;

        Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

        // Метод для вывода точки
        void print() const
        {
            cout << "Точка в трехмерном пространстве:" << "(" << x << ", " << y << ", " << z << ")" << endl;
        }
    };
}

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        Math::Fraction fraction(3, 4);
        fraction.print();

        // Тестирование комплексного числа
        Math::Complex complex(2.0, -1.5);
        cout << "Комплексное число: " << complex << endl;

        // Тестирование точки в двумерном пространстве
        Math::Point2D point2D(2.5, 1.0);
        point2D.print();

        // Тестирование точки в трехмерном пространстве
        Math::Point3D point3D(1.0, 2.0, 3.0);
        point3D.print();

    }
    catch (const exception& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
