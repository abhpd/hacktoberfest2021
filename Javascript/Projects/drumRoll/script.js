window.addEventListener('keydown', function(a){
    console.log(a.keyCode);
    const audio = document.querySelector(`audio[data-key="${a.keyCode}"]`);
    console.log(audio);
    
    const key = document.querySelector(`.key[data-key="${a.keyCode}"]`);

    if(!audio) return; //Stop the function from running all together
    audio.currentTime= 0; //return to start making time 0
    audio.play();

    key.classList.add('playing');
})