//
// Created by Lukáš Blažek on 15.04.2026.
//

#include "renderer.h"

#include "ui.h"

Renderer::~Renderer()
{
	SDL_WaitForGPUIdle(gpu_context_->get_device());
	SDL_ReleaseGPUBuffer(gpu_context_->get_device(), vertex_buffer_);
	SDL_ReleaseGPUGraphicsPipeline(gpu_context_->get_device(), graphics_pipeline_);
	SDL_ReleaseGPUShader(gpu_context_->get_device(), vertex_shader_);
	SDL_ReleaseGPUShader(gpu_context_->get_device(), fragment_shader_);

	UI::instance().shutdown();
}

void Renderer::init(SDL_GPUCommandBuffer* cmd)
{
	UI::instance().init(gpu_context_->get_window(), gpu_context_->get_device());

	// TODO: load vertices

	// TODO: load shaders

	create_pipeline();
	// create other pipelines?

	// TODO: VB, IB from loaded vertices and upload to gpu
}

void Renderer::update(SDL_GPUCommandBuffer* cmd)
{
	// get UBO changes
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
