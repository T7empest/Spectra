#include <iostream>

#include "core/spectra_app.h"
#include "SDL3/SDL_log.h"

int main(int argc, char* argv[])
{
	try
	{
		SpectraCore::SpectraApp app;
		app.init(argc, argv);

		SDL_Event event;

		bool running = true;
		while (running)
		{
			while (SDL_PollEvent(&event))
			{
				running = app.handle_event(event);
				if (!running)
					break;
			}

			if (running)
				app.tick();
		}
		return 0;
	}
	catch (const std::exception& ex)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Fatal error: %s", ex.what());
		std::cerr << "Fatal error: " << ex.what() << "\n";
		return 1;
	}
	catch (...)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Fatal error: unknown exception");
		std::cerr << "Fatal error: unknown exception\n";
		return 1;
	}
}
