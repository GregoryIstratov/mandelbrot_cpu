#pragma once

/* OpenGL render engine
 * This engine creates a memory buffer for cpu rendering
 * and renders the buffer to the screen applying shader coloring if enabled.
 *
 * This engine requires the next OpenGL features:
 * OpenGL version >= 3.2
 * GL_ARB_buffer_storage
 *
 * GL_KHR_debug and GL_ARB_debug_output - if enabled in config
 *
 * It's been successfully testes on:
 * Nvidia GTX+ 580 on linux, Nvidia proprietary drivers
 * Intel Core i5 4670K, integrated graphics on linux (4.12 kernel), Mesa 17.2.1
 * Intel Celeron B820 1.7 GHz, integrated graphics on linux 4.13, Mesa 17.2.1
 */

#include <stdint.h>
#include <stdbool.h>

#include "ogl_pixel_buffer.h"

typedef void(*ogl_render_key_callback)(void*, int, int, int, int);

typedef void(*ogl_render_resize_callback)(int,int, void*);

typedef struct _ogl_render ogl_render;

void ogl_render_create(ogl_render** rend, const char* win_title,
                       uint32_t width, uint32_t height, void* user_ctx);

void ogl_render_init_render_target(ogl_render* rend,
                                   ogl_data_update_callback cb);

void ogl_render_init_screen(ogl_render* rend, bool color_enabled);

void ogl_render_set_resize_callback(ogl_render* rend,
                                    ogl_render_resize_callback cb);

void ogl_render_set_key_callback(ogl_render* rend, ogl_render_key_callback cb);

void ogl_render_render_loop(ogl_render* rend);

void ogl_render_destroy(ogl_render* rend);

