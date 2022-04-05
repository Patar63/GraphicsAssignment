#include "BloomEffect.h"
#include "Utils/ResourceManager/ResourceManager.h"
#include "Utils/JsonGlmHelpers.h"
#include "Utils/ImGuiHelper.h"

#include <GLM/glm.hpp>

BloomEffect::BloomEffect() :
	PostProcessingLayer::Effect(),
	_shader(nullptr)
{
	Name = "Bloom Effect";
	_format = RenderTargetType::ColorRgb8;

	_shader = ResourceManager::CreateAsset<ShaderProgram>(std::unordered_map<ShaderPartType, std::string>{
		{ ShaderPartType::Vertex, "shaders/vertex_shaders/fullscreen_quad.glsl" },
		{ ShaderPartType::Fragment, "shaders/fragment_shaders/post_effects/outline.glsl" }
	});
}

BloomEffect::~BloomEffect() = default;

void BloomEffect::Apply(const Framebuffer::Sptr& gBuffer)
{
}

void BloomEffect::RenderImGui()
{
}

BloomEffect::Sptr BloomEffect::FromJson(const nlohmann::json& data)
{
	return BloomEffect::Sptr();
}

nlohmann::json BloomEffect::ToJson() const
{
	return nlohmann::json();
}
