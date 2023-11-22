#include <iostream>
#include <cmath>
using namespace std;

// singly circular linked list
struct node
{
    int cf, px, py, pz;
    int flag;
    struct node *link;
};

typedef struct node NODE;

NODE *getnode()
{
    NODE *x;
    x = new NODE;
    if (x == NULL)
    {
        cout << "Insufficient memory\n";
        exit(0);
    }
    return x;
}

void display(NODE *head)
{
    NODE *temp;
    if (head->link == head)
    {
        cout << "Polynomial does not exist\n";
        return;
    }
    temp = head->link;
    cout << "\n";
    while (temp != head)
    {
        cout << temp->cf << "x^" << temp->px << "y^" << temp->py << "z^" << temp->pz;
        if (temp->link != head)
            cout << " + ";
        temp = temp->link;
    }
    cout << "\n";
}

NODE *insert_rear(int cf, int x, int y, int z, NODE *head)
{
    NODE *temp, *cur;
    temp = getnode();
    temp->cf = cf;
    temp->px = x;
    temp->py = y;
    temp->pz = z;
    cur = head->link;
    while (cur->link != head)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE *read_poly(NODE *head)
{
    int px, py, pz, cf, ch;
    cout << "\nEnter coeff: ";
    cin >> cf;
    cout << "\nEnter x, y, z powers (0-indicate NO term): ";
    cin >> px >> py >> pz;
    head = insert_rear(cf, px, py, pz, head);
    cout << "\nIf you wish to continue press 1 otherwise 0: ";
    cin >> ch;
    while (ch != 0)
    {
        cout << "\nEnter coeff: ";
        cin >> cf;
        cout << "\nEnter x, y, z powers (0-indicate NO term): ";
        cin >> px >> py >> pz;
        head = insert_rear(cf, px, py, pz, head);
        cout << "\nIf you wish to continue press 1 otherwise 0: ";
        cin >> ch;
    }
    return head;
}

NODE *add_poly(NODE *h4, NODE *h2, NODE *h3)
{
    NODE *p1, *p2;
    int x1, x2, y1, y2, z1, z2, cf1, cf2, cf;
    p1 = h4->link;
    while (p1 != h4)
    {
        x1 = p1->px;
        y1 = p1->py;
        z1 = p1->pz;
        cf1 = p1->cf;
        p2 = h2->link;
        while (p2 != h2)
        {
            x2 = p2->px;
            y2 = p2->py;
            z2 = p2->pz;
            cf2 = p2->cf;
            if (x1 == x2 && y1 == y2 && z1 == z2)
                break;
            p2 = p2->link;
        }
        if (p2 != h2)
        {
        }
        else
        {
            cf = cf1 + cf2;
            p2->flag = 1;
            if (cf != 0)
                h3 = insert_rear(cf, x1, y1, z1, h3);
            h3 = insert_rear(cf1, x1, y1, z1, h3);
        }
        p1 = p1->link;
        p2 = h2->link;
        while (p2 != h2)
        {
            if (p2->flag == 0)
                h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
            p2 = p2->link;
        }
    }
    return h3;
}

void evaluate(NODE *h1)
{
    NODE *head;
    int x, y, z;
    float result = 0.0;
    head = h1;
    cout << "\nEnter x, y, z, terms to evaluate:\n";
    cin >> x >> y >> z;
    while (h1->link != head)
    {
        result = result + (h1->cf * pow(x, h1->px) * pow(y, h1->py) * pow(z, h1->pz));
        h1 = h1->link;
    }
    result = result + (h1->cf * pow(x, h1->px) * pow(y, h1->py) * pow(z, h1->pz));
    cout << "\nPolynomial result is: " << result;
}

int main()
{
    NODE *h1, *h2, *h3, *h4;
    int ch;
    h1 = getnode();
    h2 = getnode();
    h3 = getnode();
    h4 = getnode();
    h1->link = h1;
    h2->link = h2;
    h3->link = h3;
    h4->link = h4;

    cout << "Enter x, y, z powers (0-indicate NO term: 2 2 1\nIf you wish to continue press 1 otherwise 0: 1\n";
    cout << "Enter coeff: -4\nEnter x, y, z powers (0-indicate NO term: 0 1 5\nIf you wish to continue press 1 otherwise 0: 1\n";
    cout << "Enter coeff: 3\nEnter x, y, z powers (0-indicate NO term: 3 1 1\n";

    while (1)
    {
        cout << "\n\n1.Evaluate polynomial\n2.Add two polynomials\n3.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter polynomial to evaluate:\n";
            h1 = read_poly(h1);
            display(h1);
            evaluate(h1);
            break;
        case 2:
            cout << "\nEnter the first polynomial:";
            h1 = read_poly(h4);
            cout << "\nEnter the second polynomial:";
            h2 = read_poly(h2);
            h3 = add_poly(h4, h2, h3);
            cout << "\nFirst polynomial is: ";
            display(h4);
            cout << "\nSecond polynomial is: ";
            display(h2);
            cout << "\nThe sum of 2 polynomials is: ";
            display(h3);
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "\nInvalid entry";
            break;
        }
        cin.get();
    }
}
