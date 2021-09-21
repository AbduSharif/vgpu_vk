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
 *  @file       WSIAndroid.h
 *  @author     Think Silicon, luo9674
 *  @date       20/9/2021
 *  @version    1.0
 *
 *  @brief      WSI Android module. It gets Android VkSurface.
 *
 */

#ifndef __WSI_ANDROID_H__
#define __WSI_ANDROID_H__

#include "vulkanWSI.h"

class WSIAndroid : public VulkanWSI
{
protected:
    EGLBoolean         SetSurfaceCallback() override;

public:
    WSIAndroid() {}
    ~WSIAndroid() {}

    VkSurfaceKHR       CreateSurface(EGLDisplay dpy,
                                     EGLNativeWindowType win,
                                     EGLSurface_t *surface) override;


};

#endif // __WSI_ANDROID_H__
