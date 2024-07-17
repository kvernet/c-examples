#include "ptrack.h"

#include <stdio.h>
#include <stdlib.h>

void ptrack_init(
	ptrack ** track,
	size_t index,
	pfloat energy,
	pfloat3 position,
	pfloat3 direction
) {
	*track = (ptrack*)malloc(sizeof(ptrack));
	pstate * state = NULL;
	pstate_create(
		&state, index,
		energy, position,
		direction, 1.,
		NULL
	);
	(*track)->initial = state;
	(*track)->size = 1;
}

void ptrack_push(
	ptrack ** track,
	size_t index,
	pfloat energy,
	pfloat3 position,
	pfloat3 direction,
	pfloat weight
) {
	if(*track == NULL) return;
	pstate * state = NULL;
	pstate_create(
		&state, index,
		energy, position,
		direction, weight,
		NULL
	);
	pstate * last = (*track)->initial;
	size_t i;
	for(i = 0; i < (*track)->size - 1; i++) {
		last = last->child;
	}
	last->child = state;
	(*track)->size++;
}

void ptrack_print(
	ptrack * track
) {
	printf("=== track print ===\n");
	if(track == NULL) return;
	
	pstate * state = track->initial;
	size_t i;
	for(i = 0; i < track->size; i++) {
		printf("index    : %ld\n", state->index);
		printf("energy   : %.3E MeV\n", state->energy);
		printf("position : (%.2f, %.2f, %.2f) cm\n",
			state->position.x, state->position.y, state->position.z);
		printf("direction: (%.2f, %.2f, %.2f)\n",
			state->direction.x, state->direction.y, state->direction.z);
		printf("weight   : %.3E\n", state->weight);
		state = state->child;
	}
}

void ptrack_free(
	ptrack ** track
) {
	if(*track == NULL) return;
	pstate * state = (*track)->initial;
	size_t i;
	for(i = 0; i < (*track)->size; i++) {
		pstate * tmp = state->child;
		pstate_free(&state);
		state = tmp;
	}
	free(*track);
	track = NULL;
}
