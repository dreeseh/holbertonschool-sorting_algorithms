#ifndef __DECK_H__
#define __DECK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * enum kind_e - suits in the deck
 * @SPADE: one of 4 suits
 * @HEART: one of 4 suits
 * @CLUB: one of 4 suits
 * @DIAMOND: one of 4 suits
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void card_swap(deck_node_t **deck, deck_node_t *node);
size_t deck_len(const deck_node_t *h);
int cardtoi(deck_node_t *node);
void sort_deck(deck_node_t **deck);

#endif /* __DECK_H__ */
