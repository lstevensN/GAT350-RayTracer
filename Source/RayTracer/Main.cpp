#include <iostream>
#include "Camera.h"
#include "Canvas.h"
#include "Color.h"
#include "Material.h"
#include "MathUtils.h"
#include "Random.h"
#include "Renderer.h"
#include "Scene.h"
#include "Sphere.h"

using namespace std;

int main(int argc, char* argv[])
{
	std::cout << "Hello World\n";

	seedRandom((unsigned int)time(nullptr));

	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Ray Tracer", 400, 300);

	Canvas canvas(400, 300, renderer);

	float aspectRatio = canvas.GetSize().x / (float)canvas.GetSize().y;
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 0, 1 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 70.0f, aspectRatio);

	Scene scene; // sky color could be set with the top and bottom color
	scene.SetCamera(camera);

	auto material = std::make_shared<Lambertian>(color3_t{ 0, 0, 1 });

	// create objects -> add to scene
	auto sphere = std::make_unique<Sphere>(glm::vec3{ -1, 0, -3 }, 1.0f, material);
	scene.AddObject(std::move(sphere));

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		canvas.Clear({ 0, 0, 0, 1 });
		scene.Render(canvas);
		canvas.Update();

		renderer.PresentCanvas(canvas);
	}

	renderer.Shutdown();

	return 0;
}