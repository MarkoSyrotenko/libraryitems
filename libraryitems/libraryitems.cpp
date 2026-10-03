/*
«адание: ЂЅиблиотечна€ системаї
“ребовани€
—оздай шаблонный класс LibraryItem<T = string, const int MAX_COPIES = 5>:
T Ч тип данных дл€ идентификатора книги (по умолчанию string, но можно использовать int).
MAX_COPIES Ч нетиповой аргумент шаблона, задающий максимальное количество экземпл€ров одной книги.
¬ классе должны быть:
ѕоле title Ч название книги.
ѕоле copies Ч массив или список экземпл€ров книги (размер ограничен MAX_COPIES).
—татическое поле totalItems Ч общее количество созданных объектов LibraryItem.
ћетоды:
addCopy(T id) Ч добавить экземпл€р книги по идентификатору.
removeCopy(T id) Ч удалить экземпл€р.
getCopiesCount() Ч вернуть количество доступных экземпл€ров.
—татический метод getTotalItems() Ч вернуть общее количество объектов в библиотеке.
книги идентифицируютс€ числами (например, внутренний ID);
ѕродумай, как статическое поле totalItems позволит отслеживать количество книг в библиотеке.
–аспиши сценарий использовани€:
—оздать три книги разных типов.
ƒобавить и удалить несколько экземпл€ров.
¬ывести общее количество книг в библиотеке.
*/
#include <iostream>
using namespace std;

template <class T = string, const int MAX_COPIES = 5>
class LibraryItem
{
    string title;
    T* copies;
    int count;
    static int totalItems;

public:
    LibraryItem(string t)
    {
        title = t;
        copies = new T[MAX_COPIES];
        totalItems++;
        count = 0;
    }
    ~LibraryItem()
    {
        delete[] copies;
        totalItems--;
    }
    void addCopy(T id)
    {
        if (count < MAX_COPIES)
        {
            copies[count] = id;
            count++;
        }
        cout << "added a copy\n";
    }
    void removeCopy(T id)
    {
        for (int i = 0; i < count; i++)
        {
            if (copies[i] == id)
            {
                count--;
                for (int j = i; j < count; j++)
                {
                    copies[j] = copies[j + 1];
                }
                break;
            }
        }
        cout << "removed a copy\n";
    }
    void getCopiesCount()
    {
        return count;
    }
    static int getTotalItems()
    {
        return totalItems;
    }

    void print()
    {
        cout << title << endl << count << " copies:\n";
        for (int i = 0; i < count; i++)
        {
            cout << copies[i] << endl;
        }
        cout << endl;
    }
};

template <class T, const int MAX_COPIES>
int LibraryItem<T, MAX_COPIES>::totalItems = 0;

int main()
{
    LibraryItem<int, 5> obj1("book1");
    LibraryItem<string, 10> obj2("book2");
    LibraryItem<char, 26> obj3("book3");
    obj1.addCopy(413);
    obj1.addCopy(612);
    obj2.addCopy("copy1");
    obj3.addCopy('a');
    obj3.addCopy('b');
    obj3.addCopy('c');
    obj3.removeCopy('b');
    obj1.print();
    obj2.print();
    obj3.print();
    cout << obj1.getTotalItems() << " total books (int)\n";
    cout << obj2.getTotalItems() << " total books (string)\n";
    cout << obj3.getTotalItems() << " total books (char)\n";
}