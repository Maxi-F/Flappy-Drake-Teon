#pragma once

namespace flappyBird {
    namespace timer {
		struct Timer {
			double startTime;
			double lifeTime;
			double pauseTime;
			bool paused;
		};

		void StartTimer(Timer* timer, double lifeTime);
		bool TimerDone(Timer timer);
		void PauseTimer(Timer* timer);
		void UnPauseTimer(Timer* timer);
		double GetElapsed(Timer timer);
    }
}
