#include "Engine/Engine.h"

#include "PongLayer.h"

int main() {
	Engine::Log::Init();
	Engine::App* app = new Engine::App();
	app->PushLayer(new Pong::PongLayer());
	app->Run();
	delete app;
}