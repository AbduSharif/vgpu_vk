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
 *  @file       contextUtilities.cpp
 *  @author     Think Silicon
 *  @date       25/07/2018
 *  @version    1.0
 *
 *  @brief      OpenGL ES API calls related to GL Utilities
 *
 */

#include "context.h"
 GLenum
Context::GetError(void)
{
    FUN_ENTRY(GL_LOG_DEBUG);

    GLenum result = mStateManager.GetError();

    mStateManager.SetError(GL_NO_ERROR);

    return result;
}

const GLubyte*
Context::GetString(GLenum name)
{
    FUN_ENTRY(GL_LOG_DEBUG);
	
	/*
    const char *strings[] {"GLOVE",
						  "GLOVE (GL Over Vulkan)",
                          "OpenGL 2.0 Over Vulkan",
                          "GLSL 120",
                          "GL_OES_get_program_binary"};
    switch(name) {
    case GL_VENDOR:                     return (const GLubyte *)strings[0];
    case GL_RENDERER:                   return (const GLubyte *)strings[1];
    case GL_VERSION:                    return (const GLubyte *)strings[2];
    case GL_SHADING_LANGUAGE_VERSION:   return (const GLubyte *)strings[3];
    case GL_EXTENSIONS:                 return (const GLubyte *)strings[4];
    default:                            RecordError(GL_INVALID_ENUM); return nullptr; 
    }
    */
    if(name == GL_RENDERER){
        return (const GLubyte *)"GLOVE (GL Over Vulkan)";
    }
    if(name == GL_VERSION){
    	return (const GLubyte *)"3.0";
    }
    if(name == GL_VENDOR){
    	return (const GLubyte *)"GLOVE";
    }
    if(name == GL_SHADING_LANGUAGE_VERSION){
    	return (const GLubyte *)"1.30";
    }
    if(name == GL_EXTENSIONS){
    	return (const GLubyte *)"GL_OES_get_program_binary GL_OES_EGL_image GL_OES_EGL_image_external GL_OES_EGL_sync GL_OES_vertex_half_float GL_OES_framebuffer_object GL_OES_rgb8_rgba8 GL_OES_compressed_ETC1_RGB8_texture GL_AMD_compressed_ATC_texture GL_KHR_texture_compression_astc_ldr GL_KHR_texture_compression_astc_hdr GL_OES_texture_compression_astc GL_OES_texture_npot GL_EXT_texture_filter_anisotropic GL_EXT_texture_format_BGRA8888 GL_OES_texture_3D GL_EXT_color_buffer_float GL_EXT_color_buffer_half_float GL_QCOM_alpha_test GL_OES_depth24 GL_OES_packed_depth_stencil GL_OES_depth_texture GL_OES_depth_texture_cube_map GL_EXT_sRGB GL_OES_texture_float GL_OES_texture_float_linear GL_OES_texture_half_float GL_OES_texture_half_float_linear GL_EXT_texture_type_2_10_10_10_REV GL_EXT_texture_sRGB_decode GL_EXT_texture_format_sRGB_override GL_OES_element_index_uint GL_EXT_copy_image GL_EXT_geometry_shader GL_EXT_tessellation_shader GL_OES_texture_stencil8 GL_EXT_shader_io_blocks GL_OES_shader_image_atomic GL_OES_sample_variables GL_EXT_texture_border_clamp GL_EXT_EGL_image_external_wrap_modes GL_EXT_multisampled_render_to_texture GL_EXT_multisampled_render_to_texture2 GL_OES_shader_multisample_interpolation GL_EXT_texture_cube_map_array GL_EXT_draw_buffers_indexed GL_EXT_gpu_shader5 GL_EXT_robustness GL_EXT_texture_buffer GL_EXT_shader_framebuffer_fetch GL_ARM_shader_framebuffer_fetch_depth_stencil GL_OES_texture_storage_multisample_2d_array GL_OES_sample_shading GL_OES_get_program_binary GL_EXT_debug_label GL_KHR_blend_equation_advanced GL_KHR_blend_equation_advanced_coherent GL_QCOM_tiled_rendering GL_ANDROID_extension_pack_es31a GL_EXT_primitive_bounding_box GL_OES_standard_derivatives GL_OES_vertex_array_object GL_EXT_disjoint_timer_query GL_KHR_debug GL_EXT_YUV_target GL_EXT_sRGB_write_control GL_EXT_texture_norm16 GL_EXT_discard_framebuffer GL_OES_surfaceless_context GL_OVR_multiview GL_OVR_multiview2 GL_EXT_texture_sRGB_R8 GL_KHR_no_error GL_EXT_debug_marker GL_OES_EGL_image_external_essl3 GL_OVR_multiview_multisampled_render_to_texture GL_EXT_buffer_storage GL_EXT_external_buffer GL_EXT_blit_framebuffer_params GL_EXT_clip_cull_distance GL_EXT_protected_textures GL_EXT_shader_non_constant_global_initializers GL_QCOM_texture_foveated GL_QCOM_shader_framebuffer_fetch_noncoherent GL_EXT_memory_object GL_EXT_memory_object_fd GL_EXT_EGL_image_array GL_NV_shader_noperspective_interpolation GL_KHR_robust_buffer_access_behavior GL_EXT_EGL_image_storage GL_EXT_blend_func_extended";
    }
    RecordError(GL_INVALID_ENUM);
    return (const GLubyte *)"";
}
