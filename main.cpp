#include <iostream>

using namespace std;

class ic
{
    int x;
    int y;
    int z;
    public:

    void input(int a,int b,int c)
    {
        x=a;
        y=b;
        if(c == 0)
        {
            dot();
        }
        else if(c == 1)
        {
            add();
        }
        else
        {
            _xor();
        }
    }

    void dot()
    {
        z =  x*y;
    }

    void add()
    {
        if(x ==  1 && y == 1)
        {
            z = 1;
        }
        else
        {
            z = x+y;
        }
    }

    void _xor()
    {
        if(x == 1 && y==1)
        {
            z = 0;
        }
        else
        {
            z = x+y;
        }
    }

    int result()
    {
        return z;
    }

};

int main()
{
    ic ic_and0,ic_and1,ic_xor0,ic_xor1,ic_or0;
    int a=0,b=0,c=0;
    cout<<"Enter the two inputs\n";
    cin>>a>>b>>c;
    ic_xor0.input(a,b,2);
    ic_and0.input(a,b,0);
    ic_xor1.input(c,ic_xor0.result(),2);
    ic_and1.input(c,ic_xor1.result(),0);
    ic_or0.input(ic_and0.result(),ic_and1.result(),1);
    cout<<ic_or0.result()<<ic_xor1.result();
    return 0;
}
