/**
 * Copyright (C) 2015-2018 Think Silicon S.A. (https://think-silicon.com/)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public v3
 * License as published by the Free Software Foundation;
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 */

/**
 *  @file       WSIAndroid.cpp
 *  @author     Think Silicon, luo9674
 *  @date       20/9/2021
 *  @version    1.0
 *
 *  @brief      WSI Android module. It gets Android VkSurface.
 *
 */

#include "WSIAndroid.h"

EGLBoolean
WSIAndroid::SetSurfaceCallback(void)
{
    VK_LOAD
    
    FUN_ENTRY(DEBUG_DEPTH);

    PFN_vkCreateAndroidSurfaceKHR fpCreateAndroidSurfaceKHR = nullptr;

    fpCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR) vk_GetInstanceProcAddr(mVkInstance, "vkCreateAndroidSurfaceKHR");
    if(fpCreateAndroidSurfaceKHR == nullptr) {
        assert(fpCreateAndroidSurfaceKHR && "Could not get function pointer to CreateAndroidSurfaceKHR");
        return EGL_FALSE;
    }

    mWsiCallbacks.fpCreateSurface = reinterpret_cast<void *>(fpCreateAndroidSurfaceKHR);

    return EGL_TRUE;
}

VkSurfaceKHR
WSIAndroid::CreateSurface(EGLDisplay dpy, EGLNativeWindowType win, EGLSurface_t *surface)
{
    FUN_ENTRY(DEBUG_DEPTH);

    if(!surface) {
        return VK_NULL_HANDLE;
    }

    PFN_vkCreateAndroidSurfaceKHR fpCreateAndroidSurfaceKHR = reinterpret_cast<PFN_vkCreateAndroidSurfaceKHR>(mWsiCallbacks.fpCreateSurface);

    /// Create a vk surface
    VkSurfaceKHR vkSurface;
    VkAndroidSurfaceCreateInfoKHR surfaceCreateInfo;
    memset((void *)&surfaceCreateInfo, 0 ,sizeof(surfaceCreateInfo));
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    surfaceCreateInfo.pNext = nullptr;
    surfaceCreateInfo.flags = 0;
    surfaceCreateInfo.window = win;
    
    if(VK_SUCCESS != fpCreateAndroidSurfaceKHR(mVkInstance, &surfaceCreateInfo, NULL, &vkSurface)) {
        return VK_NULL_HANDLE;
    }

    return vkSurface;
}
