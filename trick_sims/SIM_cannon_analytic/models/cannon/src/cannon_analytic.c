/******************************************************************************
 * PURPOSE: (Analytical Cannon)
 *****************************************************************************/
#include <stdio.h>
#include <math.h>
#include "../include/cannon_analytic.h"

int cannon_analytic(CANNON* C)
{
    (*C).acc[0] = 0.00;
    (*C).acc[1] = -9.81;
    (*C).vel[0] = (*C).vel0[0] + (*C).acc[0]*(*C).time;
    (*C).vel[1] = (*C).vel0[1] + (*C).acc[1]*(*C).time;
    (*C).pos[0] = (*C).pos0[0] +((((*C).vel0[0])+((0.5)*((*C).acc[0])))*(*C).time)*(*C).time;
    (*C).pos[1] = (*C).pos0[1] +((((*C).vel0[1])+((0.5)*((*C).acc[1])))*(*C).time)*(*C).time;

    if(((*C).pos[1])<0.0)
    {
        (*C).impactTime = (- C->vel0[1] - sqrt( C->vel0[1] * C->vel0[1] - 2 * C->pos0[1]))/C->acc[1];
        (*C).pos[0] = ((*C).impactTime)+((*C).vel0[0]);
        (*C).pos[1] = 0.0;
        (*C).vel[0] = 0.0;
        (*C).vel[1] = 0.0;
        if(!((*C).impact))
        {
            (*C).impact = 1;
            fprintf(stderr, "\n\nIMPACT: t = %.9f, pos[0] = %.9f\n\n", C->impactTime, C->pos[0] );
        }
    }
    /*Time increment must (or should?) match frequency as defined in S_define */
    (*C).time += 0.01;

    return(0);
}