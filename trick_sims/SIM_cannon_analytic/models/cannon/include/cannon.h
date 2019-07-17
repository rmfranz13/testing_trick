/*************************************************************************
PURPOSE: (Represent the state and initial conditions of a cannonball)
**************************************************************************/
#ifndef CANNON_H
#define CANNON_H

typedef struct {

    double vel0[2] ;
    double pos0[2] ;
    double init_speed ; 
    double init_angle ;

    double acc[2] ;  
    double vel[2] ;   
    double pos[2] ;    

    double time;    

    int impact ; 
    double impactTime;  

} CANNON ;

#ifdef __cplusplus
extern "C" {
#endif
    int cannon_default_data(CANNON*) ;
    int cannon_init(CANNON*) ;
    int cannon_shutdown(CANNON*) ;
#ifdef __cplusplus
}
#endif

#endif