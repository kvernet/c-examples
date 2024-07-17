#include "ptrack.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415

int main(int argc, char ** argv) {
	if(argc < 2) {
		fprintf(stderr, "Usage:\n");
		fprintf(stderr, "\t%s EVENTS\n", argv[0]);
		return EXIT_FAILURE;
	}
	const int events = atoi(argv[1]);
	
	size_t index = 0;
	pfloat energy = 3000.;
	pfloat3 position = {0., 0., 0.};
	pfloat3 direction = {0., 0., 1.};
	pfloat weight = 1.;
	
	ptrack * track = NULL;
	
	ptrack_init(&track,
		index, energy,
		position, direction
	);
	
	/* ballistic particle */
	int i;
	for(i = 0; i < events; i++) {
		index++;
		energy -= 1./(i + 1);
		position.z += 1./sin((i*i + 1)*PI/180);
		weight = fabs(position.z / energy);
		ptrack_push(&track,
			index, energy,
			position, direction,
			weight
		);
	}
	
	/* print track */
	ptrack_print(track);
	
	/* free allocated memories and exit */
	ptrack_free(&track);
	
	return EXIT_SUCCESS;
}
