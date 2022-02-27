#include <iostream>
#include <set>
#include <locale>

using namespace std;

const int maxSize = 10;

struct Queue
{
    int First, Last, Count;
    int Array[maxSize];
};

void InitQueue(Queue* q) // Инициализация очереди
{
    q->Count = 0; q->First = 0; q->Last = 0;
}

int CheckedInput(int begin, int end) // Ввод целочисленного значения с проверкой интервала
{
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Вводите данные корректно: ";
            continue;
        }
        cin.ignore(32767, '\n');
        if (choice < begin || choice > end)
        {
            cout << "Вводите данные корректно: ";
            continue;
        }
        break;
    }
    return choice;
}

int CheckedInput() // Ввод целочисленного значения с проверкой
{
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Вводите данные корректно: ";
            continue;
        }
        cin.ignore(32767, '\n');
        break;
    }
    return choice;
}

bool isEmpty(Queue* q) // Проверка очереди на пустоту
{
    if (q->Count == 0)
    {
        return true;
    }
    return false;
}

bool isFull(Queue* q) // Проверка очереди на заполненность
{
    if (q->Count == maxSize)
    {
        return true;
    }
    return false;
}

void Delete(Queue* q) // Удаление элемента из начала очереди
{
    if (isEmpty(q))
    {
        cout << "Очередь пустая";
    }
    else
    {
        q->Array[q->First] = 0;
        q->Count --;
        q->First ++;
        if (q->First == maxSize)
        {
            q->First = 0;
        }

    }
}

void Add(Queue* q, int number) // Добавление элемента в конец очереди 
{
    if (isFull(q))
    {
        cout << "Очередь заполнена";
    }
    else
    {
        q->Array[q->Last] = number;
        q->Count++;
        q->Last++;
        if (q->Last == maxSize)
        {
            q->Last = 0;
        }

    }
}

void PrintQueue(Queue* q) // Вывод текущего состояния очереди
{
    if (isEmpty(q))
    {
        cout << "Очередь пуста";
    }
    else
    {
        int current = q->First;
        cout << "Очередь: ";
        do
        {
            cout << q->Array[current] << " ";
            current++;
            if (current == maxSize)
            {
                current = 0;
            }
        } while (current != q->Last); // т.к. Last указывает на след. ячейку после последнего элемента  
    }
}

void CallMenu(Queue* q) // Основное меню
{
    bool work{ true };
    while (work)
    {
        cout << "Выберите действие:\n1 - Проверка пустоты очереди\n2 - Проверка заполненности очереди\n3 - Добавить элемент в конец очереди\n";
        cout << "4 - Удалить элемент из начала очереди\n5 - Вывод очереди\n6 - Завершение работы\n";
        cout << "Введите номер действия: ";
        int choice = CheckedInput(1, 6);
        switch (choice)
        {
        case 1:
            if (isEmpty(q))
            {
                cout << "Очередь пуста";
            }
            else
            {
                cout << "Очередь не пуста";
            }
            cout << "\n\n";
            break;
        case 2:
            if (isFull(q))
            {
                cout << "Очередь полна";
            }
            else
            {
                cout << "Очередь не полна";
            }
            cout << "\n\n";
            break;
        case 3:
            if (isFull(q))
            {
                cout << "Стек полон\n\n"; break;
            }
            cout << "Какое число хотите ввести в очередь?: ";
            Add(q,CheckedInput());
            cout << "\n\n";
            break;
        case 4:
            Delete(q);
            cout << "\n\n";
            break;
        case 5:
            PrintQueue(q);
            cout << "\n\n";
            break;
        case 6:
            work = false;
            cout << "\n\n";
            break;
        default:
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");
    Queue* q = new Queue;
    InitQueue(q);
    CallMenu(q);
    delete q;
}

