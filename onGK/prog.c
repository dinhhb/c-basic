#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char code[20];
    char name[50];
    float price;
    int quantity;
} Item;

void loadItemsFromFile(const char* filename, Item* items, int* itemCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(file, "%d", itemCount);
    for (int i = 0; i < *itemCount; i++) {
        fscanf(file, "%s %s %f %d", items[i].code, items[i].name, &items[i].price, &items[i].quantity);
    }

    fclose(file);
}

void displayItemInfo(const Item* items, int itemCount, const char* code) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].code, code) == 0) {
            printf("Mã số: %s\n", items[i].code);
            printf("Tên mặt hàng: %s\n", items[i].name);
            printf("Giá tiền: %.2f\n", items[i].price);
            printf("Số lượng trong kho: %d\n", items[i].quantity);
            return;
        }
    }
    printf("Không tìm thấy mặt hàng có mã số %s\n", code);
}

void createOrder(Item* items, int itemCount) {
    char inputCode[20];
    int inputQuantity;
    float total = 0.0;

    printf("Tạo đơn hàng:\n");
    while (1) {
        printf("Nhập mã số mặt hàng (nhập STOP để kết thúc): ");
        scanf("%s", inputCode);
        if (strcmp(inputCode, "STOP") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < itemCount; i++) {
            if (strcmp(items[i].code, inputCode) == 0) {
                found = 1;
                printf("Nhập số lượng: ");
                scanf("%d", &inputQuantity);
                if (inputQuantity <= items[i].quantity) {
                    total += items[i].price * inputQuantity; // Update total based on inputQuantity
                    items[i].quantity -= inputQuantity; // Update the quantity of the item
                } else {
                    printf("Lỗi: Số lượng không đủ trong kho.\n");
                }
                break;
            }
        }
        if (!found) {
            printf("Lỗi: Không có mặt hàng có mã số %s\n", inputCode);
        }
    }

    printf("Đơn hàng:\n");
    printf("STT   Mặt hàng    Đơn giá   Số lượng   Thành tiền\n");
    float orderTotal = 0.0; // Initialize orderTotal to 0
    for (int i = 0; i < itemCount; i++) {
        int sold = items[i].quantity; // Calculate the sold quantity
        float itemTotal = items[i].price * (items[i].quantity - sold); // Calculate the total for the item
        printf("%d     %s       %.2f       %d             %.2f\n", i + 1, items[i].name, items[i].price, items[i].quantity - sold, itemTotal); // Update the quantity and itemTotal
        orderTotal += itemTotal; // Update the orderTotal
    }
    printf("Tổng tiền: %.2f\n", orderTotal); // Print the orderTotal
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    Item items[100];
    int itemCount = 0;

    loadItemsFromFile(argv[1], items, &itemCount);

    int choice;
    char code[20];
    do {
        printf("1. Xem thông tin mặt hàng\n");
        printf("2. Tạo đơn hàng\n");
        printf("3. Thoát\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập mã số mặt hàng: ");
                scanf("%s", code);
                displayItemInfo(items, itemCount, code);
                break;
            case 2:
                createOrder(items, itemCount);
                break;
            case 3:
                printf("Thoát\n");
                break;
            default:
                printf("Chức năng không hợp lệ\n");
        }
    } while (choice != 3);

    return 0;
}