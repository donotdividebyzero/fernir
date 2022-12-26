#ifndef __THOR_VECTOR_H
#define __THOR_VECTOR_H


#ifdef __cplusplus
    extern "C" {
#endif

typedef struct {
    float x,y,z,w;
} Vec4;

typedef struct {
    float x,y,z;
} Vec3;

typedef struct {
    float x,y;
} Vec2;


#ifdef __cplusplus
    }
#endif

#endif