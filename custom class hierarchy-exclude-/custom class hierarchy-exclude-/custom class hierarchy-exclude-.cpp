#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
using namespace std;

class AssignmentException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Ошибка в задании";
    }
};

class MathException : public AssignmentException
{
public:
    virtual const char* what() const throw()
    {
        return "Ошибка в математических вычислениях";
    }
};

class DivisionByZeroException : public MathException
{
public:
    virtual const char* what() const throw()
    {
        return "Деление на ноль";
    }
};

class InvalidInputException : public MathException
{
public:
    virtual const char* what() const throw()
    {
        return "Некорректный ввод данных";
    }
};

class FileException : public AssignmentException
{
public:
    virtual const char* what() const throw()
    {
        return "Ошибка при работе с файлом";
    }
};

class FileNotFoundException : public FileException
{
public:
    virtual const char* what() const throw()
    {
        return "Файл не найден";
    }
};

class FileReadException : public FileException
{
public:
    virtual const char* what() const throw()
    {
        return "Ошибка чтения из файла";
    }
};

class FileWriteException : public FileException
{
public:
    virtual const char* what() const throw()
    {
        return "Ошибка записи в файл";
    }
};

class MemoryException : public AssignmentException
{
public:
    virtual const char* what() const throw()
    {
        return "Нехватка памяти";
    }
};


int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        int a = 10;
        int b = 0;
        if (b == 0)
        {
            throw DivisionByZeroException();
        }
        int result = a / b;

        ifstream file("nonexistent_file.txt");
        if (!file.is_open())
        {
            throw FileNotFoundException();
        }
        string line;
        getline(file, line);
    }
    catch (const DivisionByZeroException& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }
    catch (const FileNotFoundException& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }
    catch (const FileReadException& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }
    catch (const MemoryException& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }
    catch (const AssignmentException& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
