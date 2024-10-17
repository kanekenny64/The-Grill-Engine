#ifndef THEGRILL_COMPONENT_H
#define	THEGRILL_COMPONENT_H



namespace thegrill {
	struct Component
	{
		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();

		void tick();
	};
}


#endif // !THEGRILL_COMPONENT_H