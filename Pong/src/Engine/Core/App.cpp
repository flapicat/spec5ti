#include "App.h"

#include <glad/glad.h>

namespace Engine {
	App* App::s_Instance = nullptr;

	App::App() {
		s_Instance = this;
		constexpr uint32_t width = 1600;
		constexpr uint32_t height = 900;
		std::string title = "Pong";
		m_Window = std::make_unique<Window>(width,height,title);
		m_Window->SetEventCallback([this](Event& e) {OnEvent(e); });
	}

	App::~App(){
	
	}

	void App::Run(){
		while (m_Running)
		{
			float time = glfwGetTime();
			TimeStep timeStep = time - m_LastFrame;
			m_LastFrame = time;

			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (auto& layer : m_LayerStack) {
				layer->OnUpdate(timeStep);
			}

			for (auto& layer : m_LayerStack) {
				layer->OnRender();
			}

			m_Window->Update();
		}
	}

	void App::OnEvent(Event& event)
	{
		EventHandler hander(event);
		hander.Handle<WindowCloseEvent>([this](const WindowCloseEvent& ev) {OnWindowCloseEvent(ev); });

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
			(*it)->OnEvent(event);
	}

	void App::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnInit();
	}

	void App::PopLayer(Layer* layer) {
		layer->OnDestroy();
		m_LayerStack.PopLayer(layer);
	}

	void App::OnWindowCloseEvent(const WindowCloseEvent& e)
	{
		m_Running = false;
	}
}