#include "AnimationController.h"
#include "vector"
#include "Entity.h"
#include "Model.h"
#include "Core.h"
#include "ModelRenderer.h"




namespace thegrill {
	AnimationController::AnimationController()
	{
		m_duration = 0;
		looping = true;
		m_currentTime = 0;
		
	}

	void AnimationController::on_initialize()
	{
		
		m_renderer = get_entity()->get_component<ModelRenderer>();
		m_lastTime = get_core()->DeltaTime();
	}

	void AnimationController::on_tick()
	{
		m_currentTime += get_core()->DeltaTime();

		if (m_currentTime - m_lastTime >= timePerFrame)
		{
			m_currentFrame++;
			std::cout << "Current Frame: " << m_currentFrame << std::endl;
			m_lastTime = m_currentTime;

			if (looping) {
				if (m_currentFrame >= m_track->m_keyFrames.size())
				{
					
					m_currentFrame = 0;
				}
			}
			else {
				if (m_currentFrame >= m_track->m_keyFrames.size())
				{
					m_currentFrame = m_track->m_keyFrames.size() - 1;
				}
			}

		}

		
		m_renderer->set_model(m_track->m_keyFrames[m_currentFrame]->get_model());
	}
	void AnimationController::set_track(std::shared_ptr<AnimationTrack> _track)
	{
		m_track = _track;
		timePerFrame = m_duration / m_track->m_keyFrames.size();
	}
}