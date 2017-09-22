#pragma once

#include <stdint.h>

typedef struct _mdb_kernel mdb_kernel;

enum
{
    MDB_KERNEL_AVX_FMA,
    MDB_KERNEL_AVX,
    MDB_KERNEL_GENERIC,
    MDB_KERNEL_NATIVE
};

int mdb_kernel_create(mdb_kernel** pmdb, int kernel_type, int width, int height, int bailout);

void mdb_kernel_set_surface(mdb_kernel* mdb, float* f32surface);

void mdb_kernel_set_size(mdb_kernel* mdb, uint32_t width, uint32_t height);

void mdb_kernel_set_scale(mdb_kernel* mdb, float scale);

void mdb_kernel_set_shift(mdb_kernel* mdb, float shift_x, float shift_y);

void mdb_kernel_set_bailout(mdb_kernel* mdb, uint32_t bailout);

void mdb_kernel_submit_changes(mdb_kernel* mdb);

void mdb_kernel_process_block(mdb_kernel* mdb, uint32_t x0, uint32_t x1, uint32_t y0, uint32_t y1);