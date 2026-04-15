//
// Created by Lukáš Blažek on 15.04.2026.
//

#include "spectra_app.h"

#include <iostream>
#include <string>

#include "imgui.h"
#include "SDL3/SDL.h"

namespace SpectraCore
{
	void SpectraApp::init(int argc, char** argv)
	{
		if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		{
			throw std::runtime_error(std::string("SDL_Init failed: ") + SDL_GetError());
		}

		create_window();
		gpu_context_ = std::make_unique<GPUContext>(window_);
		renderer_ = std::make_unique<Renderer>(gpu_context_.get());

		SDL_GPUCommandBuffer *cmd = gpu_context_->begin_cmd();
		renderer_->init(cmd);
		gpu_context_->end_cmd(cmd);
	}

	void SpectraApp::tick()
	{
		prev_ns_ = now_ns_;
		calculate_dt();
	}

	bool SpectraApp::handle_event(const SDL_Event& event)
	{
		// request to quit
		if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) return false;

		// skip if ImGui wants to process this event
		// UI::instance().process_event(event);
		// if (ImGui::::GetIO().WantCaptureMouse) return true;

		// handle events
		if (event.type == SDL_EVENT_MOUSE_MOTION)
		{
		}

		return true;
	}

	void SpectraApp::shutdown()
	{
		SDL_DestroyWindow(window_);
		SDL_Quit();
	}

	void SpectraApp::calculate_dt()
	{
		now_ns_ = SDL_GetTicksNS();
		dt_ = static_cast<float>(now_ns_ - prev_ns_) * 1e-9f;
		if (dt_ > 0.1f) dt_ = 0.1f;
	}

	void SpectraApp::create_window()
	{
#ifdef __APPLE__
		window_ = SDL_CreateWindow(CONSTANTS::WINDOW_TITLE.data(), CONSTANTS::WINDOW_START_WIDTH,
								   CONSTANTS::WINDOW_START_HEIGHT,
								   SDL_WINDOW_RESIZABLE | SDL_WINDOW_METAL);
#else
		window_ = SDL_CreateWindow(CONSTANTS::WINDOW_TITLE.data(), CONSTANTS::WINDOW_START_WIDTH,
								   CONSTANTS::WINDOW_START_HEIGHT, SDL_WINDOW_RESIZABLE);
#endif

		if (!window_)
		{
			throw std::runtime_error(std::string("SDL_CreateWindow failed: ") + SDL_GetError());
		}
	}
} // SpectraCore