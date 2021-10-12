function keyPress(e) {
    // console.log(e.keyCode);
    const audio = document.querySelector(`audio[data-key="${e.keyCode}"]`);
    const div = document.querySelector(`div[data-key="${e.keyCode}"]`);
    // console.log(div);
    if (!audio) {
        return;//stop function form all start
    }
    audio.currentTime = 0;//revind it on click
    audio.play();
    div.classList.add('playing');

}
function keyStroke(e) {
    if (e.propertyName !== "transform") {
        return;
    }
    this.classList.remove('playing');
}
window.addEventListener('keydown', keyPress);
let strok = document.querySelectorAll(".strok");
strok.forEach(key => key.addEventListener('transitionend', keyStroke))
