#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "../Event/Events.h"

namespace Engine {
	class Window
	{
	public:
		Window(uint32_t width, uint32_t height, const std::string& title);
		~Window();

		void InitWindow(uint32_t width, uint32_t height, const std::string& title);

		void Update();

		GLFWwindow* GetNativeWindow() const { return m_Window; }
		
		inline uint32_t GetWidth() const { return m_Width; }
		inline uint32_t GetHeight() const { return m_Height; }


		void SetWindowPosition(uint32_t x, uint32_t y);
		void SetWindowPosition(const glm::vec2& pos);
		glm::vec2 GetWindowPosition() const;
		glm::vec2 GetMonitorSize() const;
		void SetEventCallback(const std::function<void(Event&)>& callback) { m_EvCallback = callback; }
	private:
		GLFWwindow* m_Window = nullptr;
		uint32_t m_Width = 0;
		uint32_t m_Height = 0;
		std::function<void(Event&)> m_EvCallback;
	};
}
