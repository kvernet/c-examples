#ifndef ptrack_h
#define ptrack_h

#include "pstate.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ptrack {
	pstate * initial;
	size_t size;
}ptrack;

void ptrack_init(
	ptrack ** track,
	size_t index,
	pfloat energy,
	pfloat3 position,
	pfloat3 direction
);

void ptrack_push(
	ptrack ** track,
	size_t index,
	pfloat energy,
	pfloat3 position,
	pfloat3 direction,
	pfloat weight
);

void ptrack_print(
	ptrack * track
);

void ptrack_free(
	ptrack ** track
);

#ifdef __cplusplus
}
#endif

#endif
