
int binarysearch(int vector[40], int left, int right, int elem){
    if (left <= right){
        int mid = left + (right - left) / 2;
        if(vector[mid] == elem){
            return mid;
        }
        else if (vector[mid] > elem){
            return binarysearch(vector, left, mid-1, elem);
        }
        else{
            return binarysearch(vector, mid+1, right, elem);
        }
    }
    return -1;
}

void menu_binary_search(){
    system("cls");
    int n = 30 , rezult = -1;
    int vector[n], x;
    generator(n,vector);
    quicksortvector(n, vector, 0, n-1);
    do
    {
        printf("\nVector Sortat:\n");
        for (int i = 0; i < n; i++){
            printf("%d ", vector[i]);
        }
        printf("\nIntroduceti elementul care doriti sa-l gasiti:\n>>>");
        scanf("%d",&x);
        rezult = binarysearch(vector, 0, n-1, x);
        if (rezult != -1)
        {
            printf("\nElementul %d este pe pozitia %d!\n", x, rezult);
        }
        else{
            printf("\nAsa element nu exista in acest vector!\n");
            char ch;
            int men = 1;
            do
            {
                printf("\nDoriti sa introduceti al t element: Y \ N\n>>>");
                scanf("%s", &ch);
                switch (ch)
                {
                case 'Y':
                    men = 0;
                    system("cls");
                    break;
                case 'y':
                    men = 0;
                    system("cls");
                    break;
                case 'N':
                    men = 0;
                    rezult = 1;
                    system("cls");
                    break;
                case 'n':
                    men = 0;
                    rezult = 1;
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("\nAti gresit optinuea!");
                    break;
                }
            } while (men);
            
        }
    } while (rezult == -1);
    
    printf("\nApasati orice tasta pentru a prelungi...\n");
    system("pause");
    system("cls");
}