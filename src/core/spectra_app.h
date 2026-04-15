//
// Created by Lukáš Blažek on 15.04.2026.
//

#pragma once
#include <memory>
#include <string_view>

#include "graphics/gpu_context.h"
#include "graphics/renderer.h"
#include "SDL3/SDL_events.h"
namespace CONSTANTS
{
	inline constexpr uint32_t WINDOW_START_WIDTH = 800;
	inline constexpr uint32_t WINDOW_START_HEIGHT = 800;
	inline constexpr std::string_view WINDOW_TITLE = "Spectra";
}

namespace SpectraCore
{
	class SpectraApp
	{
	public:
		SpectraApp() = default;
		~SpectraApp(){ shutdown(); }

		// non-copyable, non-movable (holds raw SDL handles)
		SpectraApp(const SpectraApp&)            = delete;
		SpectraApp& operator=(const SpectraApp&) = delete;
		SpectraApp(SpectraApp&&)                 = delete;
		SpectraApp& operator=(SpectraApp&&)      = delete;

		void init(int argc, char** argv);
		void tick();
		bool handle_event(const SDL_Event& event);
		void shutdown();

	private:
		SDL_Window* window_ = nullptr;
		std::unique_ptr<GPUContext> gpu_context_ = nullptr;
		std::unique_ptr<Renderer> renderer_ = nullptr;

		uint64_t prev_ns_ = 0;
		uint64_t now_ns_ = 0;
		float dt_ = 0;

		void calculate_dt();

		void create_window();
	};
} // SpectraCore
