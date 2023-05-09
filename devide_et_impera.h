
void exit_menu(int *verif){
    char ch;
    int men = 1;
    do
    {
        printf("\nDoriti sa iesiti din program: Y / N\n>>>");
        scanf("%s", &ch);
        switch (ch)
        {
        case 'Y':
            printf("\nAti esit din program!");
            *verif = 0;
            men = 0;
            break;
        case 'y':
            printf("\nAti esit din program!");
            *verif = 0;
            men = 0;
            break;
        case 'N':
            system("cls");
            printf("\nAti prelungit lucrul programului!");
            *verif = 1;
            men = 0;
            break;
        case 'n':
            system("cls");
            printf("\nAti prelungit lucrul programului!");
            *verif = 1;
            men = 0;
            break;
        default:
            system("cls");
            printf("\nAti gresit optinuea!");
            men = 1;
            break;
        }
    } while (men);
    
}

int menu_option(char *option){
    int opt = -1;
    if (strcmp(option,"quick") == 0)
    {
        opt = 1;
    }
    if (strcmp(option,"merge") == 0)
    {
        opt = 2;
    }
    if (strcmp(option,"point") == 0)
    {
        opt = 3;
    }
    if (strcmp(option,"binary") == 0)
    {
        opt = 4;
    }
    if (strcmp(option,"hanoi") == 0)
    {
        opt = 5;
    }
    if (strcmp(option,"exit") == 0)
    {
        opt = 0;
    }
    return opt;
}

void menu(){    
    int verif = 1;
    char option[10];
    do
    {
        printf("\n==============================================");
        printf("\n\t\tMENU");
        printf("\nquick\t: Quick Sort");
        printf("\nmerge\t: Merge Sort");
        printf("\npoint\t: Closest pairs of points");
        printf("\nbinary\t: Binary Search");
        printf("\nhanoi\t: Tower of Hanoi");
        printf("\nexit\t: Exit");
        printf("\n>>>");
        scanf("%s", option);
        switch (menu_option(option))
        {
        case 1:
            menu_quick_sort();
            break;
        case 2:
            system("cls");
            menu_merge_sort();
            break;
        case 3:
            menu_closest_point();
            break;
        case 4:
            system("cls");
            menu_binary_search();
            break;
        case 5:
            system("cls");
            menu_tower_hanoi();
            break;
        case 0:
            system("cls");
            exit_menu(&verif);
            break;
        default:
            system("cls");
            printf("\nAti gresit optinuea!");
            break;
        }
    } while (verif);
}
