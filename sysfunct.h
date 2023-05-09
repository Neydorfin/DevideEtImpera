
void loading(){
    system("cls");
    printf("Loading.");
    sleep(1);
    system("cls");
    printf("Loading..");
    sleep(1);
    system("cls");
    printf("Loading...");
    sleep(1);
    system("cls");
}

void generator(int n, int vector[n]){
    char inter;
    int check = 1;
    int start = -50 , sfarsit = 150;
    do
    {
        system("cls");
        printf("\nDoriti sa alegeti intervalul de generare a numerelor: Y / N\n>>>");
        scanf("%s", &inter);
        if (inter == 'Y' || inter == 'y')
        {
            printf("\nIntroduceti intervalul:");
            printf("\nPunctul de start >>> ");
            scanf("%d",&start);
            printf("\nPunctul de sfarsit >>> ");
            scanf("%d",&sfarsit);
            check = 0;
        }
        else if (inter == 'N' || inter == 'n')
        {
            printf("\nNu ati introdus intevalul!");
            printf("\nInterval default este [-50;150]!");
            check = 0;
        }
        else{
            printf("\nAti gresit optiunea!");
            check = 1;
        }
    } while (check);
    srand(time(NULL));
    loading();
    printf("\nVectorul generat:\n");
    for(int i = 0; i < n; i++){
        vector[i] = rand() % sfarsit + start;
        printf("%d ", vector[i]);
    }
    printf("\n----------------------------------------------\n");
}

