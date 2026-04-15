//
// Created by Lukáš Blažek on 15.04.2026.
//

#include "renderer.h"

Renderer::~Renderer()
{
}

void Renderer::init(SDL_GPUCommandBuffer*)
{
}

void Renderer::update(SDL_GPUCommandBuffer* cmd)
{
}

void Renderer::render(SDL_GPUCommandBuffer* cmd_buf)
{
}

SDL_GPUShader* Renderer::load_shader(const char* path, SDL_ShaderCross_ShaderStage stage,
	uint32_t num_UBOs)
{
}

void Renderer::create_pipeline()
{
}
