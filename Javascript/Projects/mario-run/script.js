score = 0;
cross = true;
startaudio = new Audio("audio/music.mp3");
jumpaudio = new Audio("audio/Mario-jump-sound.mp3");
gameoveraudio = new Audio("audio/smb_mariodie.wav");
setTimeout(() => {
    startaudio.play();
}, 1000);
document.onkeydown = function(a) {
    //console.log(a.code);
    if (a.code == 'ArrowUp') {
        mario = document.querySelector('.mario');
        mario.classList.add('animateMario');
        jumpaudio.play();
        setTimeout(() => {
            mario.classList.remove('animateMario')
        }, 700);
    }
    if (a.code == 'ArrowRight') {
        mario = document.querySelector('.mario');
        marioX = parseInt(window.getComputedStyle(mario, null).getPropertyValue('left'));
        mario.style.left = marioX + 112 + "px";
    }
    if (a.code == 'ArrowLeft') {
        mario = document.querySelector('.mario');
        marioX = parseInt(window.getComputedStyle(mario, null).getPropertyValue('left'));
        mario.style.left = marioX - 112 + "px";
    }
}
setInterval(() => {
    mario = document.querySelector('.mario');
    obstacle = document.querySelector('.obstacle');
    gameover = document.querySelector('.gameover');
    track = document.querySelector('.track');

    mx = parseInt(window.getComputedStyle(mario, null).getPropertyValue('left'));
    my = parseInt(window.getComputedStyle(mario, null).getPropertyValue('top'));

    ox = parseInt(window.getComputedStyle(obstacle, null).getPropertyValue('left'));
    oy = parseInt(window.getComputedStyle(obstacle, null).getPropertyValue('top'));

    offsetX = Math.abs(mx - ox);
    offsetY = Math.abs(my - oy);

    if (offsetX < 100 && offsetY < 52) {
        obstacle.classList.remove('obstacleAni');
        mario.classList.add('mariofall');
        track.classList.remove('trackmove');
        setTimeout(() => {
            gameover.classList.add('drop');
            gameover.style.visibility = 'visible';
        }, 1500);
        setTimeout(() => {
            startaudio.pause();
        }, 1000);
        gameoveraudio.play();
    } else if (offsetX < 145 && cross) {
        score++;
        scoreCount(score);
        cross = false;
        setTimeout(() => {
            cross = true;
        }, 1000);

        setTimeout(() => {
            aniDur = parseFloat(window.getComputedStyle(obstacle, null).getPropertyValue('animation-duration'));
            newDur = aniDur - 0.1;
            if (newDur < 2.5) {
                newDur = aniDur;
            }
            obstacle.style.animationDuration = newDur + 's';
            trackDur = parseFloat(window.getComputedStyle(track, null).getPropertyValue('animation-duration'));
            newTrackDur = trackDur - 1;
            track.style.animationDuration = newTrackDur + 's';
        }, 1000);
    }
}, 100);

function scoreCount(score) {
    scorecount.innerHTML = "Your Score : " + score;
}