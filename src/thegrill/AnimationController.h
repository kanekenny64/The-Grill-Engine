#include "Component.h"
#include "AnimationTrack.h"


namespace thegrill {
	struct ModelRenderer;

	/**
	 * @brief The AnimationController class is responsible for managing and controlling the playback of animation tracks.
	 */

	struct AnimationController : Component
	{
	public:
		AnimationController();

		void on_initialize() override;
		void on_tick();

		/**
		 * @brief Sets whether the animation should loop.
		 * @param _looping A boolean indicating if the animation should loop.
		 */
		void set_looping(bool _looping) { looping = _looping; }

		/**
		* @brief Sets the animation track to be used by the AnimationController.
		* @param _track A shared pointer to the AnimationTrack to be set.
		*/
		void set_track(std::shared_ptr<AnimationTrack> _track);
		void set_duration(float _duration) { m_duration = _duration; }

	private:
		bool looping; ///< Indicates if the animation should loop.
		float m_currentTime = 0; ///< The current time of the animation.
		float m_lastTime = 0; ///< The recorded time of when the last frame was played.
		int m_currentFrame = 0; ///< The current frame of the animation.
		float m_duration; ///< The total duration of the animation.
		float timePerFrame; ///< The time allocated for each frame of the animation.
		std::shared_ptr<AnimationTrack> m_track; ///< The animation track being played.
		std::shared_ptr<ModelRenderer> m_renderer; ///< The model renderer associated with the animation.
	};
}