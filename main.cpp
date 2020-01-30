#include <iostream>

using namespace std;

class ic
{
    int x;
    int y;
    int z;
    int w;
    int i;
    public:

    void input(int a,int b,int c)
    {
        x=a;
        y=b;
        i=c;
        if(i == 0)
        {
            _and();
        }
        else if(i == 1)
        {
            _or();
        }
        else if(i == 2)
        {
            _xor();
        }
        else if(i == 3)
        {
            _nand();
        }
        else
        {
            _nor();
        }
    }
    void _not()
    {
        if(w==0)
        {
            z=1;
        }
        else
        {
            z=0;
        }
    }

    void input(int n)
    {
        w = n;
        _not();
    }

    void _and()
    {
        z =  x*y;
    }

    void _or()
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

    void _nor()
    {
        _or();
        w = z;
        _not();
    }

    void _nand()
    {
        _and();
        w = z;
        _not();
    }

    int result()
    {
        return z;
    }

};

void full_adder()
{
     ic ic_and0,ic_and1,ic_xor0,ic_xor1,ic_or0;
    int a=0,b=0,c=0;
    cout<<"Enter the two inputs\n";
    cin>>a>>b>>c;
    ic_xor0.input(a,b,2);
    ic_and0.input(ic_xor0.result(),c,0);
    ic_xor1.input(c,ic_xor0.result(),2);
    ic_and1.input(a,b,0);
    ic_or0.input(ic_and0.result(),ic_and1.result(),1);
    cout<<ic_or0.result()<<ic_xor1.result();
}

void multiplexer()
{
    ic ic_nand0,ic_nand1,ic_nand2,ic_nand3;
    int a=0,i=0,_i=0;
    cin>>_i>>a>>i;
    ic_nand0.input(a,_i,3);
    ic_nand1.input(a,a,3);
    ic_nand2.input(i,ic_nand1.result(),3);
    ic_nand3.input(ic_nand0.result(),ic_nand2.result(),3);
    cout<<ic_nand3.result();
}

void comparator()
{
    ic ic_not0,ic_not1,ic_and0,ic_and1,ic_or0;
    int a =1, b = 0;
    ic_not0.input(a);
    ic_not1.input(b);
    ic_and0.input(ic_not0.result(),b,0);
    ic_and1.input(ic_not1.result(),a,0);
    ic_or0.input(ic_and0.result(),ic_and1.result(),1);
    if(ic_and0.result() ==  1)
    {
        cout<<"A<B";
    }
    else if(ic_and1.result() == 1)
    {
        cout<<"A>B";
    }
    else
    {
        cout<<"A=B";
    }

}
int main()
{
   comparator();
    return 0;
}
