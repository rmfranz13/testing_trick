/********************************TRICK HEADER**********************************
 * PURPOSE: (Set the initial data values)
 *****************************************************************************/
//Trick will compile this file and link to simulation executable.
//The return values of these functions can be used to terminate the simulation
//via trick_ret in S_define
/*Model Include files */
#include <math.h>
#include "../include/cannon.h"


/* default data job */
int cannon_default_data(CANNON* C)
{
    (*C).acc[0] = 0.0;
    (*C).acc[1] = -9.81;
    (*C).init_angle = M_PI/6;
    (*C).init_speed = 50.0;
    (*C).pos0[0] = 0.0;
    (*C).pos0[1] = 0.0;

    (*C).time = 0.0;

    (*C).impact = 0;
    (*C).impactTime = 0.0;

    return(0);
}

/* initialization job */
int cannon_init(CANNON* C)
{
    (*C).vel0[0] = (*C).init_speed*cos((*C).init_angle);
    (*C).vel0[1] = (*C).init_speed*sin((*C).init_angle);

    (*C).vel[0] = (*C).vel0[0];
    (*C).vel[1] = (*C).vel0[1];

    (*C).impactTime = 0.0;
    (*C).impact = 0.0;

    return(0);
}