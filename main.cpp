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

    ic(int temp)
    {
        i =  temp;
    }

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

    void input(int a,int b)
    {
        x=a;
        y=b;
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

void display(int num=0,int line=0)
{
    switch(line)
    {
    case 0:
        switch(num)
        {
        case 0:
            cout<<"+---+";
            break;
        case 1:
            cout<<"    +";
            break;
        case 2:
            cout<<"+---+";
            break;
        case 3:
            cout<<"+---+";
            break;
        case 4:
            cout<<"+   +";
            break;
        case 5:
            cout<<"+---+";
            break;
        case 6:
            cout<<"+---+";
            break;
        case 7:
            cout<<"+---+";
            break;
        case 8:
            cout<<"+---+";
            break;
        case 9:
            cout<<"+---+";
            break;
        default:
            cout<<"     ";
        }
        break;
    case 1:
        switch(num)
        {
        case 0:
            cout<<"|   |";
            break;
        case 1:
            cout<<"    |";
            break;
        case 2:
            cout<<"    |";
            break;
        case 3:
            cout<<"    |";
            break;
        case 4:
            cout<<"|   |";
            break;
        case 5:
            cout<<"|    ";
            break;
        case 6:
            cout<<"|    ";
            break;
        case 7:
            cout<<"    |";
            break;
        case 8:
            cout<<"|   |";
            break;
        case 9:
            cout<<"|   |";
            break;
        default:
            cout<<"     ";
        }
        break;
    case 2:
        switch(num)
        {
        case 0:
            cout<<"+   +";
            break;
        case 1:
            cout<<"    +";
            break;
        case 2:
            cout<<"+---+";
            break;
        case 3:
            cout<<"+---+";
            break;
        case 4:
            cout<<"+---+";
            break;
        case 5:
            cout<<"+---+";
            break;
        case 6:
            cout<<"+---+";
            break;
        case 7:
            cout<<"    +";
            break;
        case 8:
            cout<<"+---+";
            break;
        case 9:
            cout<<"+---+";
            break;
        default:
            cout<<"     ";
        }
        break;
     case 3:
        switch(num)
        {
        case 0:
            cout<<"|   |";
            break;
        case 1:
            cout<<"    |";
            break;
        case 2:
            cout<<"|    ";
            break;
        case 3:
            cout<<"    |";
            break;
        case 4:
            cout<<"    |";
            break;
        case 5:
            cout<<"    |";
            break;
        case 6:
            cout<<"|   |";
            break;
        case 7:
            cout<<"    |";
            break;
        case 8:
            cout<<"|   |";
            break;
        case 9:
            cout<<"    |";
            break;
        default:
            cout<<"     ";
        }
        break;

      case 4:
        switch(num)
        {
        case 0:
            cout<<"+---+";
            break;
        case 1:
            cout<<"    +";
            break;
        case 2:
            cout<<"+---+";
            break;
        case 3:
            cout<<"+---+";
            break;
        case 4:
            cout<<"    +";
            break;
        case 5:
            cout<<"+---+";
            break;
        case 6:
            cout<<"+---+";
            break;
        case 7:
            cout<<"    +";
            break;
        case 8:
            cout<<"+---+";
            break;
        case 9:
            cout<<"+---+";
            break;
        default:
            cout<<"     ";
        }
        break;
        default:
            cout<<"";
    }
}

void two_bitbcd(int a=0,int b=0)
{
    cout<<"\n";
    display(a,0);
    cout<<" ";
    display(b,0);
    cout<<"\n";
    display(a,1);
    cout<<" ";
    display(b,1);
    cout<<"\n";
    display(a,2);
    cout<<" ";
    display(b,2);
    cout<<"\n";
    display(a,3);
     cout<<" ";
    display(b,3);
    cout<<"\n";
    display(a,4);
    cout<<" ";
    display(b,4);
    cout<<"\n";

}
void full_adder()
{
    ic ic_and0(0),ic_and1(0),ic_xor0(2),ic_xor1(2),ic_or0(1);
    int a=0,b=0,c=0;
    cout<<"Enter the three inputs\n";
    cin>>a>>b>>c;
    ic_xor0.input(a,b);
    ic_and0.input(ic_xor0.result(),c);
    ic_xor1.input(c,ic_xor0.result());
    ic_and1.input(a,b);
    ic_or0.input(ic_and0.result(),ic_and1.result());
    cout<<ic_or0.result()<<ic_xor1.result();
    two_bitbcd(ic_or0.result(),ic_xor1.result());
}

void full_subtractor()
{
    ic ic_and0(0),ic_and1(0),ic_xor0(2),ic_xor1(2),ic_not0(-1),ic_not1(-1),ic_or0(1);
    int a=0,b=0,c=0;
    cout<<"Enter the three inputs\n";
    cin>>a>>b>>c;
    ic_xor0.input(a,b);
    ic_not0.input(a);
    ic_and0.input(b,ic_not0.result());
    ic_xor1.input(ic_xor0.result(),c);
    ic_not1.input(ic_xor0.result());
    ic_and1.input(ic_not1.result(),c);
    ic_or0.input(ic_and1.result(),ic_and0.result());
    cout<<ic_xor1.result()<<ic_or0.result();


}

void multiplexer()
{
    ic ic_nand0(3),ic_nand1(3),ic_nand2(3),ic_nand3(3);
    int a=0,i=0,_i=0;
    cin>>_i>>a>>i;
    ic_nand0.input(a,_i);
    ic_nand1.input(a,a);
    ic_nand2.input(i,ic_nand1.result());
    ic_nand3.input(ic_nand0.result(),ic_nand2.result());
    cout<<ic_nand3.result();
}

void comparator()
{
    ic ic_not0(-1),ic_not1(-1),ic_and0(0),ic_and1(0),ic_or0(1);
    int a =1, b = 0;
    ic_not0.input(a);
    ic_not1.input(b);
    ic_and0.input(ic_not0.result(),b);
    ic_and1.input(ic_not1.result(),a);
    ic_or0.input(ic_and0.result(),ic_and1.result());
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
    full_subtractor();

    return 0;
}

/*+---+
  |   |
  +---+
  |   |
  +---+*/
