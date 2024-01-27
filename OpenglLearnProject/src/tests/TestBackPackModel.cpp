#include "TestBackPackModel.h"

#include "imgui/imgui.h"

#include <fstream>

namespace test
{
	TestBackPackModel::TestBackPackModel()
		: m_Proj(glm::perspective(glm::radians(45.0f), 960.0f / 540.0f, 0.1f, 100.0f)),
		m_RightV(glm::vec3(5.0f, 0.0f, 10.0f)),
		m_UpV(glm::vec3(0.0f, 0.0f, 3.0f)),
		m_DirectionalV(glm::vec3(0.0f, 1.0f, 0.0f)),
		m_SetPolygoneMode(false)
	{
		m_Shader = std::make_unique<Shader>("res/shaders/BackPackShader.shader");
		m_Shader->Bind();

		m_Model = std::make_unique<Model>("res/files3d/backpack/source/backpack.fbx");


	}

	TestBackPackModel::~TestBackPackModel()
	{
	}

	void TestBackPackModel::OnUpdate(float deltatime)
	{
	}

	void TestBackPackModel::OnRender()
	{
		GLCall(glClearColor(0.5f, 0.3f, 0.2f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		Renderer renderer;

		m_Shader->Bind();
		{
			glm::mat4 proj = glm::perspective(glm::radians(45.0f), 960.0f / 540.0f, 0.1f, 100.0f);
			glm::mat4 view = glm::lookAt(m_RightV, m_UpV, m_DirectionalV);
			m_Shader->Bind();
			m_Shader->SetUniformMat4f("projection", m_Proj);
			m_Shader->Bind();
			m_Shader->SetUniformMat4f("view", view);

			// render the loaded model
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
			model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
			m_Shader->Bind();
			m_Shader->SetUniformMat4f("model", model);
			m_Model->Draw(*m_Shader);
		}

	}

	void TestBackPackModel::OnImGuiRender()
	{
		ImGui::Checkbox("PolyGone Mode", &m_SetPolygoneMode);
		if (m_SetPolygoneMode)
		{
			// shows render in polygon mode
			GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
		}
		ImGui::SliderFloat3("Right Vector", &m_RightV.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Up Vector", &m_UpV.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Direction Vector", &m_DirectionalV.x, 0.0f, 960.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}
