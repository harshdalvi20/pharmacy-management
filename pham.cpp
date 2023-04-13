#include<iostream>
#include<cstring>
#include <iomanip>
#define MAX 100
using namespace std;

class medicine
{
public:
    string customername;
    int recieptno,x,menu2[MAX];
    int quantityx[MAX];
    int quantity[MAX],amount[MAX];
    int i;
    string medicineName[MAX]= {"crocin 500","Vitamin C(500mg)","Acid Free C(500mg)","Dolo 650","Marino Tablet","Maxi Cal Tablet",
                              "Zinc Tablet","Imol","Fabuloss 5","micozole"
                             };
    int Medicine[10] = {2,3,1,4,1,5,7,4,3,5};
    int total=0 ;
    void takeorder()
    {
        int i,choice, num,price,None;
        cout <<"\nAdd Order Details\n";
        cout <<"\n\n";
        cout<<"    MED ID"<<"     \t MED NAME"<<"             MED PRICE(rs)"<<endl;
        cout<<" \t1"<<"\t"<<"crocin 500"<<"             2.00/-"<<endl;
        cout<<" \t2"<<"\t"<<"Vitamin C(500mg)"<<"       3.00/-"<<endl;
        cout<<" \t3"<<"\t"<<"Acid Free C(500mg)"<<"     1.00/-"<<endl;
        cout<<" \t4"<<"\t"<<"Dolo 650"<<"               4.00/-"<<endl;
        cout<<" \t5"<<"\t"<<"Marino Tablet"<<"          1.00/-"<<endl;
        cout<<" \t6"<<"\t"<<"Maxi Cal Tablet"<<"        5.00/-"<<endl;
        cout<<" \t7"<<"\t"<<"Zinc Tablet"<<"            7.00/-"<<endl;
        cout<<" \t8"<<"\t"<<"Imol"<<"                   4.00/-"<<endl;
        cout<<" \t9"<<"\t"<<"Fabuloss 5"<<"             3.00/-"<<endl;
        cout<<" \t10"<<"\t"<<"micozole"<<"               5.00/-"<<endl;
        cout<<" "<<endl;
        cout <<"Enter reciept no ";
        cin >>recieptno;
        cout<<endl;
        cout <<"Enter customer name ";
        cin >>customername;
        cout<<endl;
        cout << "How many Medicines would you like to order:"<< endl;
        cout<<" (Maximum is 10 order for each transaction)  \n";
        cout << "  " ;
        cin >>x;
        cout<<endl;
        if (x >10)
        {
            cout << " Medicine order exceeded the maximum amount of order ";
        }
        else
        {
            for (i=0; i<x; i++)
            {
                cout << "Please enter MEDICINE ID  : "<<endl;
                cin>> menu2[i];
               cout<< "Medicine Name: " <<medicineName[menu2[i]-1]<<endl;
                cout << "How many quantity do you want: ";
                cin >> quantityx[i];
            }
            cout << "\nOrder  Successfull\n"<<endl;
            cout << " Proceed for payment(click 4)\n"<<endl;
        }
    }
    void delorder()
    {
        int num,count;
        cout<<"Enter receipt no  to delete \n";
        cin>>num;
        if(num==recieptno)
        {
            count --;
            cout<<"deleted sucessfully"<<endl;
            delete Medicine;
        }
        else
        {
            cout<<"invalid option"<<endl;
        }
    }

    void order()
    {
        int i, num, num2;
        cout<<" Enter the Reciept No. To Print  Reciept\n";
        cin>>num2;
        cout<<"\n";
        if( num2!=recieptno)
        {
            cout << " type your right reciept no.\n\n\n";
        }else
        {
            cout <<"\tOrder list\n";
            cout <<"Reciept No.  "<<recieptno;
            cout <<"\n";
            cout<<"Customer Name: "<<customername<<endl;
            cout << "\n|     Medicine Name       |  Quantity       |    Total Price |\n" << endl;
            for (i=0; i<x; i++)
            {
               cout<<medicineName[menu2[i]-1]<<"\t\t\t  ";
                cout<<quantityx[i] <<"\t\t";
                total=menu2[i]*quantityx[i];
            }
            cout<<"Total Bill : Rs.  "<<total;
            cout<<"\n";
            cout << "Enter the exact amount You need to pay: ";
            cin >> num;
            try
            {
                if(num==total)
                {
                    amount[i];
                    cout <<"\n";
                    cout<<"Payment received\n";
                }
                else
                {
                    throw( amount[i]);
                }
            }
            catch(int i)
            {
                cout<<"wrong amount, enter the correct payment amount\n";
            }
        }
    }
};

class modify : public medicine
{
public:
    int i, ch, sid,recieptno,x,menu2,quantity,amount;
    string customername;
    void modi()
    {
        cout<<"Enter Receipt Number To Modify: ";
        cin>>sid;
        if ( recieptno==NULL && sid==0)
        {
            cout<<"NO RECORD TO MODIFY"<<endl;
        }
        else
        {
            cout << "Change  Reciept Number: ";
            cin >> recieptno;
            cout<< "Change Customer Name: ";
            cin>> customername;
            cout << "How many New Medicine would you like to Change:"<< endl;
            cout<<"( Maximum is 10 order for each transaction ) \n";
            cout << "  " ;
            cin >> x;
            if (x >10)
            {
                cout << "Medicine you order is exceed the maximum amount of order !";
            }
            else
            {
                for (i=0; i<x; i++)
                {
                    cout << "Please enter your selection to Change: "<<endl;
                    cin>> menu2;
                    cout<< "Change Medicine Name: " <<medicineName[menu2-1]<<endl;
                    cout << "How many New medicine do you want: ";
                    cin >> quantity;
                    total=menu2;
                    cout << "The amount You need to pay After Modify  is: " << total<<" RS"<<endl;
                    if(recieptno== sid)
                    {
                        cout<<"Invalid Reciept Number"<<endl;
                    }
                    else
                    {
                        cout<<"RECORD MODIFIED....!"<<endl;
                    }
                }
            }
        }
    }
    void exit()
    {}
};

int main()
{
    int menu;
    do
    {
        cout<<"\n\t1. New Medicine           \n";
        cout<<"\t2. Delete latest Medicine  \n";
        cout<<"\t3. Modify Order List  \n";
        cout<<"\t4. Print  Reciept and Make Payment  \n";
        cout<<"\t5. Exit \n";
        cout<<"Enter choice: ";
        cin>>menu;
        switch (menu)
        {
        case 1:
        {
            medicine obj;
            obj.takeorder();
        }
        break;
        case 2:
        {
            medicine obj;
            obj.delorder();
            break;
        }
        case 3:
        {
            modify obj;
            obj.modi();
            break;
        }
        case 4:
        {
            medicine obj;
            obj.order();
            break;
        }
        case 5:
        {
            modify obj;
            obj.exit();
            break;
        }
        default:
        {
            cout<<"Invalid input \n"<<endl;
            break;
        }
        }
    }
    while(menu!=5);
    return 0;
}


