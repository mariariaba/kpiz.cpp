#include <iostream>
#include <deque>
#include <string>

using namespace std;

class Product {
public:
    string name;
    string manufacturer;

    Product(const string& name, const string& manufacturer)
        : name(name), manufacturer(manufacturer) {}
};
ostream& operator<<(ostream& os, const Product& product) {
    setlocale(LC_CTYPE, "ukr");
    os << "Назва товару: " << product.name << ", Виробник: " << product.manufacturer;
    return os;
}

void printDeque(const deque<Product>& deque) {
    for (const auto& product : deque) {
        cout << product << endl;
    }
    setlocale(LC_CTYPE, "ukr");
    cout << "Всього продуктiв: " << deque.size() << endl;
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    deque<Product> products;

    products.emplace_back("Ноутбук", "Dell");
    products.emplace_back("Смартфон", "Samsung");
    products.emplace_front("Планшет", "Apple");

    cout << "Початковий дек:" << endl;
    printDeque(products);

    products.pop_front();
    cout << "\nПiсля pop_front:" << endl;
    printDeque(products);

    products.pop_back();
    cout << "\nПiсля pop_back:" << endl;
    printDeque(products);

    products.emplace_front("Навушники", "Sony");
    products.emplace_back("Монiтор", "LG");

    cout << "\nПiсля додавання нового товару: " << endl;
    printDeque(products);

    cout << "\nПерший товар: " << products.front() << endl;
    cout << "Останнiй товар: " << products.back() << endl;

    auto it = products.begin() + 1; 
    products.emplace(it, "Камера", "Canon");

    cout << "\nПiсля розмiщення в центрi:" << endl;
    printDeque(products);

    return 0;
}
