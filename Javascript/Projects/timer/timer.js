class Timer {
    constructor(duration, startButton, pauseButton, callbacks) {
        this.duration = duration;
        this.startButton = startButton;
        this.pauseButton = pauseButton;
        if (callbacks) {
            this.onStart = callbacks.onStart;
            this.onTick = callbacks.onTick;
            this.onComplete = callbacks.onComplete;
        }
        this.startButton.addEventListener('click', this.start);
        this.pauseButton.addEventListener('click', this.pause);
    }

    start = () => {
        if (this.onStart) {
            this.onStart(this.timeLeft);
        }
        this.tick();
        this.timerID = setInterval(this.tick, 50);

    }

    pause = () => {
        clearInterval(this.timerID);
    }

    tick = () => {
        if (this.timeLeft <= 0) {
            this.pause();
            if (this.onComplete) {
                this.onComplete();
            }
        } else {
            this.timeLeft = this.timeLeft - .05;
            if (this.onTick) {
                this.onTick(this.timeLeft);
            }
        }
    }
    get timeLeft() {
        return parseFloat(this.duration.value);
    }
    set timeLeft(time) {
        this.duration.value = time.toFixed(2);
    }
}
