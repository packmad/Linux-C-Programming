#include <stdio.h>
#include <string.h>


enum strategy {WORK, SLEEP};

// use a typedef to shorten the variable declarations
typedef enum {MON, TUE, WED, THU, FRI, SAT, SUN} day_of_week;

// under the hood enum are integers!
typedef enum {J_CHRIST=33, LIFE=42, B_JACK=21} famous_int;

int main( ) {
	enum strategy my_strategy;
	day_of_week dow;
	famous_int fi;
	
	my_strategy = SLEEP;
	
	switch (my_strategy) {
		case WORK:
			dow = MON;
			break;
		case SLEEP:
			dow = SUN;
			break;
	}
	
	fi = LIFE;
	
	// otherwise enums starts from 0
	if (fi == LIFE && dow == 6) {
		printf("WORK == %d\n", WORK);
		printf("SLEEP == %d\n", SLEEP);
	}
}
