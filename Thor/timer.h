#ifndef __THOR_TIMER_H
#define __THOR_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef float Timestep;

Timestep GetTimeStep();

float GetTime();

#ifdef __cplusplus
}
#endif

#endif