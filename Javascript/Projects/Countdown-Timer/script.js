const countdown = ()=>{
    const countDate = new Date('Oct 30, 2021 00:00:00').getTime() 
    const now = new Date().getTime();
    const dif = countDate - now;

    const second = 1000;
    const minute = second*60;
    const hour = minute * 60;
    const day = hour * 24;

    const textDay = Math.floor(dif / day); 
    const textHour = Math.floor((dif % day) / hour);
    const textMinute = Math.floor((dif % hour) / minute);
    const textSecond = Math.floor((dif % minute) / second);

    document.querySelector('.day').innerText = textDay
    document.querySelector('.hour').innerText = textHour
    document.querySelector('.minute').innerText = textMinute
    document.querySelector('.second').innerText = textSecond
    
}   

setInterval(countdown, 1000)
