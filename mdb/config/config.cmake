# =====================================================
# This file contains compile time options             #
# Make sure your compiler and hardware support        #
# features that you want to enable like AVX and FMA   #
#                                                     #
# To enable option just set it ON to disable OFF      #
# =====================================================


#======================================================
# Logging parameters                                  #
#======================================================

# Show time of a log record
set(LOG_SHOW_TIME ON)

# Show date of a log record
set(LOG_SHOW_DATE ON)

# Show thread ID where logging record is coming from"
set(LOG_SHOW_THREAD ON)

# Show a full source file path and a line number
# where is a log record coming from
# Useful when debugging
#
set(LOG_SHOW_PATH ON)

# If enabled protect logging functions with a mutex
set(LOG_ENABLE_MULTITHREADING ON)

#======================================================
# Kernel parameters                                   #
#======================================================

# Turn on debugging in the kernel.
# This may lead to a huge performance impact and a massive verbose output.
# Don't enable it unless you know what you're doing.
#
set(MDB_KERNEL_DEBUG OFF)

# Enable building a kernel that using avx2 and fma instruction sets.
# Written in intrinsics to maximize performance gain of vectorisation CPU extension.
# Your CPU and compiler must support AVX2 and FMA features.
#
set(MDB_ENABLE_AVX2_FMA_KERNEL ON)

# Enable building a kernel that using avx2 instruction set ( without using FMA )
# thus this may be slightly slower than that one above which using FMA.
# This kernel is also written in intrinsics to maximize performance gain of vectorisation CPU extension.
# Your CPU and compiler must support AVX2 feature.
#
set(MDB_ENABLE_AVX2_KERNEL ON)


# Enable building a kernel that is written in regular way ( plain C without intrinsics )
# and let your compiler handle all optimisations by itself.
# Performance of this kernel usually low, but it depends on how is your compiler doing his optimization job.
# When building this kernel try to enable all available CPU extension and fast math by specifying
# compiler flags like -march=native -ffast-math, etc.
# This kernel uses the same code as 'generic' kernel, but the difference is in
# for the generic kernel compiler disables all CPU extensions sse,avx,fma,etc and builds it
# with using x87 coprocessor math instead of default for x86-64 - sse math.
# Thus 'native' kernel performance is an example of how compiler may optimise code for specific CPU.
# But both kernels shares all other compiler flags like -O3 -ffast-math, etc, so 'native' kernel
# shows only how compiler uses vectorisation for optimisations.
#
set(MDB_ENABLE_NATIVE_KERNEL ON)


set(MDB_ENABLE_AVX_FMA_ASM_KERNEL ON)