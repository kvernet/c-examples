#ifndef pstate_h
#define pstate_h

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef float pfloat;

typedef struct pfloat3 {
	pfloat x;
	pfloat y;
	pfloat z;
}pfloat3;

typedef struct pstate pstate;

struct pstate {
	size_t index;
	pfloat energy;
	pfloat3 position;
	pfloat3 direction;
	pfloat weight;
	pstate * child;
};

void pstate_create(
	pstate ** state,
	size_t index,
	pfloat energy,
	pfloat3 position,
	pfloat3 direction,
	pfloat weight,
	pstate * child
);

void pstate_free(
	pstate ** state
);


#ifdef __cplusplus
}
#endif

#endif
