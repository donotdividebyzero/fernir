#ifndef __THOR_TEXTURE_H
#define __THOR_TEXTURE_H

typedef struct {
    unsigned int id;
} Texture2d;

Texture2d LoadTexture(const char*);

#endif