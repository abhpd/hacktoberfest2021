let gameCanvas, screen;
const FPS = 100;
let tilesCount = 20;
let playerPosX = 10, playerPosY = 10;
let applePosX = 15, applePosY = 15;
let xVelocity = 0, yVelocity = 0;
let count = 0, i = 0, a, b, c, d = 0;
var list = [playerPosX, playerPosY];


window.onload = function () {
    gameCanvas = document.getElementById('gameCanvas');
    screen = gameCanvas.getContext('2d');

    this.document.addEventListener('keydown', onKeyup);


    setInterval(() => {
        gameLoop();
    }, FPS);
}

function gameLoop() {
    a = list[0];
    b = list[1];
    list[0] += xVelocity;
    list[1] += yVelocity;


    for (i = 2; i < list.length; i = i + 2) {
        if (list[0] == list[i] && list[1] == list[i + 1]) {

            window.alert(`GAME OVER : \n Score =${(list.length / 2) - 1}`);

            list = null;
            list = [10, 10];
            return 0;
        }
    };
    for (i = 2; i < list.length - 1; i = i + 2) {

        c = list[i];
        d = list[i + 1];
        list[i] = a;
        list[i + 1] = b;
        a = c;
        b = d;
    };

    if ((list[0] * tilesCount) > gameCanvas.width - 1)
        list[0] = 0;
    else if ((list[0] * tilesCount) < 0)
        list[0] = tilesCount - 1;
    else if ((list[1] * tilesCount) > gameCanvas.height - 1)
        list[1] = 0;
    else if ((list[1] * tilesCount) < 0)
        list[1] = tilesCount - 1;

    if (list[0] == applePosX && list[1] == applePosY) {

        list.push(list[list.length - 2]);
        list.push(list[list.length - 1]);

        //applePosX=0,applePosY=10;
        applePosX = Math.floor(Math.random() * tilesCount);
        applePosY = Math.floor(Math.random() * tilesCount);
    }

    screen.fillStyle = '#000';
    screen.fillRect(0, 0, gameCanvas.width, gameCanvas.height);

    screen.fillStyle = 'yellow';

    for (i = 0; i < list.length; i = i + 2) {
        screen.fillRect(list[i] * tilesCount, list[i + 1] * tilesCount, tilesCount - 2, tilesCount - 2);
    };




    screen.fillStyle = 'red';
    screen.fillRect(applePosX * tilesCount, applePosY * tilesCount, tilesCount - 2, tilesCount - 2);
}

function onKeyup(event) {
    switch (event.keyCode) {
        case 37:        //left
            xVelocity = -1;
            yVelocity = 0;
            break;
        case 38:        //up
            xVelocity = 0;
            yVelocity = -1;
            break;
        case 39:        //right
            xVelocity = 1;
            yVelocity = 0;
            break;
        case 40:        //down
            xVelocity = 0;
            yVelocity = 1;
            break;
    }
}