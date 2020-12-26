#include <vector>

template <typename T>
void dupliceer(vector<unique_ptr<T>> &v, int);

int main() {
    unique_ptr<string> namen[] = {make_unique("Rein"),
                                  make_unique<string>("Ada"),
                                  make_unique("Eppo"),
                                  make_unique<string>("Pascal"),
                                  make_unique("Ilse")};
    vector<unique_ptr<string>> namenvector;

    ... //voeg de unieke pointers van namen toe aan namenvector
    dupliceer(namenvector,3);
    ... //print de inhoud van namenvector
    //output moet zijn: Rein Rein Rein Ada Ada Ada Eppo Eppo Eppo Pascal Pascal Pascal Ilse Ilse Ilse
}

void dupliceer(vector)