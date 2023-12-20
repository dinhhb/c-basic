/*
Hồ sơ sinh viên bao gồm:
• name: tên của sinh viên
• email: địa chỉ email của sinh viên
• Viết chương trình trong chế độ tương tác dòng lệnh thực hiện các
nghiệp vụ cơ bản trong quản lý hồ sơ sinh viên
• Đọc dữ liệu từ file văn bản vào danh sách
• In danh sách sinh viên
• Thêm 1 hồ sơ vào cuối danh sách
• Xóa 1 hồ sơ
• Tìm kiếm hồ sơ
• Lưu hồ sơ vào file văn bản
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Profile{
    int id;
    char name[256];
    char email[256];
    struct Profile *next;
}Profile;

Profile *first, *last;

Profile *makeProfile(int id, char *name, char *email){
    Profile *node = (Profile*)malloc(sizeof(Profile));
    node->id = id;
    strcpy(node->name, name);
    strcpy(node->email, email);
    node->next = NULL;
    return node;
}

void initList(){
    first = NULL;
    last = NULL;
}

int listEmpty(){
    return first == NULL && last == NULL;
}

void insertLast(int id, char *name, char *email){
    Profile *profile = makeProfile(id, name, email);
    if(listEmpty()){
        first = profile;
        last = profile;
    }else{
        last->next = profile;
        last = profile;
    }
}

void printList(){
    for(Profile *p = first; p != NULL; p = p->next)
        printf("%d %s %s\n", p->id, p->name, p->email);
}

Profile *removeProfile(Profile *f, char *name){
    if (listEmpty())
        return NULL;
    if (strcmp(f->name, name) == 0){
        Profile *tmp = f->next;
        free(f);
        if (tmp == NULL)
            last = NULL;
        return tmp;
    } else {
        f->next = removeProfile(f->next, name);
        return f;
    }
}

void load(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Load data -> file not found\n");
        return;
    }

    while (1) {
        Profile *profile1 = (Profile *)malloc(sizeof(Profile));

        if (fread(profile1, sizeof(Profile), 1, f) != 1) {
            free(profile1);  // Free the dynamically allocated memory
            break;  // Exit the loop when no more records can be read
        }

        insertLast(profile1->id, profile1->name, profile1->email);
    }

    fclose(f);
}


void processLoad(){
    char filename[256];
    scanf("%s", filename);
    load(filename);
}

void processFind(){
    char name[256];
    scanf("%s", name);
    Profile *profile = NULL;
    for (Profile *p = first; p != NULL; p = p->next){
        if (strcmp(p->name, name) == 0){
            profile = p;
            break;
        }
    }
    if (profile == NULL){
        printf("NOT FOUND profile %s\n", name);
    } else {
        printf("FOUND profile %d %s %s\n", profile->id, profile->name, profile->email);
    }
}

void processStore(){
    char filename[256];
    scanf("%s", filename);
    FILE *f = fopen(filename, "wb");
    for (Profile *p = first; p != NULL; p = p->next){
        fprintf(f,"%d %s %s", p->id, p->name, p->email);
        if (p->next != NULL) fprintf(f, "\n");
    }
    fclose(f);
}

void processInsert(){
    int id;
    char name[256], email[256];
    scanf("%d%s%s", &id, name, email);
    insertLast(id, name, email);
}

void processRemove(){
    char name[256];
    scanf("%s", name);
    first = removeProfile(first, name);
}

int main(){
    initList();
    while(1){
        printf("\nEnter command: ");
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "Quit") == 0) break;
        else if (strcmp(cmd,"Load")==0) processLoad();
        else if (strcmp(cmd, "Print") == 0) printList();
        else if (strcmp(cmd, "Find") == 0) processFind();
        else if (strcmp(cmd, "Insert") == 0) processInsert();
        else if (strcmp(cmd, "Remove") == 0) processRemove();
        else if (strcmp(cmd, "Store") == 0) processStore();
    }
}