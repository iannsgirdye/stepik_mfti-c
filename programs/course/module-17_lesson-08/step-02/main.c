#include <stdio.h>
#include <stdlib.h>


#define MAX_STEPS     1000000
#define COUNT_CARDS   5
#define COUNT_PLAYERS 2


typedef int Data;
struct Node {
    struct Node *prev;
    struct Node *next;
    Data value;
};


// инициализация
void list_init(struct Node *list) {
    list->prev = list;
    list->next = list;
    list->value = -1;
}


// вставка new_node после node_prev
void list_insert(struct Node *node_prev, struct Node *new_node) {
    new_node->prev = node_prev;
    new_node->next = node_prev->next;
    node_prev->next->prev = new_node;
    node_prev->next = new_node;
}


// удаление node
void list_remove(struct Node *node) {
    Data data = node->value;
    node->prev->next = node->next;
    node->next->prev = node->prev;
}


// проверка на пустоту
int list_is_empty(struct Node *list) {
    return (list->next == list)? 1 : 0;
}


// печать узлов через пробел
void list_print(struct Node *list) {
    printf("[ ");
    for (struct Node *node = list->next; node != list; node = node->next) {
        printf("%d ", node->value);
    }
    printf("]");
}


// вскрытие одной карты
void cards_put(struct Node *player_1, struct Node *player_2) {
    struct Node *player_1_card = player_1->next;
    struct Node *player_2_card = player_2->next;

    list_remove(player_1_card);
    list_remove(player_2_card);
    struct Node *winner;

    if (player_1_card->value == 0 && player_2_card->value == 9) {  // "шестерка бьет туза"
        winner = player_1;                         // победитель хода
    }
    else if (player_2_card->value == 0 && player_1_card->value == 9) {
        winner = player_2;
    }
    else {
        winner = (player_1_card->value > player_2_card->value)? player_1 : player_2;
    }
    
    list_insert(winner->prev, player_1_card);
    list_insert(winner->prev, player_2_card);
}


// проверка, есть ли победитель 
int cards_check(struct Node *player_1, struct Node *player_2, int steps) {
    if (steps > MAX_STEPS) {
        return 3;   
    }
    if (list_is_empty(player_1)) {
        return 2;
    }
    if (list_is_empty(player_2)) {
        return 1;
    }
    return 0;
}


// процесс игры
void game(struct Node *player_1, struct Node *player_2) {
    static int steps = 0;  // количество шагов
    int result;
    
    while((result = cards_check(player_1, player_2, steps)) == 0) {
        cards_put(player_1, player_2);
        steps++;
    }

    switch (result) {
    case 1:
        printf("first %d\n", steps);
        break;
    case 2:
        printf("second %d\n", steps);
        break;
    case 3:
        printf("botva");
        break;
    }
}


// считывание карт
void cards_scan(struct Node *cards) {
    for (int i = 0; i < COUNT_PLAYERS; i++) {
        for (int j = 1; j <= COUNT_CARDS; j++) {
            int index = i * COUNT_CARDS + j + i;
            scanf("%d", &(cards[index].value));
            list_insert(&cards[index - 1], &cards[index]);
        }
    }
}


int main() {
    size_t cards_size = COUNT_CARDS * 2 + COUNT_PLAYERS * 2;  // 5*2 на карты и 1*2 на служебные узлы
    struct Node *cards = malloc(cards_size * sizeof(struct Node));
    struct Node *player_1 = cards;
    struct Node *player_2 = cards + 1 + COUNT_CARDS;  // [player1][][][][][][player2][][][][][]
    
    list_init(player_1);
    list_init(player_2);

    cards_scan(cards);

    game(player_1, player_2);
    free(cards);

    return 0;
}
