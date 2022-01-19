#include <stdio.h>
#include <string.h>

int num=0;

struct player{
    char name[10],score[5];
    int age;
}p[100];

void create(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the name of player-%d: ",i+1);
        scanf("%s",p[i].name);
        fflush(stdin);
        printf("Enter the age: ");
        scanf("%d",&p[i].age);
        fflush(stdin);
    }
}

void riddle(int m)
{
    int i;
    char ans[50];
    for(i=0;i<num;i++)
    {
        if(p[i].age>10&&p[i].age<20)
        {
            printf("\nRiddle for player- %s\n",p[i].name);
            printf("If you were running a race, and you passed the person in 2nd place, what place would you be in now?\nAns: ");
            gets(ans);
            fflush(stdin);
            if(strcmp(ans,"2nd")==0)
            {
                strcpy(p[i].score,"Win");
            }
            else
            {
                strcpy(p[i].score,"Lose");
            }
        }
        else if(p[i].age>20&&p[i].age<30)
        {
            printf("\nRiddle for player- %s\n",p[i].name);
            printf("A man in a car saw a Golden Door, Silver Door and a Bronze Door. What door did he open first?\nAns: ");
            gets(ans);
            fflush(stdin);
            if(strcmp(ans,"car door")==0)
            {
                strcpy(p[i].score,"Win");
            }
            else
            {
                strcpy(p[i].score,"Lose");
            }
        }
        else if(p[i].age>30&&p[i].age<50)
        {
            printf("\nRiddle for player- %s\n",p[i].name);
            printf("What 4-letter word can be written forward, backward or upside down, and can still be read from left to right?\nAns: ");
            gets(ans);
            fflush(stdin);
            if(strcmp(ans,"NOON")==0)
            {
                strcpy(p[i].score,"Win");
            }
            else
            {
                strcpy(p[i].score,"Lose");
            }
        }
    }
}

void main()
{
    int i,start,new_age;
    char c,ch;
    FILE *fp;

    printf("\t\t  WELCOME TO THE RIDDLER'S PUZZLE\n\n");

    char user[10],pass[10];
    printf("Enter username: ");
    gets(user);
    fflush(stdin);
    printf("Enter password: ");
    gets(pass);
    fflush(stdin);

    if(strcmp(user,"riddler")==0)
    {
        if(strcmp(pass,"password")==0)
        {
            printf("\n\t\t\t  Login Success!\n\n");

            printf("Choose an option:\n1. Start game\n2. View previous scores\n3. Edit records\n4. Delete records\n5. Exit\n\n");
            printf("Option: ");
            scanf("%d",&start);

            switch(start)
            {
            case 1:
            printf("Enter the number of players: ");
            scanf("%d",&num);
            fflush(stdin);

            printf("\nPlease enter age from 10 to 50 only.\n");

            create(num);

            riddle(p[i].age);

            fp = fopen ("project.txt","w");
            if (fp == NULL)
            {
                printf("\nNo such file exists.\n\n");
            }
            else
            for(i = 0; i < num; i++)
                    fprintf(fp,"%s\n%d\n%s\n", p[i].name, p[i].age, p[i].score);

            fclose(fp);

            printf("\nDo you want to see the results?\nPress Y or N: ");
            scanf("%c",&c);

            if(c=='Y')
            {
                printf("\nThe results are:\n");

                for (i = 0; i < num; i++)
                {
                    printf("Name of player-%d: %s\n"
                           "Age: %d\n"
                           "Score: %s\n\n", i+1, p[i].name, p[i].age, p[i].score);
                }
            printf("\n\n\t\t\tPRESS ENTER TO EXIT");
            getch();
            }
            else if(c=='N')
            {
                printf("\n\n\t\t\tPRESS ENTER TO EXIT");
                getch();
            }
            break;

            case 2:
            printf("\nThe results are:\n");

            fp = fopen ("project.txt","r");

            if (!fp)
                printf("File Does not Exist\n\n");
            else
            {
                while (!feof(fp))
                {
                    fscanf(fp,"%s\n%d\n%s\n", p[i].name, &p[i].age, p[i].score);

                    printf("Name of player-%d: %s\n"
                           "Age: %d\n"
                           "Score: %s\n\n", i+1, p[i].name, p[i].age, p[i].score);
                    i++;
                    num++;
                }
            }

            fclose(fp);
            printf("\n\n\t\t\tPRESS ENTER TO EXIT");
                getch();
            break;

            case 3:
                printf("\nThe results are:\n");

            fp = fopen ("project.txt","r");

            if (!fp)
                printf("File Does not Exist\n\n");
            else
            {
                while (!feof(fp))
                {
                    fscanf(fp,"%s\n%d\n%s\n", p[i].name, &p[i].age, p[i].score);

                    printf("Name of player-%d: %s\n"
                           "Age: %d\n"
                           "Score: %s\n\n", i+1, p[i].name, p[i].age, p[i].score);
                    i++;
                    num++;
                }
            }

            fclose(fp);

                printf("Name of the Player to Edit: ");
                scanf("%s", user);
                fflush(stdin);

                for (i = 0; i < num; i++)
                {
                    if (strcmp(user, p[i].name) == 0)
                    {
                        printf("What is the new age? ->");
                        scanf("%d", &new_age);
                        fflush(stdin);

                        p[i].age = new_age;

                        FILE* fp = fopen ("project.txt","w");

                        if (!fp)
                            printf("\nNo such file exists.\n\n");

                        else
                        {
                            for(i = 0; i < num; i++)
                                fprintf(fp,"%s\n%d\n%s\n", p[i].name, p[i].age, p[i].score);
                        }

                        fclose(fp);
                        printf("Record edited successfully.\n");

                        break;
                    }
                    else
                    {
                        printf("Player doesn't exist.");
                    }
                }
                printf("\n\n\t\t\tPRESS ENTER TO EXIT");
                getch();

                break;

            case 4: printf("\nThe results are:\n");

            fp = fopen ("project.txt","r");

            if (!fp)
                printf("File Does not Exist\n\n");
            else
            {
                while (!feof(fp))
                {
                    fscanf(fp,"%s\n%d\n%s\n", p[i].name, &p[i].age, p[i].score);

                    printf("Name of player-%d: %s\n"
                           "Age: %d\n"
                           "Score: %s\n\n", i+1, p[i].name, p[i].age, p[i].score);
                    i++;
                    num++;
                }
            }

            fclose(fp);


                printf("Name of the Player to Delete: ");
                scanf("%s", user);
                fflush(stdin);

                for (i = 0; i < num; i++)
                {
                    if (strcmp(user, p[i].name) == 0)
                    {
                        for (;i < num-1; i++)
                            p[i] = p[i+1];

                        num--;
                        i++;

                        FILE* fp = fopen ("project.txt","w");

                        if (!fp)
                            printf("\nNo such file exists.\n\n");

                        else
                        {
                            for(i = 0; i < num; i++)
                                fprintf(fp,"%s\n%d\n%s\n", p[i].name, p[i].age, p[i].score);
                        }
                        printf("Record deleted successfully.");
                        fclose(fp);
                    }
                    else
                    {
                        printf("Player doesn't exist.");
                    }
                }

                printf("\n\n\t\t\tPRESS ENTER TO EXIT");
                getch();

            fclose(fp);
            break;
        case 5: break;
    }
    }
        else
        {
            printf("\nWrong password\n");
        }
    }
    else
    {
        printf("\nUser doesn't exist");
    }
}
