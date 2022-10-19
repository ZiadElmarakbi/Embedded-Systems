
#ifndef STATES_H_
#define STATES_H_

#include "BareMetalDriver.h"

 /* Creating Automatic Preprocessor Macros
    with Arguments for defining all the
    state functions */

#define Define_State(state) void ST_##state()
#define State(state) ST_##state

#endif /* STATES_H_ */
