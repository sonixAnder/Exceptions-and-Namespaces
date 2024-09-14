#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node* prev;
    Node* next;

    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList()
    {
        clear();
    }

    // Вставка в начало списка
    void push_front(const T& data)
    {
        try
        {
            Node<T>* newNode = new Node<T>(data);
            if (newNode == nullptr)
            {
                throw bad_alloc(); // Исключение нехватки памяти
            }
            if (head == nullptr)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
        }
        catch (const bad_alloc& e)
        {
            cerr << "Ошибка: Не удалось выделить память: " << e.what() << endl;
        }
    }

    // Вставка в конец списка
    void push_back(const T& data)
    {
        try
        {
            Node<T>* newNode = new Node<T>(data);
            if (newNode == nullptr)
            {
                throw bad_alloc(); // Исключение нехватки памяти
            }
            if (tail == nullptr)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }
        catch (const bad_alloc& e)
        {
            cerr << "Ошибка: Не удалось выделить память: " << e.what() << endl;
        }
    }

    // Удаление из начала списка
    void pop_front()
    {
        if (head == nullptr)
        {
            throw out_of_range("Список пуст"); // Исключение попытки удаления из пустого списка
        }
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr; // Если удален единственный элемент
        }
        delete temp;
        size--;
    }

    // Удаление из конца списка
    void pop_back()
    {
        if (tail == nullptr)
        {
            throw out_of_range("Список пуст"); // Исключение попытки удаления из пустого списка
        }
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr; // Если удален единственный элемент
        }
        delete temp;
        size--;
    }

    // Очистка списка
    void clear()
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // Получение размера списка
    int getSize() const
    {
        return size;
    }

    // Проверка на пустоту
    bool isEmpty() const
    {
        return size == 0;
    }

    // Вывод списка
    void print() const
    {
        if (isEmpty())
        {
            cout << "Список пуст" << endl;
            return;
        }
        Node<T>* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    DoublyLinkedList<int> list;
    try
    {
        list.push_front(1);
        list.push_front(2);
        list.push_back(3);
        list.push_back(4);
        std::cout << "Список:" << std::endl;
        list.print();

        list.pop_front(); // Удалить из начала
        cout << "После удаления из начала:" << endl;
        list.print();

        list.pop_back(); // Удалить из конца
        cout << "После удаления из конца:" << endl;
        list.print();

        list.pop_front(); // Удалить из начала
        list.pop_front(); // Удалить из начала
        list.pop_front(); // Удалить из начала
        cout << "После удаления всех элементов:" << endl;
        list.print(); // Попытка вывода пустого списка

        list.pop_front(); // Попытка удаления из пустого списка
    }
    catch (const out_of_range& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }
    catch (const bad_alloc& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
