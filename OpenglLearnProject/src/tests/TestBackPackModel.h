#pragma once

#include "Test.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Model.h"

#include <memory>

namespace test {
	class TestBackPackModel : public Test
	{
	public:
		TestBackPackModel();
		~TestBackPackModel();

		virtual void OnUpdate(float deltatime) override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
	private:
		bool m_SetPolygoneMode;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<Model> m_Model;

		glm::mat4 m_Proj;
		glm::vec3 m_RightV, m_UpV, m_DirectionalV;
	};
}
