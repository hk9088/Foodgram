#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#define RETURNTIME 15

void Password();
void Mainmenu();
void Administration();
void User();
void Admin_Food_menu();
void Admin_Orders();
void Admin_Income();
void Add_item_menu();
void Update_Menu();
void View_Menu();
void new_menu();
void editmenu();

int  check_code(int);
int item_code(void);
char contact[20];
char password[10]={"123"};
char finditem;
FILE *Menu, *fp,*ft,*fs,*in;
char M[1000];

struct items
{
    int id;
    int quantity;
    int table;
    char stname[20];
    char name[100],report[1000];
    float Price;
};
struct items a;



COORD coord = {0, 0};
void gotoxy (int x, int y)
{
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



/*void getdate()
{
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    printf("%d / %d / %d",stime.wDay,stime.wMonth,stime.wYear);
}*/

void Password(void)
{

    system("cls");
    char d[25]=" Password Protected";
    char ch,pass[10];
    int i=0,j;
    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
        Sleep(10);
        printf("*");
    }
    for(j=0;j<20;j++)
    {
        Sleep(30);
        printf("%c",d[j]);
    }
    for(j=0;j<20;j++)
    {
        Sleep(30);
        printf("*");
    }
    gotoxy(15,7);
    printf("Enter Password:");

    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {

        gotoxy(15,9);
        //textcolor(BLINK);
        printf("Password match");
        gotoxy(15,10);
        printf("Press any key to countinue.....");
        getch();
        completedorders();
    }
    else
    {
        gotoxy(15,16);
        printf("\aWarning!! Incorrect Password");
        getch();
        Administration();
    }
}


void Mainmenu()
{
    system("cls");

    int i;
    char r;
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 < 1 > Administration");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 < 2 > User");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 < 0 > Exit");
    gotoxy(20,11);

    printf("Enter your choice:");
    r=getch();
    switch(r)
    {
        case '1':
        Administration();
        break;

        case '2':
        User();
        break;
        case '0':
        {exit(0);
        break;}

        default:
        {
            gotoxy(10,23);
            printf("\aWrong Entry!!Please re-entered correct option");
            if(getch())
            Mainmenu();
        }

    }
}

void Administration()
{
    system("cls");

    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Administration \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 < 1 > Food Menu");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 < 2 > Orders");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 < 3 > Income");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 < 4 > Reservation");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 < 5 > View Reports");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 < 0 > Back");


    gotoxy(20,17);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        Admin_Food_menu();
        break;
        case '2':
        adminorders();
        break;
        case '3':
        Password();
        break;
        case '4':
        reservation();
        break;
        case '5':
        viewreports();
        Administration();
        break;
        case '0':
        Mainmenu();
        break;

        default:
        {
            gotoxy(10,23);
            printf("\aWrong Entry!!Please re-entered correct option");
            if(getch())
            Administration();
        }

    }

}
void Admin_Food_menu()
{
    system("cls");
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Administration \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 < 1 > Add Menu Items");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 < 2 > Edit Menu Items");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 < 3 > Create New Menu");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 < 4 > View Menu");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 < 0 > Back");
    gotoxy(20,15);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        Add_item_menu();
        break;
        case '2':
        editmenu();
        break;
        case '3':
        new_menu();
        break;
        case '4':
        {
        View_Menu();
        Admin_Food_menu();
        }
        break;
        case '0':
        Administration();
        break;

        default:
        {
            gotoxy(10,23);
            printf("\aWrong Entry!!Please re-entered correct option");
            if(getch())
            Admin_Food_menu();
        }

    }
}
void User()
{
    system("cls");

    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    User    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 < 1 > Menu \\ Order Food");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 < 2 > Check Orders");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 < 3 > Reservations");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 < 4 > Report");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 < 0 > Back");
    gotoxy(20,15);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        orderfood();
        break;
        case '2':
        userorders();
        userorderview();
        break;
        case '3':
        View_Reserve();
        User();
        break;
        case '4':
        reportmenu();
        break;
        case '0':
        Mainmenu();
        break;

        default:
        {
            gotoxy(10,23);
            printf("\aWrong Entry!!Please re-entered correct option");
            if(getch())
            User();
        }

    }

}
void Add_item_menu()
{
    system("cls");
    fp=fopen("menu.dat","ab+");
    if(getdata()==1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(21,14);
        printf("The record is sucessfully saved");
        gotoxy(21,15);
        printf("Save any more?(Y / N):");
        switch(getch())
        {
        case 'y':
        Add_item_menu();
        break;
        case 'n':
        Admin_Food_menu();
        break;
        }
    }
    fclose(fp);

}
void View_Menu()
{
    int j;
    system("cls");
    gotoxy(1,1);
    printf("********************************* MENU *****************************");
    gotoxy(2,2);
    printf("ID              FOOD NAME                           PRICE");
    j=4;
    fp=fopen("menu.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%d",a.id);
        gotoxy(15,j);
        printf("%s",a.name);
        gotoxy(55,j);
        printf("%.2f",a.Price);
        printf("\n\n");
        j++;
    }
    getch();
}
int count()
{
    int j;
    j=4;
    fp=fopen("menu.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        j++;
    }
    return j;
}
int rcount()
{
    int j;
    j=4;
    fp=fopen("reserve.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        j++;
    }
    return j;
}
int getdata()
{


    int t;
    gotoxy(20,3);
    printf("Enter the Information Below");
    gotoxy(20,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,12);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21,6);
    printf("Item ID:\t");
    gotoxy(30,6);
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe item id already exists\a");
        _getch();
        Admin_Food_menu();
        return 0;
    }
    a.id=t;
    gotoxy(21,7);
    printf("Item Name:");
    gotoxy(33,7);
    gets(a.name);
    gets(a.name);
    gotoxy(21,9);
    printf("Price:");
    gotoxy(28,9);
    scanf("%f",&a.Price);

    return 1;
}
int checkid(int t)
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(a.id==t)
            return 0;
    return 1;
}
void new_menu()
{
    system("cls");
    fp=fopen("menu.dat","wb+");
    fp=fopen("menu.dat","ab+");
    if(getdata()==1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(21,14);
        printf("The record is sucessfully saved");
        gotoxy(21,15);
        printf("Save any more?(Y / N):");
        switch(getch())
        {
        case 'y':
        Add_item_menu();
        break;
        case 'n':
        Admin_Food_menu();
        break;
        }
    }
    fclose(fp);
}
void editmenu(void)
{
    system("cls");
    int c=0;
    int d,e;
    gotoxy(20,4);
    printf("****Edit Menu Section****");
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(15,6);
        printf("Enter Item Id to be edited:");
        scanf("%d",&d);
        fp=fopen("menu.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {
                gotoxy(15,7);
                printf("The Item is availble");
                gotoxy(15,8);
                printf("The Item ID:%d",a.id);
                gotoxy(15,9);
                printf("Enter new name:");
                gets(a.name);
                gets(a.name);
                gotoxy(15,10);
                printf("Enter new quantity:");
                scanf("%d",&a.quantity);
                gotoxy(15,12);
                printf("Enter new price:");
                scanf("%f",&a.Price);
                gotoxy(15,13);
                printf("The record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(15,9);
                printf("No record found");
            }
        }
        gotoxy(15,16);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another=_getch() ;
    }
    returnfunc();
}
void returnfunc(void)
{
    {
        printf(" Press ENTER to return to main menu");
    }
a:
    if(_getch()==13) //allow only use of enter
        Administration();
    else
        goto a;
}
void issuerecord()
{
    system("cls");
    gotoxy(10,9);
    printf("Table Number : %d",a.table);

}
void orderfood(void)
{
    system("cls");
    View_Menu();
    printf("\n\nOrder Now ? : (y \\ n)");
    if(getch()=='y')
    {
        int t,x=count();
        char another='y';
        while(another=='y')
        {
            View_Menu();
            printf("\n\nEnter the item Id:");
            scanf("%d",&t);
            fs=fopen("Issue.dat","ab+");
            if(checkid(t)==0)
            {
                system("cls");
                gotoxy(10,x);
                printf("The item is available");
                gotoxy(10,x+2);
                printf("The name of item is %s  Price : %.2f  ",a.name,a.Price);
                gotoxy(10,x+4);
                printf("Enter Phone Number :");
                scanf("%s",a.stname);
                gotoxy(10,x+6);
                printf("Enter Table number:");
                scanf("%d",&a.table);
                gotoxy(10,x+8);
                printf("Enter Quantity:");
                scanf("%d",&a.quantity);
                gotoxy(10,x+10);
                printf("The Item of ID %d is Ordered",a.id);

                fseek(fs,sizeof(a),SEEK_END);
                fwrite(&a,sizeof(a),1,fs);
                fclose(fs);

            }
            if(checkid(t)!=0)
            {
                gotoxy(10,x);
                printf("No record found");
            }
            gotoxy(10,x+11);
            printf("Order any more(Y/N):");
            fflush(stdin);
            another=getche();
            fclose(fp);
        }
        User();

    }
    else
       User();
}
void adminorders(void)
{
    int t;

    system("cls");
    gotoxy(10,7);
    printf("\xDB\xDB\xDB\xDb\xB2 < 1 >. View Ordered Item");
    gotoxy(10,11);
    printf("\xDB\xDB\xDB\xDb\xB2 < 2 >. Complete Ordered Item");
    gotoxy(10,14);
    printf("\xDB\xDB\xDB\xDb\xB2 < 0 >. Back");
    gotoxy(10,17);
    printf("Enter a Choice:");
    switch(_getch())
    {
    case '1':
    {
        system("cls");
        int j=4;
        printf("*******************************Ordered Item*******************************\n");
        gotoxy(2,2);
        printf("Phone Number               ID    ITEM NAME         Quantity    Price");
        fs=fopen("Issue.dat","rb");
        while(fread(&a,sizeof(a),1,fs)==1)
        {

            gotoxy(2,j);
            printf("%s",a.stname);
            gotoxy(30,j);
            printf("%d",a.id);
            gotoxy(36,j);
            printf("%s",a.name);
            gotoxy(56,j);
            printf("%d",a.quantity );
            gotoxy(70,j);
            printf("%.2f",a.quantity*a.Price);
            gotoxy(50,25);
            j++;
        }
        fclose(fs);
        gotoxy(1,25);
        returnfunc();
    }
    break;
    case '2':
    {
        system("cls");
        FILE *fg;

        char another='y';
        while(another=='y')
        {
            char b[20];
            system("cls");
            gotoxy(10,5);
            printf("ENTER Phone Number TO COMPLETE:");
            scanf("%s",b);
            fs=fopen("Issue.dat","rb+");
            while(fread(&a,sizeof(a),1,fs)==1)
            {
                if(strcmp(a.stname,b)==0)
                {
                    issuerecord();
                    finditem='t';
                }
                if(finditem=='t')
                {
                    gotoxy(10,12);
                    printf("Do You Want to Complete it?(Y/N)");
                    if(_getch()=='y')
                    {
                        fg=fopen("record.dat","wb+");
                        in=fopen("income.dat","ab+");
                        rewind(fs);
                        while(fread(&a,sizeof(a),1,fs)==1)
                        {
                            if(strcmp(a.stname,b)!=0)
                            {
                                fseek(fs,0,SEEK_CUR);
                                fwrite(&a,sizeof(a),1,fg);
                            }
                            if(strcmp(a.stname,b)==0)
                            {
                                fseek(fs,0,SEEK_CUR);
                                fwrite(&a,sizeof(a),1,in);
                            }

                        }
                        fclose(fs);
                        fclose(fg);
                        fclose(in);
                        remove("Issue.dat");
                        rename("record.dat","Issue.dat");
                        gotoxy(10,14);
                        printf("The Order is  Completed");


                    }

                }
                if(finditem!='t')
                {
                    gotoxy(10,15);
                    printf("No Record Found");
                }
            }
            gotoxy(10,16);
            printf("Complete any more?(Y/N)");
            another=_getch();
        }
        returnfunc();
    }
    break;
    case '0':
        Administration();
        break;


    default:
        gotoxy(10,18);
        printf("\aWrong Entry!!");
        _getch();
        adminorders();
        break;
    }
    gotoxy(1,30);
    returnfunc();
}

void userorders()
{
        system("cls");
        char b[20];
        int x=0;
        FILE *fg;
            system("cls");
            gotoxy(10,5);
            printf("ENTER Phone Number TO SEE ORDERS:");
            scanf("%s",b);
            fs=fopen("Issue.dat","rb+");
            while(fread(&a,sizeof(a),1,fs)==1)
            {
                if(strcmp(a.stname,b)==0)
                {

                        fg=fopen("user.dat","wb+");
                        rewind(fs);
                        while(fread(&a,sizeof(a),1,fs)==1)
                        {
                            if(strcmp(a.stname,b)==0)
                            {
                                fseek(fs,0,SEEK_CUR);
                                fwrite(&a,sizeof(a),1,fg);

                            }
                        }
                        fclose(fs);
                        fclose(fg);
                        x=1;

                }

            }
            if(x==0)
            {
                    gotoxy(10,15);
                    printf("No Record Found");
                    gotoxy(10,16);
                    printf("Press any key..............");
                    getch();
                    User();
            }

}
void userorderview()
{
        system("cls");
        int j=4;
        float sum=0;
        printf("*******************************Ordered Item*******************************\n");
        gotoxy(2,2);
        printf("Phone Number               ID    ITEM NAME         Quantity    Price");
        fs=fopen("user.dat","rb");
        while(fread(&a,sizeof(a),1,fs)==1)
        {

            gotoxy(2,j);
            printf("%s",a.stname);
            gotoxy(30,j);
            printf("%d",a.id);
            gotoxy(36,j);
            printf("%s",a.name);
            gotoxy(56,j);
            printf("%d",a.quantity);
            gotoxy(70,j);
            printf("%.2f",a.quantity*a.Price);
            j++;
            sum+=a.Price*a.quantity;
        }
        fclose(fs);
        gotoxy(50,j+5);
        printf("The Total Bill is %.2f",sum);
        if(getch())
            User();
}

void completedorders()
{
        system("cls");
        int j=4;
        float sum=0;
        printf("*****************************Completed Ordered Item*****************************\n");
        gotoxy(2,2);
        printf("Phone Number                ID    ITEM NAME          Quantity        Price");
        in=fopen("income.dat","rb");
        while(fread(&a,sizeof(a),1,in)==1)
        {

            gotoxy(2,j);
            printf("%s",a.stname);
            gotoxy(30,j);
            printf("%d",a.id);
            gotoxy(36,j);
            printf("%s",a.name);
            gotoxy(56,j);
            printf("%d",a.quantity);
            gotoxy(70,j);
            printf("%.2f",a.quantity*a.Price);
            j++;
            sum+=a.Price*a.quantity;
        }
        fclose(in);
        gotoxy(50,j+5);
        printf("The Total income is %.2f",sum);
        if(getch())
            Administration();
}
void adminreserve()
{
    system("cls");
    fp=fopen("reserve.dat","ab+");
    if(getadminresevedata()==1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(21,14);
        printf("The record is sucessfully saved");
        gotoxy(21,15);
        printf("Save any more?(Y / N):");
        switch(getch())
        {
        case 'y':
        adminreserve();
        break;
        case 'n':
        Administration();
        break;
        }
    }
    fclose(fp);

}
void getadminresevedata()
{
    int t;

    gotoxy(20,3);
    printf("Enter the Information Below");
    gotoxy(20,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,12);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21,6);
    printf("Table No:\t");
    gotoxy(30,6);
    scanf("%d",&t);
    if(reservecheckid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe table already exists\a");
        _getch();
        Administration();
        return 0;
    }
    a.id=t;
    gotoxy(21,7);
    printf("Phone no: ");
    gets(a.stname);
    gets(a.stname);
    gotoxy(21,8);
    printf("Booked/Unbooked :");
    gets(a.name);
    gotoxy(21,9);
    printf("Quantity:");
    gotoxy(33,9);
    scanf("%d",&a.quantity);

    return 1;
}
int reservecheckid(int t)
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(a.id==t)
            return 0;
    return 1;
}
void editreserve()
{
    system("cls");
    int c=0;
    int d,e;
    gotoxy(20,4);
    printf("****Edit Table Section****");
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(15,6);
        printf("Enter Table to be edited:");
        scanf("%d",&d);
        fp=fopen("reserve.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(reservecheckid(d)==0)
            {
                gotoxy(15,7);
                printf("The table is availble");
                gotoxy(15,8);
                printf("The Table No.:%d",a.id);
                gotoxy(15,9);
                printf("Phone no:");
                gets(a.stname);
                gets(a.stname);
                gotoxy(15,10);
                printf("Booked/Unbooked:");
                gets(a.name);
                gotoxy(15,11);
                printf("Enter new quantity:");
                scanf("%d",&a.quantity);
                gotoxy(15,13);
                printf("The record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(15,9);
                printf("No record found");
            }
        }
        gotoxy(15,16);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another=_getch() ;
    }
    returnfunc();
}
void View_Reserve()
{
    int j;
    system("cls");
    gotoxy(1,1);
    printf("********************************* Reservation *****************************");
    gotoxy(2,2);
    printf("Table No.              Booking                           Quantity");
    j=4;
    fp=fopen("reserve.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%d",a.id);
        gotoxy(25,j);
        printf("%s",a.name);
        gotoxy(60,j);
        printf("%d",a.quantity);
        printf("\n\n");
        j++;
    }
    gotoxy(25,j+5);
    printcontact();
    getch();
}
void reservation()
{
    system("cls");
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Administration \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 < 1 > Add Table");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 < 2 > Edit Table Info");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 < 3 > View Table Info");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 < 4 > Change Contact");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 < 0 > Back");
    gotoxy(20,15);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        adminreserve();
        break;
        case '2':
        editreserve();
        break;
        case '3':
        {
        Admin_View_Reserve();
        reservation();
        }
        break;
        case '4':
        getcontact();
        reservation();
        break;
        case '0':
        Administration();
        break;

        default:
        {
            gotoxy(10,23);
            printf("\aWrong Entry!!Please re-entered correct option");
            if(getch())
            reservation();
        }

    }
}
void Admin_View_Reserve()
{
    int j;
    system("cls");
    gotoxy(1,1);
    printf("********************************* Reservations ****************************");
    gotoxy(2,2);
    printf("Table No.              Phone                    Quantity           Booking");
    j=4;
    fp=fopen("reserve.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%d",a.id);
        gotoxy(25,j);
        printf("%s",a.stname);
        gotoxy(54,j);
        printf("%d",a.quantity);
        gotoxy(69,j);
        printf("%s",a.name);
        printf("\n\n");
        j++;
    }
    gotoxy(25,j+5);
    printcontact();
    getch();
}
void getcontact()
{
    system("cls");
    printf("Enter Number : ");
    gets(contact);
}
void printcontact()
{
    printf("Contact Number for Booking: %s ",contact);
}
int getreportdata()
{
    system("cls");
    fp=fopen("report.dat","ab+");
    gotoxy(20,3);
    printf("Enter the Information Below");
    gotoxy(21,6);
    gets(a.stname);
    gotoxy(21,6);
    printf("Phone no: ");
    gets(a.stname);
    gotoxy(21,8);
    printf("Report :");
    gets(a.report);
    return 1;
}
void report()
{

    system("cls");
    fp=fopen("report.dat","ab+");
    if(getreportdata()==1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(21,14);
        printf("The record is successfully saved");
        gotoxy(21,15);
        printf("Report any more?(Y / N):");
        switch(getch())
        {
        case 'y':
        report();
        break;
        case 'n':
        reportmenu();
        break;
        }
    }
    fclose(fp);
}
void viewreports()
{
    int j;
    system("cls");
    gotoxy(1,1);
    printf("********************************* Reports ****************************");
    gotoxy(2,2);
    printf("Phone No.                         Comments");
    j=4;
    fp=fopen("report.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%s",a.stname);
        gotoxy(36,j);
        printf("%s",a.report);
        printf("\n\n");
        j=j+2;;
    }
    gotoxy(3,j+5);
    getch();
}

void reportmenu()
{
    system("cls");

    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Report    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 < 1 > Customer Report");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 < 2 > View Report");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 < 0 > Back");
    gotoxy(20,15);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        report();
        break;
        case '2':
        viewreports();
        reportmenu();
        break;
        case '0':
        User();
        break;

        default:
        {
            gotoxy(10,23);
            printf("\aWrong Entry!!Please re-entered correct option");
            if(getch())
            User();
        }

    }
}
int main()
{
    system("COLOR F9");
    Mainmenu();
    return 0;

}


