#include "pstate.h"

#include <stdlib.h>

void pstate_create(
	pstate ** state,
	size_t index,
	pfloat energy,
	pfloat3 position,
	pfloat3 direction,
	pfloat weight,
	pstate * child
) {
	*state = (pstate*)malloc(sizeof(pstate));
	(*state)->index = index;
	(*state)->energy = energy;
	(*state)->position = position;
	(*state)->direction = direction;
	(*state)->weight = weight;
	(*state)->child = child;
}

void pstate_free(
	pstate ** state
) {
	if(*state == NULL) return;
	free(*state);
	*state = NULL;
}
