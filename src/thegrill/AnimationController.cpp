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

	/**
	 * @brief Initializes the AnimationController. This function retrieves the ModelRenderer component from the associated entity.
	 */
	void AnimationController::on_initialize()
	{

		m_renderer = get_entity()->get_component<ModelRenderer>();
		m_lastTime = get_core()->DeltaTime();
	}

	/**
	 * @brief Updates the AnimationController each tick. This function advances the animation based on the elapsed time.
	 */
	void AnimationController::on_tick()
	{
		m_currentTime += get_core()->DeltaTime(); ///< Update the current time with the delta time.

		if (m_currentTime - m_lastTime >= timePerFrame)
		{
			m_currentFrame++; ///< Move to the next frame.

			m_lastTime = m_currentTime; ///< Update last time to current time.

			if (looping) {
				if (m_currentFrame >= m_track->m_keyFrames.size())
				{

					m_currentFrame = 0; ///< Loop back to the first frame.
				}
			}
			else {
				if (m_currentFrame >= m_track->m_keyFrames.size())
				{
					m_currentFrame = m_track->m_keyFrames.size() - 1; ///< Stay at the last frame.
				}
			}

		}


		m_renderer->set_model(m_track->m_keyFrames[m_currentFrame]); ///< Set the model to the current frame's model.
	}
	void AnimationController::set_track(std::shared_ptr<AnimationTrack> _track)
	{
		m_track = _track;
		timePerFrame = m_duration / m_track->m_keyFrames.size();
	}
}