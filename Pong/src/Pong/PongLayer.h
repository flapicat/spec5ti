#pragma once
#include "Engine/Engine.h"

namespace Pong {

	class PongLayer : public Engine::Layer
	{
	public:
		PongLayer();
		~PongLayer();

		void OnInit() override;
		void OnDestroy() override;
		void OnUpdate(Engine::TimeStep ts) override;
		void OnRender() override;
		void OnEvent(Engine::Event& e) override;
	private:
	};

}