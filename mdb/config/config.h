#pragma once

/*DO NOT EDIT THIS FILE IT WILL BE OVERWRITTEN
* EDIT config.cmake INSTEAD!*/

/* This file contains compile time options
 * Make sure your compiler and hardware support
 * features that you want to enable like AVX and FMA
 */

/* ---------------------------------------------------
 * Logging parameters
 * -------------------------------------------------*/

/* Show time of a log record */
#define LOG_SHOW_TIME

/* Show date of a log record */
#define LOG_SHOW_DATE

/* Show thread ID where logging record is coming from */
#define LOG_SHOW_THREAD

/* Show a full source file path and a line number
 * where is a log record coming from
 * Useful when debugging */
/* #undef LOG_SHOW_PATH */

/* If enabled protect logging functions with a mutex */
#define LOG_ENABLE_MULTITHREADING

/* ---------------------------------------------------
 * Kernel parameters
 * -------------------------------------------------*/

/* Turn on debugging in the kernel.
 * This may lead to a huge performance impact and a massive verbose output.
 * Don't enable it unless you know what you're doing.
 */
/* #undef MDB_KERNEL_DEBUG */

/* Enable building a kernel that using avx2 and fma instruction sets.
 * Written in intrinsics to maximize performance gain of vectorisation CPU extension.
 * Your CPU and compiler must support AVX2 and FMA features.
 */
#define MDB_ENABLE_AVX2_FMA_KERNEL

/* Enable building a kernel that using avx2 instruction set ( without using FMA )
 * thus this may be slightly slower than that one above which using FMA.
 * This kernel is also written in intrinsics to maximize performance gain of vectorisation CPU extension.
 * Your CPU and compiler must support AVX2 feature.
 */
#define MDB_ENABLE_AVX2_KERNEL

/* Enable building a kernel that is written in regular way ( plain C without intrinsics )
 * and let your compiler handle all optimisations by itself.
 * Performance of this kernel usually low, but it depends on how is your compiler doing his optimization job.
 * When building this kernel try to enable all available CPU extension and fast math by specifying
 * compiler flags like -march=native -ffast-math, etc.
 * This kernel uses the same code as 'generic' kernel, but the difference is in
 * for the generic kernel compiler disables all CPU extensions sse,avx,fma,etc and builds it
 * with using x87 coprocessor math instead of default for x86-64 - sse math.
 * Thus 'native' kernel performance is an example of how compiler can optimise code for a specific CPU.
 * But both kernels shares other compiler flags like -O3 -ffast-math, etc, so 'native' kernel
 * shows only how compiler uses vectorisation for optimisations.
 */
#define MDB_ENABLE_NATIVE_KERNEL

/* Enable building a kernel that is written in x86 assembly using NASM
 * This kernel requires NASM compiller available in /usr/bin/nasm
 * and CPU with AVX2,FMA support.
 * It also requares external kernel support.
 */
#define MDB_ENABLE_AVX_FMA_ASM_KERNEL


/* ---------------------------------------------------
 * Render parameters
 * -------------------------------------------------*/

/* Enable building render engine based on OpenGL 4.4.
 * The main advantage of using this engine is persistent buffer mapping
 * available since version 4.4 of OpenGL.
 * Persistent buffer mapping reduces overhead on transfering memory from
 * CPU to GPU.
 * It potentyaly gives better performance on CPU kernels.
 */
#define OGL_RENDER_ENABLED
