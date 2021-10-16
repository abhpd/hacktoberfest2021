

$(document).ready(function() {

    var time = 10000,
        timer;
    $('.slideshow li:first-child').addClass('active');

    function play() {
        timer = setInterval(function(){
            var next = $(".slideshow .active").removeClass("active").next(".image");
            if (!next.length) {
                next = $(".slideshow .image:first");
            }
            next.addClass("active");
        }, time);
    }
    play();

    /*Start of function for next button  */
    function forward() {
        $('.forward').click(function() {
            clearInterval(timer);
            play();
            var go = $(".slideshow .active").removeClass("active").next(".image").addClass("active");
            if (!go.length) {
                go = $(".slideshow .image:first");
            }
            go.addClass("active");
        });
    }

    forward();

    /*Start of function for prev button  */
    function previous() {
        $('.backward').click(function() {
            clearInterval(timer);
            play();
            var go = $(".slideshow .active").removeClass("active").prev(".image").addClass("active");
            if (!go.length) {
                go = $(".slideshow .image:last");
            }
            go.addClass("active");
        });
    }

    previous();

});

/*Blendet Weiter und Zurück button aus/ein  */
var timer;
$(document).mousemove(function() {
    if (timer) {
        clearTimeout(timer);
        timer = 0;
    }

    $('.backward, .forward').fadeIn();
    timer = setTimeout(function() {
        $('.backward, .forward').fadeOut()
    }, 3000)
})