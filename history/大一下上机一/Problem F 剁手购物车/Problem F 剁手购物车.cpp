#include <iostream>
using namespace std;
class W
{
public:
    double price;
    int num;
};
class Cart
{
public:
    W w[3];
    Cart()
    {       

    }
    virtual double caculate() 
    { 
        double sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += (w[i].price * w[i].num);
        }
        return sum;
    }
    friend istream& operator>>(istream&, Cart);
};
istream& operator>>(istream& input, Cart cart)
{
    for (int i = 0; i < 3; i++)
    {
        cin >> cart.w[i].price;
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> cart.w[i].num;
    }
    return input;
}
class DisCount :public Cart
{
public:
    virtual double caculate()
    {
        double sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += ((double)w[i].price * w[i].num) * 0.9;
        }
        return sum;
    }
};
class Minus :public Cart
{
public:
    virtual double caculate()
    {
        double sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += ((double)w[i].price * w[i].num);
        }
        double cnt;
        cnt = sum / (200.0);
        sum -= cnt * 30;
        return sum;
    }
};
int main()
{
    DisCount d;
    Cart* cart = &d;
    while (cin >> *cart) 
    {
        double originPrice = cart->caculate();
        DisCount* discount = (DisCount*)cart;
        double res1 = discount->caculate();
        Minus* minus = (Minus*)cart;
        double res2 = minus->caculate();
        cout << originPrice << " ";
        if (res1 < res2) {
            cout << res1 << endl;
        }
        else {
            cout << res2 << endl;
        }
    }
    return 0;
}