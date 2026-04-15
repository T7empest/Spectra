//
// Created by Lukáš Blažek on 15.04.2026.
//

#pragma once
#include "gpu_context.h"
#include "SDL3_shadercross/SDL_shadercross.h"


class Renderer
{
public:
	explicit Renderer(GPUContext* gpu_context)
		: gpu_context_(gpu_context)
	{
	}
	~Renderer();

	void init(SDL_GPUCommandBuffer*);
	void update(SDL_GPUCommandBuffer* cmd);
	void render(SDL_GPUCommandBuffer* cmd_buf);
	SDL_GPUShader* load_shader(const char* path, SDL_ShaderCross_ShaderStage stage,
							   uint32_t num_UBOs);
	void create_pipeline();

private:
	GPUContext* gpu_context_ = nullptr;
	SDL_GPUBuffer*           vertex_buffer_     = nullptr;
	uint32_t                 vertex_count_      = 0;
	SDL_GPUShader*           vertex_shader_     = nullptr;
	SDL_GPUShader*           fragment_shader_   = nullptr;
	SDL_GPUGraphicsPipeline* graphics_pipeline_ = nullptr;
};
