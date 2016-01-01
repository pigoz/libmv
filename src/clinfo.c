#include <mv.h>
#include <stdio.h>
#include "ta.h"

static void mv_clinfo_info_device(void *ta_ctx, cl_device_id did) {
    const char* device_attrs[] = {
        "Device Name", "Device Version", "Driver Version",
        "Device CL C Version", "Device Extensions" };
    const cl_device_info device_attr_types[] = {
        CL_DEVICE_NAME, CL_DEVICE_VERSION, CL_DRIVER_VERSION,
        CL_DEVICE_OPENCL_C_VERSION, CL_DEVICE_EXTENSIONS };
    const int device_attrs_size = MV_ARRAY_SIZE(device_attrs);

    for (int i = 0; i < device_attrs_size; i++) {
        size_t info_size;
        clGetDeviceInfo(did, device_attr_types[i], 0, NULL, &info_size);
        char *info = ta_znew_array(ta_ctx, char, info_size);
        clGetDeviceInfo(did, device_attr_types[i], info_size, info, NULL);
        printf("   .%d %-11s: %s\n", i+1, device_attrs[i], info);
    }

    cl_uint max_compute_units;
    char compute_units[] = "Device Max Compute Units";
    clGetDeviceInfo(did, CL_DEVICE_MAX_COMPUTE_UNITS,
                    sizeof(max_compute_units), &max_compute_units, NULL);
    printf("   .%d %-11s: %d\n", device_attrs_size, compute_units, max_compute_units);
}

static void mv_clinfo_info_platform(void *ta_ctx, cl_platform_id pid) {
    const char* platform_attrs[] = {
        "Name", "Vendor", "Version", "Profile", "Extensions" };
    const cl_platform_info platform_attr_types[] = {
        CL_PLATFORM_NAME, CL_PLATFORM_VENDOR, CL_PLATFORM_VERSION,
        CL_PLATFORM_PROFILE, CL_PLATFORM_EXTENSIONS };
    const int platform_attrs_size = MV_ARRAY_SIZE(platform_attrs);

    for (int j = 0; j < platform_attrs_size; j++) {
        size_t info_size;
        clGetPlatformInfo(pid, platform_attr_types[j], 0, NULL, &info_size);
        char *info = ta_znew_array(ta_ctx, char, info_size);
        clGetPlatformInfo(pid, platform_attr_types[j], info_size, info, NULL);
        printf(" .%d %-11s: %s\n", j+1, platform_attrs[j], info);
    }

    // devices info
    cl_uint devices_size;
    clGetDeviceIDs(pid, CL_DEVICE_TYPE_ALL, 0, NULL, &devices_size);
    cl_device_id *devices = ta_znew_array(ta_ctx, cl_device_id, devices_size);
    clGetDeviceIDs(pid, CL_DEVICE_TYPE_ALL, devices_size, devices, NULL);
    for (int i = 0; i < devices_size; i++) {
        mv_clinfo_info_device(ta_ctx, devices[i]);
    }
}

void mv_clinfo() {
    void *ta_ctx = ta_new_context(NULL);
    cl_uint platforms_size;
    cl_platform_id *platforms;

    clGetPlatformIDs(0, NULL, &platforms_size);
    platforms = ta_znew_array(ta_ctx, cl_platform_id, platforms_size);
    clGetPlatformIDs(platforms_size, platforms, NULL);

    for (int i = 0; i < platforms_size; i++) {
        printf("%d. Platform \n", i+1);
        mv_clinfo_info_platform(ta_ctx, platforms[i]);
    }

    ta_free(ta_ctx);
}
