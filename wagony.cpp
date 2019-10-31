//wagony aisd, dk 2019 

#include <iostream>

struct bocznicaW
{
    int numer;
    bocznicaW *next;
};

bocznicaW *head = nullptr;

void push(bocznicaW *&head, int nr);
void pop(bocznicaW *&head);

int top();
bool pusty();

int main()
{
    int ostatni = 1;
    int ile;
    int numer;

    std::cin >> ile;

    for(int i=0; i<ile; i++)
    {
        std::cin >> numer;
        push(head, numer);

        while(pusty()==0)
        {
            if(ostatni==top())
            {
                pop(head);
                ostatni++;
            }
            else
            {
                break;
            }
        }
    }

    if(ostatni-1 == ile)
    {
         std::cout << "TAK";
    }
    else
    {
          std::cout << "NIE";
    }
    return 0;
}

void push(bocznicaW *&head, int nr)
{
    bocznicaW *tmp;
    tmp = new bocznicaW;

    int numer = nr;

    tmp->numer = numer;
    tmp->next = head;
    head = tmp;
}

void pop(bocznicaW *&head)
{
    bocznicaW *tmp;
    tmp = head;

    if(tmp)
    {
        head = head->next;
        delete tmp;
    }
}

int top()
{
    return head->numer;
}

bool pusty()
{
    if(head == nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}