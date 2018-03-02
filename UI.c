//User Interface File

//global variable;
COORD coord={0,0};

//function for location in screen in left-hand co-ordinate system.
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//function for input of up  and down arrow
int keys(int h)
{
    int v=18;
    char keyPress;

    Opt:
    gotoxy(h,v);
    printf("-->");
    fflush(stdin);
    keyPress = getch();

    if(keyPress == 13)
        return v;
    else if (keyPress == 72)
    {
            // code for arrow up
            v=v-2;
            if(v<=18)
                {
                    gotoxy(h,v+2);
                    printf("   ");
                    v=18;
                    goto Opt;
                }
            gotoxy(h,v+2);
            printf("   ");
            goto Opt;

    }
    else if(keyPress == 80)// code for arrow down
    {
            v=v+2;
            if(v>=22){
                gotoxy(h,v-2);
                printf("   ");
                v=22;
                goto Opt;
            }
            gotoxy(h,v-2);
            printf("   ");
            goto Opt;
    }
    else
            goto Opt;
}


//code for logo of project
void logo()
{
    int x = 11;
    int y = 4;

    char str1[] = " --  -----   ----          ---    ---       ---    ---      --  -----   ----          ---    --- ";
    char str2[] = "/      |    |    |  |  |  |      |   |     |   \\  |        /      |    |    |  |  |  |      |   |";
    char str3[] = "|      |    |    |  |  |  |      |   |     |   |  |        |      |    |    |  |  |  |      |   |";
    char str4[] = "|      |     ----    --    ---    ---   -- |   |   ---  -- |      |     ----    --    ---    ---";
    char str5[] = "|      |    |       |  |  |       |\\       |   |  |        |      |    |       |  |  |       |\\       ";
    char str6[] = "\\      |    |       |  |  |       | \\      |   /  |        \\      |    |       |  |  |       | \\      ";
    char str7[] = " --  -----                 ---    |  \\      ---    ---      --  -----                 ---    |  \\      ";

    gotoxy(x,y);
    printf("%s",str1);
    gotoxy(x,y+1);
    printf("%s",str2);
    gotoxy(x,y+2);
    printf("%s",str3);
    gotoxy(x,y+3);
    printf("%s",str4);
    gotoxy(x,y+4);
    printf("%s",str5);
    gotoxy(x,y+5);
    printf("%s",str6);
    gotoxy(x,y+6);
    printf("%s",str7);
}

//code for displaying boxes
void box()
{
    for (int i = 0; i < 105; i++)
    {
        gotoxy(8+i,3);
        printf("%c",223);
        gotoxy(8+i,12);
        printf("%c",223);
        gotoxy(8+i,28);
        printf("%c",223);
    }

    for (int i = 3; i < 28; i++)
    {
        gotoxy(8,i);
        printf("%c",219);
        gotoxy(8+104,i);
        printf("%c",219);
    }
}

//code for confirmation screen
int confirm_screen()
{
    system("cls");
    logo();
    box();

    gotoxy(43,14);
    printf("Do you want to confirm your input data ?");
    gotoxy(48,18);
    printf(" Yes, Proceed");
    gotoxy(48,20);
    printf(" No, Change");
    gotoxy(48,22);
    printf(" Back to Main Menu");

    int keypress = keys(45);
    if (keypress == 18)
        return 0;
    else if(keypress == 20)
        return 1;
    else if (keypress== 22)
        return -1;
    else
        exit(0);
}

//function of UI of input of encryption screen.
void encryption_screen()
{
    start:
    system("cls");

    char key_character[8];
    char file_namein[100];
    char file_nameout[100];

    logo();
    box();

    gotoxy(45,14);
    printf("Input the following information");
    gotoxy(25,18);
    printf("Enter 8 Characters Key: ");
    scanf("%s",key_character);

    if (strlen(key_character) != 8)
        goto start;

    gotoxy(25,20);
    printf("Enter filename you want to encrypt: ");
    scanf("%s",file_namein);
    gotoxy(25,22);
    printf("Enter output filename: ");
    scanf("%s",file_nameout);

    int x = confirm_screen();
    if (x == 1)
        goto start;
    else if (x == 0)
    {
        file_encrypt(key_character,file_namein, file_nameout);
        succesfull();
    }
    else if (x==-1){
        int y = main();
        exit(1);
    }
    else
        exit(0);
}

// function of UI of decryption screen.
void decryption_screen()
{
    start:
    system("cls");

    char key_character[8];
    char file_namein[100];
    char file_nameout[100];

    logo();
    box();

    gotoxy(45,14);
    printf("Input the following information");
    gotoxy(25,18);
    printf("Enter 8 Character Key: ");
    scanf("%s",key_character);
    if (strlen(key_character) != 8)
        goto start;

    gotoxy(25,20);
    printf("Enter filename you want to decrypt: ");
    scanf("%s",file_namein);
    gotoxy(25, 22);
    printf("Enter output filename: ");
    scanf("%s",file_nameout);

    int x = confirm_screen();
    if (x == 1)
        goto start;
    else if (x == 0)
    {
        file_decrypt(key_character, file_namein, file_nameout);
        succesfull();
    }
    else if (x==-1){
        int y = main();
        exit(1);
    }
    else
        exit(0);
}

//main function of UI screen
void main_UI()
{
    system("cls");
    SetConsoleTitle("Cipher-De-Cipher");
    system("color 02");
    logo();
    box();

    gotoxy(55,14);
    printf("M E N U");
    gotoxy(48,18);
    printf(" Encrypt  File");
    gotoxy(48,20);
    printf(" Decrypt  File");
    gotoxy(48,22);
    printf(" Exit ");

    int press = keys(45);
    if (press == 18)
        {
        encryption_screen();
        }
    else if(press == 20)
        {
         decryption_screen();
        }
    else if(press == 22)
        {   system("cls");
            exit(1);
        }
    else
        printf("Bug");
}

//Success Message
void succesfull()
{
    system("cls");
    logo();
    box();

    gotoxy(45,14);
    printf("Successfully Completed Task");
    gotoxy(45,16);
    printf("Press any key to continue");
    getch();

    fflush(stdin);
    main_UI();
}
