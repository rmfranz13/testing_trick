/******************************************************************************
 * PURPOSE: (Represent the state and initial conditions of a cannonball)
 *****************************************************************************/
#ifndef CANNON_H
#define CANNON_H

typedef struct
{
    //Comments are structured as: /* [*i][*o][*io][**] [units] [Comments] */
    //the comments next to the fields below follow this format and are readable to trick.
    //
    //the i/o specify whether it is an input or output or both
    //** means you don't want the parameter processed at all.
    //*io is default if not otherwise specified.
    //
    //Units are allow trick to use it's unit conversion capabilities
    //as well as plotting and other uses.
    //units of [--] assumes no units. There is no default for unit specs,
    //which is probably why you can't include things like booleans (see below)

    double vel0[2]; /* *i m/s initial velocity of cannonball */
    double pos0[2]; /* *i m initial position of cannonball */
    double init_speed; /* *i m/s initial barrel speed */
    double init_angle; /* *i rad initial angle of cannon */

    double acc[2];  /* *i m/s^2 xy-acceleration */
    double vel[2];  /* *i m/s xy-velocity */
    double pos[2];  /* *i m xy-position */

    double time;  /* *io s Model time */

    int impact; /* *io -- has an impact occured? (why not a boolean?) */
    double impactTime; /* *io s Time of Impact */
} CANNON;

#ifdef __cplusplus
extern "C" 
{
    #endif
        int cannon_default_data(CANNON*);
        int cannon_init(CANNON*);
        int cannon_shutdown(CANNON*);
    #ifdef __cplusplus
}
#endif
#endif