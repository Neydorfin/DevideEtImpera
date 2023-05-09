
void hanoi(int n, int start, int end){
    if (n == 1)
    {
        printf("Disc [%d] from %d -> %d\n", n, start ,end);
    }
    else{
        
        int temp = 6 - start - end;
        hanoi(n-1, start, temp);
        printf("Disc [%d] from %d -> %d\n", n, start ,end);
        hanoi(n-1, temp, end);
    }
}


void menu_tower_hanoi(){
    loading();
    system("cls"); 
    int n, start, end;
    printf("Introduceti numarul de discuri:\n>>>");
    scanf("%d", &n);
    printf("Introduceti pozitia de start:\n>>>");
    scanf("%d", &start);
    printf("Introduceti pozitia finala:\n>>>");
    scanf("%d", &end);
    hanoi(n, start, end);
    printf("\nApasati orice tasta pentru a prelungi...\n");
    system("pause");
    system("cls");
}