#include <stdio.h>
#include <string.h>

void AddContactF (char name[], char phone_number[], char email[]){
    printf("\nSaving Information to 'contacts.txt'\n");
    
    FILE *pfile;
    pfile = fopen("contacts.txt", "a");
    fprintf(pfile, "%s|%s|%s\n", name, phone_number, email);
    fclose(pfile);
    printf("Saved!");
}

void DeleteContactF (char name[], char phone_number[], char email[]){
    FILE *pfile;
    FILE *pfile2; 
    pfile = fopen("contacts.txt", "r");
    pfile2 = fopen("temp.txt", "w");
    int found = 0;

    char String[100];
    char f_name[40], f_phone_number[40], f_email[40];

    while (fgets(String, sizeof String, pfile) != NULL) {
        if (sscanf(String, "%39[^|]|%39[^|]|%39[^\n]", f_name, f_phone_number, f_email) != 3){ continue; }
        if (strcmp(f_name, name) == 0) { 
            found = 1;
            continue;
        }
        else { fprintf(pfile2, "%s|%s|%s\n", f_name, f_phone_number, f_email); }
    }

    fclose(pfile2);
    fclose(pfile);
    
    if (found){ printf("Contact deleted.\n"); }
    else { printf("Contact not found.\n"); }

    if (remove("contacts.txt") != 0) {
        printf("Could not delete contacts.txt\n");
        return;
    }

    if (rename("temp.txt", "contacts.txt") != 0) {
        printf("Could not rename temp.txt\n");
        return;
    }

    printf("Done!\n");
    
}

void SearchContactF (char name[], char phone_number[], char email[]){
    FILE *pfile;
    pfile = fopen("contacts.txt", "r");

    char String[100];
    char f_name[40], f_phone_number[40], f_email[40];

    while (fgets(String, sizeof(String), pfile) != NULL) {
        if (sscanf(String, "%39[^|]|%39[^|]|%39[^\n]", f_name, f_phone_number, f_email) != 3){ continue; }
        if (strstr(f_name, name) != NULL) {printf("%s  %s  %s\n", f_name, f_phone_number, f_email);} 
    }
    
    fclose(pfile);
    
}


void clear (void) {
    while ( getchar() != '\n' );
}

void GetInputF(char name[], char phone_number[], char email[]) {
    printf("Please enter the phone number: \n");
    fgets(phone_number, 40, stdin);

    phone_number[strcspn(phone_number, "\n")] = '\0';

    printf("Please enter the name: \n");
    fgets(name, 40, stdin);

    name[strcspn(name, "\n")] = '\0';
    
    printf("Please enter email: \n");
    fgets(email, 40, stdin);

    email[strcspn(email, "\n")] = '\0';  
}

int main() {

    int choice;
    char phone_number[40];
    char email[40];
    char name[40];
    
    void (*oprations[3])(char*, char*, char*) = { AddContactF,  DeleteContactF, SearchContactF };

    printf("Hello welcome to Telephone Directory\n");
    printf("Please enter you choice\n");

    printf("1. Add Contact\n2. Delete Contact\n3. Search Contact\n");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid Input!\n");
        return 1;
    }

    clear();

    if (choice < 1 || choice > 3) {
        printf("Invalid Input!\n");
        return 1;
    }

    GetInputF(name, phone_number, email);
    oprations[choice-1](name, phone_number, email);

    return 0;
}