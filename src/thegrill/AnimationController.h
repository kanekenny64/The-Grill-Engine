#include "Component.h"
#include "AnimationTrack.h"


namespace thegrill {
	struct ModelRenderer;
	//struct AnimationTrack;
	struct AnimationController : Component
	{
	public:
		AnimationController();

		void on_initialize() override;
		void on_tick();

		void set_looping(bool _looping) { looping = _looping; }
		void set_track(std::shared_ptr<AnimationTrack> _track);
		void set_duration(float _duration) { m_duration = _duration; }

	private:
		bool looping;
		float m_currentTime = 0;
		float m_lastTime = 0;
		int m_currentFrame = 0;
		float m_duration;
		float timePerFrame;
		std::shared_ptr<AnimationTrack> m_track;
		std::shared_ptr<ModelRenderer> m_renderer;
	};
}