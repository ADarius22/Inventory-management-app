#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[15];
    int code;
    double price;

} product;
product item;
FILE *f;

void add();
void Searchby_price();
void Searchby_name();
void Searchby_code();
void Viewby_code();
void Viewby_price();
void Viewby_name();
void Buyby_Name();
void Buyby_Code();

int i,j,k,flag;

int main() {
    printf("\n_______________________________WELCOME_________________________________________\n");
    do {
        printf("\n\n\n\n\t\t\t1.Add an item\n\t\t\t2.Buy an item\n");
        printf("\t\t\t3.Search item\n");
        printf("\t\t\t4.View items\n\t\t\t0.Exit\n\t\t\t ");
        scanf("%d",&j);

        switch(j) {
        case 1:
            add();
            break;
        case 2:
            printf("\n\n\n\t\t\t1. Buy by name\n\t\t\t2. Buy by code\n\t\t\t0. Back to main menu\n\t\t\t");
                scanf("%d", &k);

                switch(k) {
                    case 1:
                        Buyby_Name();
                        break;
                    case 2:
                        Buyby_Code();
                        break;
                    case 0:
                        printf("\nPress any key to return to the main menu.\n");
                        getchar();
                        while (getchar() != '\n');
                        main();
                        break;
                    default:
                        printf("Invalid option. Please enter a valid option.\n");
                        break;
                }
                break;
        case 3:

                printf("\n\n\n\t\t\t1. Search by name\n\t\t\t2. Search by code\n\t\t\t3. Search by price\n");
                printf("\t\t\t0. Back to main menu\n\t\t\t");


                scanf("%d", &k);

                switch(k) {
                    case 1:
                        Searchby_name();
                        break;
                    case 2:
                        Searchby_code();
                        break;
                    case 3:
                        Searchby_price();
                        break;
                    case 0:
                        printf("\nPress any key to return to the main menu.\n");
                        getchar();
                        while (getchar() != '\n');
                        main();
                        break;
                    default:
                        printf("Invalid option. Please enter a valid option.\n");
                        break;
                }
                break;


        case 4:
                printf("\n\n\n\t\t\t1. View by name\n\t\t\t2. View by code\n\t\t\t3. View by price\n");
                printf("\t\t\t0. Back to main menu\n\t\t\t");

                scanf("%d", &k);

                switch(k) {
                    case 1:
                        Viewby_name();
                        break;
                    case 2:
                        Viewby_code();
                        break;
                    case 3:
                        Viewby_price();
                        break;
                    case 0:
                        printf("\nPress any key to return to the main menu.\n");
                        getchar();
                        while (getchar() != '\n');
                        main();
                        break;
                    default:
                        printf("Invalid option. Please enter a valid option.\n");
                        break;
                }
                break;


        default:
            if(j!=0) {
                printf("Enter correct number\n");
                printf("\nPress any key to try again.");

            }
            break;

        }
        system("cls");
    } while(j!=0);
    printf("\n\n--------------------------------GOODBYE!!------------------------------------\n\n");

    return 0;
}

void add() {
    system("cls");
    f=fopen("list.txt","a+");
    printf("\n\n\t\tCode:");
    scanf("%d",&item.code);
    printf("\t\tName:");
    scanf("%s",&item.name);
    printf("\t\tprice:");
    scanf("%lf",&item.price);
    fprintf(f,"\n%d\t%s\t%.2lf",item.code,item.name,item.price);
    printf("\nItem success fully added.\n");
    fclose(f);
    printf("\nPress any key to main menu.");
    getchar();
    while (getchar() != '\n');
    main();


}

void Searchby_code() {
    int code;
    int found = 0;
    FILE *file = fopen("list.txt", "r");
    if (file == NULL) {
        printf("\nFile not found.\n");
        printf("\nPress any key to return to the main menu.");
        return;
    }
    printf("\n\n\n\t\t\tEnter code: ");
    scanf("%d", &code);
    printf("\n\t\tCode\tName\tPrice\n");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int file_code;
        char name[256];
        double price;
        if (sscanf(line, "%d\t%s\t%lf", &file_code, name, &price) == 3) {
            if (code == file_code) {
                printf("\n\t\t%d\t%s\t%.2lf\n", file_code, name, price);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("\nNot found.\n");
    }
    fclose(file);
    printf("\nPress any key to return to the main menu.");
    getchar(); // consume the newline character
    while (getchar() != '\n'); // consume any additional characters in the input buffer
    main();
}

void Searchby_price() {
    system("cls");
    int rt, count = 0;
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");

        return;
    }
    printf("\n\n\n\t\t\tEnter price:");
    scanf("%d",&rt);
    printf("\n\t\tCode\tName\tprice\n");
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf",&item.code,item.name,&item.price);
        if(rt==(int)item.price) {
            printf("\n\t\t%d\t%s\t%.2lf\n",item.code,item.name,item.price);
            count++;
        }
    }
    if(count == 0)
        printf("\nNot Found!!\n");
    else
        printf("\nTotal items with price %.2lf: %d\n", (double)rt, count);
    fclose(f);
    printf("\nPress any key to main menu.");
    getchar();
    while (getchar() != '\n');
    main();
}

void Searchby_name() {
    system("cls");
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        return;
    }
    char nm[20];
    printf("\n\n\n\t\t\tEnter name:");
    scanf("%s",nm);
    flag=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item.code,item.name,&item.price);
        if(!stricmp(nm,item.name)) {
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nNot Found!!\n");
    else {
        printf("\n\t\tCode\tName\tprice\n");
        printf("\n\t\t%d\t%s\t%.2lf\n",item.code,item.name,item.price);
    }
    fclose(f);
    printf("\nPress any key to main menu.");
    getchar();
    while (getchar() != '\n');
    main();
}


void Viewby_name() {
    system("cls");
    f = fopen("list.txt","r");
    if(f == NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        return;
    }

    product item[100];
    int i = 0;

    while (fscanf(f, "%d\t%s\t%lf\n", &item[i].code, item[i].name, &item[i].price) == 3) {
        i++;
    }

    fclose(f);

    for (int k = 0; k < i - 1; k++) {
        for (int j = k + 1; j < i; j++) {
            if (strcmp(item[k].name, item[j].name) > 0) {
                // Swap items
                product tmp = item[k];
                item[k] = item[j];
                item[j] = tmp;
            }
        }
    }

    printf("\n\t\tName            Code       price\n");
    for (int k = 0; k < i; k++) {
        printf("\t\t%-11s   %6d   %8.2lf\n", item[k].name, item[k].code, item[k].price);
    }

    printf("\nPress any key to main menu.");
    getchar();
    while (getchar() != '\n');
    main();
}

void Viewby_price() {
    system("cls");
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        return;
    }
    product item[100];
    double tmp;
    char temp[20];
    i=0;

    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item[i].code,item[i].name,&item[i].price);
        i++;
    }
    fclose(f);

    for(k=0; k<i; k++) {
        for(j=k; j<i; j++) {
            if(item[k].price > item[j].price) {
                tmp=item[k].price;
                item[k].price=item[j].price;
                item[j].price=tmp;

                item[k].code=item[k].code^item[j].code;
                item[j].code=item[k].code^item[j].code;
                item[k].code=item[k].code^item[j].code;

                strcpy(temp,item[k].name);
                strcpy(item[k].name,item[j].name);
                strcpy(item[j].name,temp);

            }
        }
    }
    printf("\n\t\t    price   Name            Code\n");
    for(k=0; k<i; k++)
        printf("\t\t%8.2lf   %-11s   %6d\n", item[k].price, item[k].name, item[k].code);

    printf("\nPress any key to main menu.");
    getchar();
    while (getchar() != '\n');
    main();
}


    void Viewby_code() {
    system("cls");
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        return;
    }
    product item[100];
    double tmp;
    char temp[20];
    i=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item[i].code,item[i].name,&item[i].price);
        i++;
    }
    fclose(f);
    rewind(f);
    for(k=0; k<i; k++) {
        for(j=k; j<i; j++) {
            if(item[k].code>item[j].code) {
                tmp=item[k].price;
                item[k].price=item[j].price;
                item[j].price=tmp;

                item[k].code=item[k].code^item[j].code;
                item[j].code=item[k].code^item[j].code;
                item[k].code=item[k].code^item[j].code;

                strcpy(temp,item[k].name);
                strcpy(item[k].name,item[j].name);
                strcpy(item[j].name,temp);

            }
        }
    }
    printf("\n\t\t  Code   Name              price\n");
    for(k=0; k<i; k++)
        printf("\t\t%6d   %-11s   %8.2lf\n",item[k].code,item[k].name,item[k].price);
    printf("\nPress any key to main menu.");
    getchar();
    while (getchar() != '\n');
    main();
}

void Buyby_Name() {
    system("cls");
    FILE *dlt;
    double p=-1;
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        return;
    }
    dlt=fopen("temp.txt","w");
    char namedlt[15];
    printf("\n\n\t\tEnter item name:");
    scanf("%s",namedlt);
    flag=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item.code,item.name,&item.price);
        if(!stricmp(namedlt,item.name)) {
            flag=1;
            while(1) {
                printf("\nIn order to buy this item,please pay %.2lf RON(0 to discard):",item.price);
                scanf("%lf",&p);
                if(p==0)break;
                if(p==item.price) {
                    printf("\nYou bought this item.Enjoy!\n");
                    p=1;
                    break;
                }
            }
        }
        if(p!=1)
            fprintf(dlt,"%d\t%s\t%.2lf\n",item.code,item.name,item.price);
        p=-1;
    }
    fclose(f);
    fclose(dlt);
    if(flag==0)
        printf("\nName not found\n");
    remove("list.txt");
    rename("temp.txt","list.txt");
    fclose(f);
    printf("\nPress any key to main menu.");
    getchar();
    while (getchar() != '\n');
    main();
}

void Buyby_Code() {
    system("cls");
    FILE *dlt;
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        return;
    }
    dlt=fopen("temp.txt","w");
    int codlt;
    double paid, price;
    printf("\n\n\t\tEnter item code:");
    scanf("%d",&codlt);
    int found = 0;
    while(fscanf(f,"%d\t%s\t%lf\n",&item.code,item.name,&item.price) == 3) {
        if(codlt==item.code) {
            found = 1;
            while(1) {
                printf("\nPlease pay %.2lf RON(0 to discard):",item.price);
                scanf("%lf",&paid);
                if(paid == 0) {
                    fprintf(dlt,"%d\t%s\t%.2lf\n",item.code,item.name,item.price);
                    break;
                }
                if(paid == item.price) {
                    printf("\nYou bought this item. Congrats!\n");
                    break;
                }
            }
        } else {
            fprintf(dlt,"%d\t%s\t%.2lf\n",item.code,item.name,item.price);
        }
    }
    fclose(f);
    fclose(dlt);
    if(!found) {
        printf("\nCode not found\n");
    } else {
        remove("list.txt");
        rename("temp.txt","list.txt");
    }
    printf("\nPress any key to main menu.");
    getchar();
    while (getchar() != '\n');
    main();
}
