const section = document.querySelector("section");
const text = document.querySelector(".outerText");
const innerText = document.querySelector(".innerText");

const scrollEffect = () => {
    let value = window.scrollY;
    if (window.innerWidth < 600) {
        section.style.clipPath = `circle(${value/2}px at center center)`;
        text.style.left = 100 - value/5 + "%";
        innerText.style.left = 100 - value/5 + "%";
    } else {
        section.style.clipPath = `circle(${value}px at center center)`;
        text.style.left = 100 - value/5 + "%";
        innerText.style.left = 100 - value/5 + "%";

    }
     
}

window.addEventListener("scroll", scrollEffect);