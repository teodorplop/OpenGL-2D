#include "Renderer.h"

std::unordered_set<IRenderable*> Renderer::s_Renderables;

void Renderer::Register(IRenderable* renderable) {
	s_Renderables.insert(renderable);
}

void Renderer::Unregister(IRenderable* renderable) {
	s_Renderables.erase(renderable);
}

void Renderer::Setup() {
	// Depth test, so we can set which sprite is in front of another using the z values
	glEnable(GL_DEPTH_TEST);

	// Blend, so we can display transparent textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Renderer::Render(Camera* camera) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(camera->GetClearColor().r, camera->GetClearColor().g, camera->GetClearColor().b, 0);

	for (IRenderable* renderable : s_Renderables) {
		if (!renderable->IsActive())
			continue;

		Material* material = renderable->GetMaterial();
		VertexArray* vArray = renderable->GetMesh()->GetVertexArray();
		IndexBuffer* iBuffer = renderable->GetMesh()->GetIndexBuffer();

		vArray->Bind();
		iBuffer->Bind();
		material->Bind();

		material->GetShader()->SetUniformMatrix4fv("_ProjMatrix", camera->GetProjectionMatrix());
		material->GetShader()->SetUniformMatrix4fv("_ViewMatrix", camera->GetViewMatrix());
		material->GetShader()->SetUniformMatrix4fv("_ModelMatrix", renderable->GetTransform()->GetMatrix());

		glDrawElements(GL_TRIANGLES, iBuffer->GetCount(), GL_UNSIGNED_INT, 0);

		material->Unbind();
		iBuffer->Unbind();
		vArray->Unbind();
	}
}