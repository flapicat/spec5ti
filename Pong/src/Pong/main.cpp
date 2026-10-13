#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Engine/Log.h"

int main() {
	Engine::Log::Init();
	LOG_TRACE("TEST");
	return 0;
}